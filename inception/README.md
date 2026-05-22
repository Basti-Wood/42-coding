# Inception

*This project has been created as part of the 42 curriculum by sholz.*

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
                         ┌──────────────────────────────────────────────────┐
                         │                    HOST VM                       │
    Internet             │  ┌───────────────────────────────────────────┐   │
        │                │  │           Docker Network                  │   │
        │ HTTPS          │  │                                           │   │
        ▼ (443)          │  │   ┌───────┐    ┌───────────┐    ┌──────┐  │   │
   ┌─────────┐           │  │   │       │    │           │    │      │  │   │
   │  User   │◄─────────────►   │ NGINX │◄──►│ WordPress │◄──►│ DB   │  │   │
   │ Browser │           │  │   │ :443  │9000│  :9000    │3306│:3306 │  │   │
   └─────────┘           │  │   └───────┘    └───────────┘    └──────┘  │   │
                         │  │       │              │             │      │   │
                         │  └───────┼──────────────┼─────────────┼──────┘   │
                         │          ▼              ▼             ▼          │
                         │     ┌─────────────────────────────────────┐      │
                         │     │     /home/login/data/               │      │
                         │     │     ├── wordpress/                  │      │
                         │     │     └── mariadb/                    │      │
                         │     └─────────────────────────────────────┘      │
                         └──────────────────────────────────────────────────┘
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
# instructions

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



# recources

in the making of this project the following recources were used

## links
- https://github.com/Forstman1/inception-42
- https://docs.docker.com/
- https://github.com/waltergcc/42-inception
- and more

## AI
- Chat GPT
- Claude
- Gemini
- Copilot

## usage
AI was mostly used, to help find errors, fix those errors and help structure the project.