# Dev Doc

This document describes the development setup and internal architecture of the **42 Inception** project.

---

## Project Structure

```bash
Inception/
├── Makefile
├── secrets/
│   ├── credentials.txt        # WordPress admin credentials
│   ├── db_password.txt        # MariaDB user password
│   └── db_root_password.txt   # MariaDB root password
└── src/
    ├── docker-compose.yml
    └── requirements/
        ├── mariadb/
        │   ├── conf/
        │   │   └── 50-server.cnf     # MariaDB server configuration
        │   ├── Dockerfile
        │   └── tools/
        │       └── init_db.sh        # Database and user initialization
        ├── nginx/
        │   ├── conf/
        │   │   └── nginx.conf        # TLS termination and reverse proxy config
        │   ├── Dockerfile
        │   └── tools/
        └── wordpress/
            ├── conf/
            │   └── www.conf          # PHP-FPM pool configuration
            ├── Dockerfile
            └── tools/
                └── setup_wp.sh       # WordPress installation via WP-CLI
```

---

## Setup

### Requirements

```bash
# Update system
sudo apt update && sudo apt upgrade -y

# Install Docker and tools
sudo apt install -y docker.io docker-compose make openssl git

# Add your user to the docker group (avoids needing sudo for docker commands)
sudo usermod -aG docker $USER

# Apply group changes (or logout/login)
newgrp docker

# Verify installation
docker --version
docker-compose --version
```

### Secrets

The `secrets/` folder contains three files with sensitive credentials.
They are mounted into containers at runtime under `/run/secrets/<name>` and read by the entrypoint scripts — they are never baked into the images.

| File                  | Purpose                              |
|-----------------------|--------------------------------------|
| `credentials.txt`     | WordPress admin username and password|
| `db_password.txt`     | MariaDB user password                |
| `db_root_password.txt`| MariaDB root password                |

### Dockerfile

Each service has its own `Dockerfile` that defines how its image is built.
It specifies the base image, installs dependencies, copies configuration files and scripts into the image, and sets the entrypoint. Images are built locally — no pre-built application images are pulled from Docker Hub (as required by the project rules).

### docker-compose.yml

Defines all three services (`nginx`, `wordpress`, `mariadb`), their build contexts, volumes, secrets, and the shared internal network. It is the single source of truth for how the containers are wired together.

---

## Build and Launch

All commands are run from the project root via the Makefile.

```bash
make        # builds all images and starts the stack
make down   # stops and removes containers
make clean  # removes containers and volumes
make re     # full rebuild from scratch (clean + build)
```

On first boot, `init_db.sh` initializes the MariaDB database and creates the WordPress user. `setup_wp.sh` then runs WP-CLI to install and configure WordPress. Both scripts are idempotent — they check whether setup has already been done before running.

---

## Manage Containers

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

# Restart a single service without a full rebuild
docker compose restart wordpress
```

---

## Where is the Data

Persistent data is stored on the host machine and mounted into containers via named Docker volumes:

| Volume           | Host path                    | Used by   |
|------------------|------------------------------|-----------|
| `wordpress_data` | `/home/$USER/data/wordpress` | WordPress |
| `mariadb_data`   | `/home/$USER/data/mariadb`   | MariaDB   |

Volumes use the `local` driver with `driver_opts` to bind-mount the host path. Data survives `docker compose down` but is wiped by `make clean`.

---

## Network & TLS

All external traffic enters through **NGINX** on port `443`. Only TLS 1.2 and 1.3 are accepted — port 80 is not exposed.

NGINX acts as a reverse proxy, forwarding PHP requests to WordPress via FastCGI on port `9000`. WordPress communicates with MariaDB internally on port `3306`. The database port is never exposed to the host.