# Inception

*This project has been created as part of the 42 curriculum by basti.*

---

## Description

Inception is a system administration project that introduces Docker containerization. The goal is to set up a small infrastructure composed of different services (NGINX, WordPress, MariaDB) running in separate Docker containers, orchestrated with Docker Compose.

The infrastructure runs entirely within a Virtual Machine and follows strict security and configuration guidelines:

- **NGINX** serves as the only entry point via HTTPS (port 443)
- **WordPress** runs with PHP-FPM for dynamic content
- **MariaDB** provides the database backend
- All services communicate through a dedicated Docker network
- Data persists through Docker named volumes

---

## Architecture Overview

```
                         ┌─────────────────────────────────────────────────┐
                         │                    HOST VM                      │
    Internet             │  ┌─────────────────────────────────────────┐   │
        │                │  │           Docker Network                 │   │
        │ HTTPS          │  │                                         │   │
        ▼ (443)          │  │   ┌───────┐    ┌───────────┐   ┌─────┐ │   │
   ┌─────────┐           │  │   │       │    │           │   │     │ │   │
   │  User   │◄─────────────►   │ NGINX │◄──►│ WordPress │◄─►│ DB  │ │   │
   │ Browser │           │  │   │ :443  │9000│  :9000    │3306│:3306│ │   │
   └─────────┘           │  │   └───────┘    └───────────┘   └─────┘ │   │
                         │  │       │              │             │    │   │
                         │  └───────┼──────────────┼─────────────┼────┘   │
                         │          ▼              ▼             ▼        │
                         │     ┌─────────────────────────────────────┐    │
                         │     │     /home/login/data/               │    │
                         │     │     ├── wordpress/                  │    │
                         │     │     └── mariadb/                    │    │
                         │     └─────────────────────────────────────┘    │
                         └────────────────────────────────────────────────┘
```

---

## Project Structure

```
inception/
├── Makefile
├── README.md
├── USER_DOC.md
├── DEV_DOC.md
├── .gitignore
├── secrets/                          # NOT in git
│   ├── credentials.txt
│   ├── db_password.txt
│   └── db_root_password.txt
└── srcs/
    ├── .env                          # NOT in git
    ├── docker-compose.yml
    └── requirements/
        ├── mariadb/
        │   ├── Dockerfile
        │   ├── .dockerignore
        │   ├── conf/
        │   │   └── 50-server.cnf
        │   └── tools/
        │       └── init_db.sh
        ├── nginx/
        │   ├── Dockerfile
        │   ├── .dockerignore
        │   ├── conf/
        │   │   └── nginx.conf
        │   └── tools/
        └── wordpress/
            ├── Dockerfile
            ├── .dockerignore
            ├── conf/
            │   └── www.conf
            └── tools/
                └── setup_wp.sh
```

---

## Instructions

### Prerequisites

Your VM needs these packages installed:

```bash
# Update system
sudo apt update && sudo apt upgrade -y

# Install Docker and tools
sudo apt install -y docker.io docker-compose make openssl

# Add your user to docker group (no sudo needed for docker commands)
sudo usermod -aG docker $USER

# Apply group changes (or logout/login)
newgrp docker

# Verify installation
docker --version
docker-compose --version
```

### Step 1: Configure Domain Name

Add your domain to the hosts file:

```bash
# Replace 'basti' with your 42 login
sudo bash -c 'echo "127.0.0.1 basti.42.fr" >> /etc/hosts'

# Verify
cat /etc/hosts | grep 42.fr
```

### Step 2: Create Data Directories

```bash
# Replace 'basti' with your login
sudo mkdir -p /home/basti/data/wordpress
sudo mkdir -p /home/basti/data/mariadb
sudo chown -R $USER:$USER /home/basti/data
```

### Step 3: Create Project Structure

```bash
# Create all directories
mkdir -p inception/secrets
mkdir -p inception/srcs/requirements/mariadb/{conf,tools}
mkdir -p inception/srcs/requirements/nginx/{conf,tools}
mkdir -p inception/srcs/requirements/wordpress/{conf,tools}
cd inception
```

### Step 4: Create Secrets

**Important:** These files should NEVER be committed to git!

```bash
# Database password
echo "SecureDbPassword123!" > secrets/db_password.txt

# Database root password  
echo "SecureRootPassword456!" > secrets/db_root_password.txt

# WordPress admin password
echo "WpAdminPassword789!" > secrets/credentials.txt

# Set restrictive permissions
chmod 600 secrets/*
```

### Step 5: Create .gitignore

```bash
cat > .gitignore << 'EOF'
secrets/
srcs/.env
*.log
.DS_Store
EOF
```

### Step 6: Create Environment File

Create `srcs/.env`:

