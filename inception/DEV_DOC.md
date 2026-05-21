# Dev Doc

## Set up

This document describes the development setup and internal architecture of the **42 Inception** project.

---

### Project Structure

```bash
	Inception/
	├── Makefile
	├── secrets/
	│   ├── credentials.txt
	│   ├── db_password.txt
	│   └── db_root_password.txt
	└── src/
		├── docker-compose.yml
		└── requirements/
			├── mariadb/
			│   ├── conf/
			│   │   └── 50-server.cnf
			│   ├── Dockerfile
			│   └── tools/
			│       └── init_db.sh
			├── nginx/
			│   ├── conf/
			│   │   └── nginx.conf
			│   ├── Dockerfile
			│   └── tools/
			└── wordpress/
				├── conf/
				│   └── www.conf
				├── Dockerfile
				└── tools/
					└── setup_wp.sh
```


## build and launch

### requirements

```bash
# Update system
sudo apt update && sudo apt upgrade -y

# Install Docker and tools
sudo apt install -y docker.io docker-compose make openssl git

# Add your user to docker group (no sudo needed for docker commands)
sudo usermod -aG docker $USER

# Apply group changes (or logout/login)
newgrp docker

# Verify installation
docker --version
docker-compose --version
```
### Secrets

Inside the `Secrets/` folder are 3 files containing sensitive information:

1. `Credentials.txt`  
   - Contains the credentials of the WordPress administrator (username & password)

2. `db_password.txt`  
   - Contains the database password for a standard MariaDB user

3. `db_root_password.txt`  
   - Contains the database password for the MariaDB root/admin user

### Docker compose

contains the container information for the different dockers.

### DOCKERFILE

ist like a makefile for dockers. constructs a docker, that has to copy the content into it.


## manage container

```bash
# View running containers
docker ps

# Follow logs for a specific service
docker logs -f nginx
docker logs -f wordpress
docker logs -f mariadb

# Open a shell inside a container
docker exec -it wordpress bash
docker exec -it mariadb bash

# Restart a single service without full rebuild
docker compose restart wordpress
```


## where is the data

Data is stored in /home/Username/Data


## Network & TLS

All traffic enters through **NGINX** on port `443`. Only TLS 1.2 and 1.3 are accepted. HTTP (port 80) is not exposed.

NGINX acts as a reverse proxy, forwarding PHP requests to WordPress via FastCGI on port `9000`. WordPress communicates with MariaDB internally on port `3306`. No database port is exposed to the host.

