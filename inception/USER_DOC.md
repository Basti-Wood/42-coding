# User Doc

## Overview

This project sets up a fully containerized web infrastructure using Docker. It includes:

- **NGINX** — handles HTTPS traffic (TLS only, port 443)
- **WordPress** — the website, running with PHP-FPM
- **MariaDB** — the database backend
- Persistent volumes so data survives container restarts
- An internal Docker network for secure container communication

---

## Requirements

Run these commands once to install the necessary tools:

```bash
# Update system
sudo apt update && sudo apt upgrade -y

# Install Docker and tools
sudo apt install -y docker.io docker-compose make openssl git

# Add your user to the docker group (avoids needing sudo for docker commands)
sudo usermod -aG docker $USER

# Apply group changes (or log out and back in)
newgrp docker

# Verify installation
docker --version
docker-compose --version
```

---

## Credentials

The `secrets/` folder contains three files with login credentials.
**Do not share or commit these files.**

| File                  | Contains                                      |
|-----------------------|-----------------------------------------------|
| `credentials.txt`     | WordPress admin username and password         |
| `db_password.txt`     | MariaDB user password                         |
| `db_root_password.txt`| MariaDB root password                         |

---

## How to Run

**1. Clone the repository into your home folder**

```bash
git clone https://github.com/Basti-Wood/42Inception.git ~/Inception
```

**2. Register your domain in `/etc/hosts`**

This makes your browser resolve the domain locally instead of going to the internet.

```bash
sudo bash -c 'echo "127.0.0.1 YOUR.DOMAIN.COM" >> /etc/hosts'
```

Replace `YOUR.DOMAIN.COM` with your actual domain (e.g. `sholz.42.fr`).

**3. Build and start the project**

Navigate into the project folder and run:

```bash
make
```

The first build takes a few minutes. Once done, all three containers (`nginx`, `wordpress`, `mariadb`) should be running.

**4. Confirm everything is up**

```bash
docker ps
```

You should see all three containers with status `Up`.

---

## Access the Website

| Page          | URL                                  |
|---------------|--------------------------------------|
| Website       | `https://YOUR.DOMAIN.COM`            |
| Admin Panel   | `https://YOUR.DOMAIN.COM/wp-admin`   |

> Your browser may warn about the certificate — this is expected since it is self-signed. Accept the exception to continue.

Log in to the Admin Panel using the credentials from `secrets/credentials.txt`.

---

## Stop and Restart

```bash
# Stop all containers (data is preserved)
make down

# Full reset — stops containers and deletes all data
make clean

# Rebuild everything from scratch
make re
```

---

## Check Container State

```bash
# Show running containers
docker ps

# Show all containers including stopped ones
docker ps -a

# View logs for a specific container
docker logs -f nginx
docker logs -f wordpress
docker logs -f mariadb
```