```bash
cat > srcs/.env << 'EOF'
# Domain (replace basti with your login)
DOMAIN_NAME=basti.42.fr

# MariaDB Configuration
MYSQL_DATABASE=wordpress
MYSQL_USER=wpdbuser

# WordPress Configuration
WP_TITLE=Inception
WP_ADMIN_USER=boss
WP_ADMIN_EMAIL=boss@basti.42.fr
WP_USER=editor
WP_USER_EMAIL=editor@basti.42.fr

# Data path (replace basti with your login)
DATA_PATH=/home/basti/data
EOF
```

**Note:** `WP_ADMIN_USER` cannot contain "admin" or "administrator"!

### Step 7: Create MariaDB Files

**srcs/requirements/mariadb/Dockerfile:**

```bash
cat > srcs/requirements/mariadb/Dockerfile << 'EOF'
FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    mariadb-server \
    mariadb-client \
    && rm -rf /var/lib/apt/lists/*

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/init_db.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/init_db.sh && \
    mkdir -p /var/run/mysqld && \
    chown -R mysql:mysql /var/run/mysqld && \
    chmod 755 /var/run/mysqld

EXPOSE 3306

ENTRYPOINT ["init_db.sh"]
EOF
```

**srcs/requirements/mariadb/conf/50-server.cnf:**

```bash
cat > srcs/requirements/mariadb/conf/50-server.cnf << 'EOF'
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
character-set-server    = utf8mb4
collation-server        = utf8mb4_general_ci
EOF
```

**srcs/requirements/mariadb/tools/init_db.sh:**

```bash
cat > srcs/requirements/mariadb/tools/init_db.sh << 'EOF'
#!/bin/bash

DB_ROOT_PASS=$(cat /run/secrets/db_root_password)
DB_PASS=$(cat /run/secrets/db_password)

if [ ! -d "/var/lib/mysql/$MYSQL_DATABASE" ]; then
    echo "Initializing MariaDB..."
    
    mysqld_safe &
    sleep 5
    
    mysql -u root << EOSQL
CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$DB_PASS';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASS';
FLUSH PRIVILEGES;
EOSQL
    
    mysqladmin -u root -p"$DB_ROOT_PASS" shutdown
    sleep 2
    echo "MariaDB initialized!"
fi

echo "Starting MariaDB..."
exec mysqld_safe
EOF

chmod +x srcs/requirements/mariadb/tools/init_db.sh
```

### Step 8: Create NGINX Files

**srcs/requirements/nginx/Dockerfile:**

```bash
cat > srcs/requirements/nginx/Dockerfile << 'EOF'
FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /etc/nginx/ssl && \
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/nginx.key \
    -out /etc/nginx/ssl/nginx.crt \
    -subj "/C=DE/ST=Berlin/L=Berlin/O=42/OU=42/CN=basti.42.fr"

COPY conf/nginx.conf /etc/nginx/conf.d/default.conf

RUN rm -f /etc/nginx/sites-enabled/default

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
EOF
```

**srcs/requirements/nginx/conf/nginx.conf:**

```bash
cat > srcs/requirements/nginx/conf/nginx.conf << 'EOF'
server {
    listen 443 ssl;
    listen [::]:443 ssl;
    
    server_name basti.42.fr;
    
    ssl_certificate     /etc/nginx/ssl/nginx.crt;
    ssl_certificate_key /etc/nginx/ssl/nginx.key;
    ssl_protocols       TLSv1.2 TLSv1.3;
    
    root /var/www/html;
    index index.php index.html;
    
    location / {
        try_files $uri $uri/ /index.php?$args;
    }
    
    location ~ \.php$ {
        try_files $uri =404;
        fastcgi_split_path_info ^(.+\.php)(/.+)$;
        fastcgi_pass wordpress:9000;
        fastcgi_index index.php;
        include fastcgi_params;
        fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
        fastcgi_param PATH_INFO $fastcgi_path_info;
    }
}
EOF
```

### Step 9: Create WordPress Files

**srcs/requirements/wordpress/Dockerfile:**

```bash
cat > srcs/requirements/wordpress/Dockerfile << 'EOF'
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

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY tools/setup_wp.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/setup_wp.sh && \
    mkdir -p /var/www/html /run/php && \
    chown -R www-data:www-data /var/www/html

WORKDIR /var/www/html

EXPOSE 9000

ENTRYPOINT ["setup_wp.sh"]
EOF
```

**srcs/requirements/wordpress/conf/www.conf:**

```bash
cat > srcs/requirements/wordpress/conf/www.conf << 'EOF'
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
EOF
```

**srcs/requirements/wordpress/tools/setup_wp.sh:**

