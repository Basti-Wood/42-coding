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

## manage container

## where is the data