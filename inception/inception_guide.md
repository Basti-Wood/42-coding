# 42 Inception Project - Complete Guide

*This guide assumes your 42 login is `basti`. Replace all instances with your actual login.*

---

## 1. Prerequisites & VM Setup

### Install required packages on your VM (Debian/Ubuntu):
```bash
sudo apt update && sudo apt upgrade -y
sudo apt install -y docker.io docker-compose make openssl
sudo usermod -aG docker $USER
newgrp docker
```

### Configure your domain in /etc/hosts:
```bash
sudo bash -c 'echo "127.0.0.1 basti.42.fr" >> /etc/hosts'
```

### Create data directories:
```bash
sudo mkdir -p /home/basti/data/wordpress
sudo mkdir -p /home/basti/data/mariadb
sudo chown -R $USER:$USER /home/basti/data
```

---

## 2. Project Structure

Create this exact structure:
```
inception/
├── Makefile
├── secrets/
│   ├── credentials.txt
│   ├── db_password.txt
│   └── db_root_password.txt
└── srcs/
    ├── .env
    ├── docker-compose.yml
    └── requirements/
        ├── mariadb/
        │   ├── Dockerfile
        │   ├── conf/
        │   │   └── 50-server.cnf
        │   └── tools/
        │       └── init_db.sh
        ├── nginx/
        │   ├── Dockerfile
        │   ├── conf/
        │   │   └── nginx.conf
        │   └── tools/
        └── wordpress/
            ├── Dockerfile
            ├── conf/
            │   └── www.conf
            └── tools/
                └── setup_wp.sh
```

### Create structure with commands:
```bash
mkdir -p inception/secrets
mkdir -p inception/srcs/requirements/{mariadb,nginx,wordpress}/{conf,tools}
touch inception/Makefile
touch inception/srcs/.env
touch inception/srcs/docker-compose.yml
```

---

## 3. Secrets Setup

### Create secrets files (NOT committed to git):
```bash
cd inception

# Database password
echo "YourSecureDbPass123!" > secrets/db_password.txt

# Database root password
echo "YourSecureRootPass456!" > secrets/db_root_password.txt

# WordPress credentials (user:password format)
echo "wpuser:WpSecurePass789!" > secrets/credentials.txt
```

### Add to .gitignore:
```bash
echo "secrets/" >> .gitignore
echo "srcs/.env" >> .gitignore
```

---

## 4. Environment File (srcs/.env)

```env
# Domain
DOMAIN_NAME=basti.42.fr

# MariaDB
MYSQL_DATABASE=wordpress
MYSQL_USER=wpdbuser

# WordPress
WP_TITLE=Inception
WP_ADMIN_USER=boss
WP_ADMIN_EMAIL=boss@basti.42.fr
WP_USER=editor
WP_USER_EMAIL=editor@basti.42.fr

# Paths
DATA_PATH=/home/basti/data
```

**Important:** `WP_ADMIN_USER` cannot contain "admin" or "administrator"!

---

## 5. MariaDB Container

### srcs/requirements/mariadb/Dockerfile
```dockerfile
FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    mariadb-server \
    mariadb-client \
    && rm -rf /var/lib/apt/lists/*

# Copy configuration
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Copy init script
COPY tools/init_db.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/init_db.sh

# Create mysql run directory
RUN mkdir -p /var/run/mysqld && \
    chown -R mysql:mysql /var/run/mysqld && \
    chmod 755 /var/run/mysqld

EXPOSE 3306

ENTRYPOINT ["init_db.sh"]
```

### srcs/requirements/mariadb/conf/50-server.cnf
```ini
[mysqld]
user                    = mysql
pid-file                = /run/mysqld/mysqld.pid
socket                  = /run/mysqld/mysqld.sock
port                    = 3306
basedir                 = /usr
datadir                 = /var/lib/mysql
tmpdir                  = /tmp
bind-address            = 0.0.0.0
skip-external-locking

# Character set
character-set-server    = utf8mb4
collation-server        = utf8mb4_general_ci
```

### srcs/requirements/mariadb/tools/init_db.sh
```bash
#!/bin/bash

# Read secrets
DB_ROOT_PASS=$(cat /run/secrets/db_root_password)
DB_PASS=$(cat /run/secrets/db_password)

# Check if database already initialized
if [ ! -d "/var/lib/mysql/$MYSQL_DATABASE" ]; then
    echo "Initializing database..."
    
    # Start MariaDB temporarily
    mysqld_safe &
    sleep 5
    
    # Create database and user
    mysql -u root <<EOF
CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$DB_PASS';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASS';
FLUSH PRIVILEGES;
EOF
    
    # Stop temporary instance
    mysqladmin -u root -p"$DB_ROOT_PASS" shutdown
    sleep 2
    
    echo "Database initialized successfully."
fi

echo "Starting MariaDB..."
exec mysqld_safe
```