```bash
cat > srcs/requirements/wordpress/tools/setup_wp.sh << 'EOF'
#!/bin/bash

DB_PASS=$(cat /run/secrets/db_password)
WP_ADMIN_PASS=$(cat /run/secrets/credentials)

echo "Waiting for MariaDB..."
while ! mysqladmin ping -h mariadb -u "$MYSQL_USER" -p"$DB_PASS" --silent; do
    sleep 2
done
echo "MariaDB ready!"

cd /var/www/html

if [ ! -f wp-config.php ]; then
    echo "Installing WordPress..."
    
    wp core download --allow-root
    
    wp config create \
        --dbname="$MYSQL_DATABASE" \
        --dbuser="$MYSQL_USER" \
        --dbpass="$DB_PASS" \
        --dbhost=mariadb:3306 \
        --allow-root
    
    wp core install \
        --url="https://$DOMAIN_NAME" \
        --title="$WP_TITLE" \
        --admin_user="$WP_ADMIN_USER" \
        --admin_password="$WP_ADMIN_PASS" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --allow-root
    
    wp user create "$WP_USER" "$WP_USER_EMAIL" \
        --role=author \
        --user_pass="$WP_ADMIN_PASS" \
        --allow-root
    
    chown -R www-data:www-data /var/www/html
    echo "WordPress installed!"
fi

echo "Starting PHP-FPM..."
exec php-fpm7.4 -F
EOF

chmod +x srcs/requirements/wordpress/tools/setup_wp.sh
```

### Step 10: Create Docker Compose

**srcs/docker-compose.yml:**

```bash
cat > srcs/docker-compose.yml << 'EOF'
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
EOF
```

### Step 11: Create Makefile

```bash
cat > Makefile << 'EOF'
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
	@echo "=== Containers ==="
	@docker ps -a
	@echo ""
	@echo "=== Volumes ==="
	@docker volume ls
	@echo ""
	@echo "=== Networks ==="
	@docker network ls | grep inception

.PHONY: all up down stop start logs clean fclean re status
EOF
```

### Step 12: Build and Run

```bash
# Build and start all containers
make

# Check status
make status

# View logs
make logs

# Access the site
# Open browser: https://basti.42.fr
# (Accept the self-signed certificate warning)
```

---

## Useful Commands

### Container Management

```bash
# Start everything
make

# Stop containers (keep data)
make down

# Full reset (removes all data)
make fclean && make

# View real-time logs
make logs

# Check what's running
make status
```

### Debugging

```bash
# Enter a container shell
docker exec -it nginx bash
docker exec -it wordpress bash
docker exec -it mariadb bash

# Check container logs individually
docker logs nginx
docker logs wordpress
docker logs mariadb

# Test database connection from wordpress
docker exec -it wordpress mysql -h mariadb -u wpdbuser -p

# Check if PHP-FPM is running
docker exec wordpress ps aux | grep php

# Check nginx configuration
docker exec nginx nginx -t

# Test HTTPS locally
curl -k https://basti.42.fr
```

### Volume and Network Inspection

```bash
# List volumes
docker volume ls

# Inspect a volume
docker volume inspect srcs_wordpress_data

# List networks
docker network ls

# Inspect network
docker network inspect srcs_inception
```

---

## Troubleshooting

### MariaDB Won't Start

```bash
# Check logs
docker logs mariadb

# Common fix: reset everything
make fclean
make
```

### WordPress Can't Connect to Database

```bash
# Verify MariaDB is running
docker ps | grep mariadb

# Test connection manually
docker exec -it wordpress bash
mysql -h mariadb -u wpdbuser -p
# Enter password from secrets/db_password.txt
```

### NGINX 502 Bad Gateway

This means NGINX can't reach PHP-FPM.

```bash
# Check if WordPress container is running
docker ps | grep wordpress

# Check PHP-FPM inside wordpress container
docker exec wordpress ps aux | grep php

# Restart wordpress
docker restart wordpress
```

### Permission Denied on Volumes

```bash
# Fix WordPress permissions
sudo chown -R 33:33 /home/basti/data/wordpress

# Fix MariaDB permissions  
sudo chown -R 999:999 /home/basti/data/mariadb
```

### Certificate Warning in Browser

This is expected! You're using a self-signed certificate. Click "Advanced" → "Proceed anyway" (or similar depending on browser).

---

## Resources

### Official Documentation

