NAME = inception

DATA_PATH = /home/sholz/data

all: up

up:
	@mkdir -p $(DATA_PATH)/wordpress
	@mkdir -p $(DATA_PATH)/mariadb
	@docker compose -f src/docker-compose.yml up -d --build
	@echo "Homepage: https://sholz.42.fr"
	@echo "Admin-Panel: https://sholz.42.fr/wp-admin"

down:
	@docker compose -f src/docker-compose.yml down

stop:
	@docker compose -f src/docker-compose.yml stop

start:
	@docker compose -f src/docker-compose.yml start

logs:
	@docker compose -f src/docker-compose.yml logs -f

clean:
	@docker compose -f src/docker-compose.yml down -v --rmi all --remove-orphans 2>/dev/null || true

fclean: clean
	@docker system prune -af --volumes
	@sudo rm -rf $(DATA_PATH)/wordpress
	@sudo rm -rf $(DATA_PATH)/mariadb

re: fclean all

status:
	@docker ps
	@echo ""
	@docker volume ls

.PHONY: all up down stop start logs clean fclean re status