---

## 6. NGINX Container

### srcs/requirements/nginx/Dockerfile
```dockerfile
FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/*

# Create SSL directory
RUN mkdir -p /etc/nginx/ssl

# Generate self-signed SSL certificate
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/nginx.key \
    -out /etc/nginx/ssl/nginx.crt \
    -subj "/C=DE/ST=Berlin/L=Berlin/O=42/OU=42/CN=basti.42.fr"

# Copy nginx configuration
COPY conf/nginx.conf /etc/nginx/conf.d/default.conf

# Remove default config
RUN rm -f /etc/nginx/sites-enabled/default

EXPOSE 443

# Run nginx in foreground (PID 1 best practice)
CMD ["nginx", "-g", "daemon off;"]
```

### srcs/requirements/nginx/conf/nginx.conf
```nginx
server {
    listen 443 ssl;
    listen [::]:443 ssl;
    
    server_name basti.42.fr;
    
    # SSL Configuration
    ssl_certificate     /etc/nginx/ssl/nginx.crt;
    ssl_certificate_key /etc/nginx/ssl/nginx.key;
    ssl_protocols       TLSv1.2 TLSv1.3;
    
    # Root directory
    root /var/www/html;
    index index.php index.html;
    
    # PHP handling - forward to WordPress container
    location ~ \.php$ {
        try_files $uri =404;
        fastcgi_split_path_info ^(.+\.php)(/.+)$;
        fastcgi_pass wordpress:9000;
        fastcgi_index index.php;
        include fastcgi_params;
        fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
        fastcgi_param PATH_INFO $fastcgi_path_info;
    }
    
    location / {
        try_files $uri $uri/ /index.php?$args;
    }
}
```

---

## 7. WordPress Container

### srcs/requirements/wordpress/Dockerfile
```dockerfile
FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    php7.4 \
    php7.4-fpm \
    php7.4-mysql \
    php7.4-curl \
    php7.4-gd \
    php7.4-mbstring \
    php7.4-xml \
    php7.4-zip \
    curl \
    mariadb-client \
    && rm -rf /var/lib/apt/lists/*

# Install WP-CLI
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

# Configure PHP-FPM
COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

# Create necessary directories
RUN mkdir -p /var/www/html && \
    mkdir -p /run/php && \
    chown -R www-data:www-data /var/www/html

# Copy setup script
COPY tools/setup_wp.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/setup_wp.sh

WORKDIR /var/www/html

EXPOSE 9000

ENTRYPOINT ["setup_wp.sh"]
```

### srcs/requirements/wordpress/conf/www.conf
```ini
[www]
user = www-data
group = www-data

listen = 9000

pm = dynamic
pm.max_children = 5
pm.start_servers = 2
pm.min_spare_servers = 1
pm.max_spare_servers = 3

clear_env = no
```

### srcs/requirements/wordpress/tools/setup_wp.sh
```bash
#!/bin/bash

# Read secrets
DB_PASS=$(cat /run/secrets/db_password)
WP_CREDS=$(cat /run/secrets/credentials)
WP_ADMIN_PASS=$(echo "$WP_CREDS" | cut -d':' -f2)
WP_USER_PASS=$(echo "$WP_CREDS" | cut -d':' -f2)

# Wait for MariaDB
echo "Waiting for MariaDB..."
while ! mysqladmin ping -h mariadb -u "$MYSQL_USER" -p"$DB_PASS" --silent; do
    sleep 2
done
echo "MariaDB is ready!"

cd /var/www/html

# Download WordPress if not exists
if [ ! -f wp-config.php ]; then
    echo "Downloading WordPress..."
    wp core download --allow-root
    
    # Create wp-config.php
    wp config create \
        --dbname="$MYSQL_DATABASE" \
        --dbuser="$MYSQL_USER" \
        --dbpass="$DB_PASS" \
        --dbhost=mariadb:3306 \
        --allow-root
    
    # Install WordPress
    wp core install \
        --url="https://$DOMAIN_NAME" \
        --title="$WP_TITLE" \
        --admin_user="$WP_ADMIN_USER" \
        --admin_password="$WP_ADMIN_PASS" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --allow-root
    
    # Create regular user
    wp user create "$WP_USER" "$WP_USER_EMAIL" \
        --role=author \
        --user_pass="$WP_USER_PASS" \
        --allow-root
    
    # Set permissions
    chown -R www-data:www-data /var/www/html
    
    echo "WordPress installed successfully!"
fi

echo "Starting PHP-FPM..."
exec php-fpm7.4 -F
```