- [Docker Documentation](https://docs.docker.com/)
- [Docker Compose Reference](https://docs.docker.com/compose/compose-file/)
- [NGINX Documentation](https://nginx.org/en/docs/)
- [WordPress CLI Handbook](https://developer.wordpress.org/cli/commands/)
- [MariaDB Documentation](https://mariadb.com/kb/en/documentation/)

### Tutorials

- [Docker Getting Started](https://docs.docker.com/get-started/)
- [Dockerfile Best Practices](https://docs.docker.com/develop/develop-images/dockerfile_best-practices/)

### AI Usage

AI tools were used to assist with:

- Generating boilerplate configuration files
- Debugging shell script syntax
- Explaining Docker networking concepts
- Reviewing Dockerfile best practices

All AI-generated content was reviewed, tested, and understood before inclusion.

---

## Project Description

### What This Project Does

This project creates a complete web hosting infrastructure using Docker containers:

1. **NGINX** - Web server handling HTTPS connections
2. **WordPress** - Content management system with PHP-FPM
3. **MariaDB** - Database server storing WordPress data

All components run in isolated containers and communicate through a private Docker network.

### Design Choices

- **Base Image:** Debian Bullseye (penultimate stable as required)
- **TLS Version:** TLSv1.2 and TLSv1.3 only (modern, secure)
- **Process Management:** Each container runs one main process as PID 1
- **Secrets:** Stored in files, mounted at runtime (not in environment)

---

## Key Comparisons (For Evaluation)

### Virtual Machines vs Docker

| Aspect | Virtual Machine | Docker Container |
|--------|----------------|------------------|
| **Isolation** | Full OS isolation with hypervisor | Process isolation, shares host kernel |
| **Size** | GBs (full OS) | MBs (just app + dependencies) |
| **Startup** | Minutes | Seconds |
| **Resource Usage** | High (dedicated RAM, CPU) | Low (shared resources) |
| **Use Case** | Strong isolation needed | Microservices, dev environments |

**Why Docker for this project:** Lightweight, fast deployment, easy orchestration with docker-compose.

### Secrets vs Environment Variables

| Aspect | Environment Variables | Docker Secrets |
|--------|----------------------|----------------|
| **Storage** | In container environment | Mounted as files in /run/secrets/ |
| **Visibility** | Visible in `docker inspect`, process list | Only inside container filesystem |
| **Security** | Lower (can leak in logs) | Higher (file-based, restricted access) |
| **Use Case** | Non-sensitive config | Passwords, API keys |

**Why Secrets for this project:** Passwords should not be visible in process lists or docker inspect output.

### Docker Network vs Host Network

| Aspect | Docker Bridge Network | Host Network |
|--------|----------------------|--------------|
| **Isolation** | Containers isolated from host | No isolation, uses host ports directly |
| **Port Mapping** | Explicit port mapping needed | All ports exposed |
| **DNS** | Container names resolve automatically | Must use localhost/IP |
| **Security** | Better (controlled exposure) | Lower (full access) |

**Why Bridge Network:** Containers can communicate by name (e.g., `mariadb:3306`), only port 443 exposed to outside.

### Docker Volumes vs Bind Mounts

| Aspect | Named Volumes | Bind Mounts |
|--------|--------------|-------------|
| **Management** | Docker manages location | You specify exact host path |
| **Portability** | More portable | Host-path dependent |
| **Backup** | Via Docker commands | Direct file access |
| **Performance** | Optimized by Docker | Direct filesystem access |

**This project uses both:** Named volumes with `local` driver and `device` option to satisfy the requirement of data in `/home/login/data/` while using Docker's volume management.

---

## Evaluation Checklist

Before your evaluation, verify:

- [ ] All containers start with `make`
- [ ] Website accessible at `https://login.42.fr`
- [ ] TLS working (check with `curl -k https://login.42.fr`)
- [ ] Two WordPress users exist (admin + regular)
- [ ] Admin username doesn't contain "admin"
- [ ] Data persists after `make down && make up`
- [ ] Containers restart after crash (`docker kill nginx && sleep 5 && docker ps`)
- [ ] No passwords in Dockerfiles
- [ ] No `latest` tags used
- [ ] No infinite loops in entrypoints
- [ ] Secrets not in git repository

---

## Quick Setup Script

Run this to create the entire structure (adjust login first!):

```bash
#!/bin/bash
LOGIN="basti"  # CHANGE THIS TO YOUR LOGIN

# Create directories
mkdir -p inception/secrets
mkdir -p inception/srcs/requirements/{mariadb,nginx,wordpress}/{conf,tools}

# Create secrets (change passwords!)
echo "DbPass123!" > inception/secrets/db_password.txt
echo "RootPass456!" > inception/secrets/db_root_password.txt
echo "WpPass789!" > inception/secrets/credentials.txt

# Set permissions
chmod 600 inception/secrets/*

# Create data directories
sudo mkdir -p /home/$LOGIN/data/{wordpress,mariadb}
sudo chown -R $USER:$USER /home/$LOGIN/data

# Add to hosts
sudo bash -c "echo '127.0.0.1 $LOGIN.42.fr' >> /etc/hosts"

echo "Structure created! Now add the configuration files."
```

---

*Remember: Understanding > Copying. Be prepared to explain every line during evaluation.*
