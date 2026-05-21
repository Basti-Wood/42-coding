# User Doc

## Contains

This project sets up a fully containerized web infrastructure using Docker. It includes:

- **NGINX** container with TLS (HTTPS)
- **WordPress** container with PHP-FPM
- **MariaDB** database container
- Docker volumes for persistent data
- Docker network for container communication
- Environment-based configuration for security and flexibility


## Manage Credentials

Inside the `Secrets/` folder are 3 files containing sensitive information:

1. `Credentials.txt`  
   - Contains the credentials of the WordPress administrator (username & password)

2. `db_password.txt`  
   - Contains the database password for a standard MariaDB user

3. `db_root_password.txt`  
   - Contains the database password for the MariaDB root/admin user


## requirements

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


## how to run

to run this programm you have to:

1. Copy the git repository inside your Home folder.

	```BASH
	git clone https://github.com/Basti-Wood/42Inception.git
	```
2. add your domain to your known hosts

	```BASH
	sudo bash -c 'echo "127.0.0.1 YOUR.DOMAIN.COM" >> /etc/hosts'
	```


3. navigate in the project folder and run the command "`make`" to build and start the project

	```BASH
	make
	```

## access the webpage and admin pannel

To open the webpage you have to go to your webbrowser and type in `https://YOUR.DOMAIN.COM`

To access the Admin Pannel of the webpage you have to type in `https:/YOUR.DOMAIN.COM/wp-admin`

Inside the Admin pannel, you have to login with either your admin user or your Editor user and password.

## check state

to check the state of the dockers run this command

	docker ps -a