---

## 8. Docker Compose (srcs/docker-compose.yml)

```yaml
version: '3.8'

services:
  nginx:
    build: ./requirements/nginx
    container_name: nginx
    ports:
      - "443:443"
    volumes:
      - wordpress_data:/var/www/html
    networks:
      - inception
    depends_on:
      - wordpress
    restart: unless-stopped

  wordpress:
    build: ./requirements/wordpress
    container_name: wordpress
    env_file:
      - .env
    volumes:
      - wordpress_data:/var/www/html
    networks:
      - inception
    depends_on:
      - mariadb
    secrets:
      - db_password
      - credentials
    restart: unless-stopped

  mariadb:
    build: ./requirements/mariadb
    container_name: mariadb
    env_file:
      - .env
    volumes:
      - mariadb_data:/var/lib/mysql
    networks:
      - inception
    secrets:
      - db_password
      - db_root_password
    restart: unless-stopped

networks:
  inception:
    driver: bridge

volumes:
  wordpress_data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/basti/data/wordpress

  mariadb_data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/basti/data/mariadb

secrets:
  db_password:
    file: ../secrets/db_password.txt
  db_root_password:
    file: ../secrets/db_root_password.txt
  credentials:
    file: ../secrets/credentials.txt
```

---

## 9. Makefile

```makefile
NAME = inception

DATA_PATH = /home/basti/data

all: up

up:
	@mkdir -p $(DATA_PATH)/wordpress
	@mkdir -p $(DATA_PATH)/mariadb
	@docker-compose -f srcs/docker-compose.yml up -d --build

down:
	@docker-compose -f srcs/docker-compose.yml down

stop:
	@docker-compose -f srcs/docker-compose.yml stop

start:
	@docker-compose -f srcs/docker-compose.yml start

logs:
	@docker-compose -f srcs/docker-compose.yml logs -f

clean: down
	@docker system prune -af

fclean: clean
	@docker volume rm -f $$(docker volume ls -q) 2>/dev/null || true
	@sudo rm -rf $(DATA_PATH)/wordpress/*
	@sudo rm -rf $(DATA_PATH)/mariadb/*

re: fclean all

status:
	@docker ps
	@echo ""
	@docker volume ls

.PHONY: all up down stop start logs clean fclean re status
```

---

## 10. Build & Run

```bash
cd inception
make
```

### Verify everything works:
```bash
# Check containers are running
docker ps

# Check logs
make logs

# Test the website
curl -k https://basti.42.fr
```

Access in browser: `https://basti.42.fr`

---

## 11. Common Issues & Solutions

### Issue: MariaDB won't start
```bash
# Check logs
docker logs mariadb

# Reset database
make fclean
make
```

### Issue: WordPress can't connect to database
```bash
# Enter wordpress container
docker exec -it wordpress bash

# Test connection
mysql -h mariadb -u wpdbuser -p
```

### Issue: NGINX 502 Bad Gateway
```bash
# Check if php-fpm is running
docker exec wordpress ps aux | grep php
```

### Issue: Permission denied on volumes
```bash
sudo chown -R 1000:1000 /home/basti/data/wordpress
sudo chown -R 999:999 /home/basti/data/mariadb
```

---

## 12. Key Concepts to Understand

**For your evaluation, know these:**

1. **Docker vs VM**: Docker shares the host kernel (lighter, faster). VMs have full OS isolation.

2. **Docker Networks**: Containers communicate by service name. `wordpress` can reach `mariadb:3306`.

3. **Named Volumes vs Bind Mounts**: Named volumes are managed by Docker. We use local driver with bind to satisfy both requirements.

4. **Secrets vs Env Vars**: Secrets are mounted as files in `/run/secrets/`. More secure than env vars which appear in process lists.

5. **PID 1**: Container's main process. Must handle signals properly. That's why we use `exec` in entrypoints.

6. **TLS**: Only port 443 exposed. TLSv1.2/1.3 configured in nginx.

---

## Quick Reference Commands

```bash
# Build and start
make

# View logs
make logs

# Stop containers
make down

# Complete reset
make fclean && make

# Enter a container
docker exec -it nginx bash
docker exec -it wordpress bash
docker exec -it mariadb bash

# Check MySQL
docker exec -it mariadb mysql -u root -p
```
