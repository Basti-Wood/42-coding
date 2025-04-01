# Simplified Makefile for so_long with colored Zelda output

NAME        = so_long
CC          = clang
FLAG        = -Wall -Wextra -Werror

# Library paths
LIBFT_PATH  = ./ft_printf/
LIBFT_FILE  = libftprintf.a
MLX_PATH    = ./minilibx-linux/
MLX_FILE    = libmlx.a
MLX_FLAG    = -lX11 -lXext
GNL_PATH    = ./get_next_line/

# Automatic file finding
SRC_DIR     = ./src/
INC_DIR     = ./includes/
SRC         = $(wildcard $(SRC_DIR)*.c) $(wildcard $(GNL_PATH)*.c)
OBJ         = $(SRC:.c=.o)

# Basic ANSI Colors (widely supported)
RED      = \033[0;31m
GREEN    = \033[0;32m
YELLOW   = \033[0;33m
BLUE     = \033[0;34m
CYAN	= \e[0;36m
GRAY	= \e[0;37m
NC       = \033[0m 


# Extended 256 Colors (for terminals that support it)
BEIGE     = \033[38;5;223m
WHITE     = \033[0;0m
GRAY      = \033[38;5;245m
BROWN     = \033[38;5;130m    # or 94 for darker brown
DARK_RED  = \033[38;5;88m     # deeper red
DARK_GREEN = \033[38;5;22m    # forest green

# Light Green options (choose one)
LIGHT_GREEN = \033[38;5;120m   # Bright minty green
LIGHT_GREEN2 = \033[38;5;156m  # Softer lime green
LIGHT_GREEN3 = \033[38;5;46m   # Vivid light green (brighter)

# Rules
all: $(NAME)

lib:
	@echo "$(YELLOW)\nCOMPILING $(LIBFT_PATH)\n$(NC)"
	@make -C $(LIBFT_PATH)
	@echo "$(GREEN)LIBFT_lib created\n$(NC)"

mlx:
	@echo "$(YELLOW)\nCOMPILING $(MLX_PATH)...\n$(NC)"
	@make -sC $(MLX_PATH)
	@echo "$(GREEN)MLX_lib created\n$(NC)"

$(NAME): lib mlx $(OBJ)
	@echo "$(YELLOW)\nCOMPILING SO_LONG...\n$(NC)"
	@$(CC) $(FLAG) $(OBJ) $(addprefix $(LIBFT_PATH), $(LIBFT_FILE)) \
		$(addprefix $(MLX_PATH), $(MLX_FILE)) $(MLX_FLAG) -o $(NAME)
	@echo "$(GREEN)./so_long created\n$(NC)"
	@echo "$(DARK_RED)It's dangerous to go alone...$(NC)"| pv -qL 10
	@echo "$(GREEN)	   Take this!$(NC)"| pv -qL 15
	@sleep 0 
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⡦⢄⣀⣀⣀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠽⠶⠒⠒⠒⠲⠶⠄⠉⠙⣦⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⠖⠺⠷⠤⢄⣀⡀⠠⢤⣢⣴⠞⠉⠉⠉⠉⠉⠙⠳⢦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠋⠀⠀⠀⡀⠠⠀⢈⣡⠶⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⢤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "${YELLOW}⠀⠀ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⠋⢀⡶⠚⠋⠙⠚⠏⣙⡷⠒⠉⠁⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠋⢳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠞⠉⣿⢠⠟⠀⢀⡠⢔⡞⠀⣸⣿⡀⠀⠀⠉⠉⠉⠙⢢⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⢷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠖⠛⠁⢰⢇⣿⠀⠀⡞⢀⡞⠀⠀⡇⣿⢿⠢⣄⣀⠀⠀⠀⠀⠈⢻⣿⠒⠦⢤⣤⠤⡄${BEIGE}⣠⡼⢻⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡟⠀⣿⢀⠄⠀⢸⠀⠀⠀⠀⣿⠀⠛⣤⠈⢛⠢⠄⠀⠀⠀⢹⡷⢄⠀${BEIGE}⣠⡶⣻⠟⢀⣾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣞⡴⠚⡇⠀⠀⢰⠸⡇⠀⠀⣸⠇⠊⠀${CYAN}⣠⣿${WHITE}⣮⣷${YELLOW}⢦⣄⠀⠀⠀⢹${BEIGE}⣠⠞⠁⣰⠟⠀⣾${YELLOW}⠋⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⠞⠁⠀⣸⠁⠀⠀⠀⠀⢹⣄⣼⠃⢀⣤${CYAN}⣾⣿${WHITE}⣿⣿⣽⡖${YELLOW}⢸⣧⠀⢸⡿⢯${BEIGE}⡀⣸⠁⠀⣼⠏${YELLOW}⣀⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠒⠚⢀⡟⠀⣀⣤⢄⣴⣿⠞⠑⠛⠛⠙${CYAN}⡟⠙⣷⣿⡿⠀${YELLOW}⢸⡿⡇⣼⡁⠀⠳${BEIGE}⣟⠀⣰⠋⠀${YELLOW}⣿⡇⢳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠟⢉⣻⣶⣾⣻⣿${CYAN}⣟${WHITE}⣫⣄⠀⠀⠀${CYAN}⠉⠀⠘⠋⠀⠀${YELLOW}⢸⠇⣿⣿⡝⢦⡀⠘${BEIGE}⢦⠟⠀${YELLOW}⢰⠁⣤⣤⣳⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⡵⠞⠛⠋⠉⣿${BEIGE}⣾⡉${CYAN}⢳⡟⠻⡇⠀⠀⠀⠀⠀⠀⠀${YELLOW}⢀⡾⢈⣡⣿⢦⠀⢿⣦⡈⣧⢠⢏⣶⠋⠀⠈⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡯${BEIGE}⣿⣟⠓⠀⠀⠇⠀⠀⠀⠀⠀${YELLOW}⠀⠒⠛⠋⠁⣼⡟⢸⠀⣦⣧⢿⣻⣿⣿⣿⣶⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼⢸${BEIGE}⢸⢻⣧⡀⠀⠛⠢⠄⠀⠀⠀⠀⠀⠀${YELLOW}⢀⣼⡟⢁⡞⠀⠘⣿⣽⣿⣧⠀⠀⢠⠈⠳⡝⢳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠞⠁⢸⣸⡇${BEIGE}⣟⠳⣄⡀⠠⠶⠒⠻⠛⠂⠀${YELLOW}⣠⢾⠏⣠⠞⠀⠀⣤⢟⡿⠘⣿⠀⠀⠈⢣⠀⠈⠢⡙⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠶⠚⠉⣉⠟⠁⢀⣞⣵⠿⠟⠉${BEIGE}⠀⠈⠛⠶⣄⠀⠉⠀${YELLOW}⣠⣴⠥⠞⠋⠁⣀⡰⠾⠷⠾⠦⣬⣙⣧⡀⠀⠈⡇⠀⠀⠀⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠿⠗⠒⠲⠾⣷⣀⣶⠿⠋⠁⠀⠀⠀⠀⠀⠀⢀⣈⣽⣶⠯⠽⢶⣆⣠⣴⠚⠉⣉⠩⠭⠳⠦⣄⣈⠉⢙⠶⢦⣅⠀⠀⠀⣿⠋⢧⡀⠀⠀⠀⠀⠀⠀"
	@echo "⠀${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠠⠎⠁⠀⠀⠀⠀⠀⠀⠋⠁⠀⠀⠀⠀⠀⠀⠀⣠⢶⡿⢋⣁⣄⡴⠞⠉⠁⠈⠉⠙⠙⠲⢯⣒⠦⢄⣀⢩⡿⠿⢦⣘⣿⣗⡖⠶⣯⣀⠈⠉⠀⠀⠀⠀⠀⠀"
	@echo "${BLUE}⣠⠴⠒⢿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀${YELLOW}⠀⠀⠀⠀⠀⠀⣰⡾⢻⡿⠋⠉${GREEN}⠀⣀⠴⠒⠉⠁⠀⠀⠀⠀⠀⢀${BLUE}⠻⣧⠀⠀⣠⣥⢾⣿⣿⡫⠍⢻⣟⣶⣀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣁⣀⠀⠈⣿⡉⠻⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀${YELLOW}⠀⠀⠀⠀⠀⢠⠞⠉${GREEN}⠀⢀⣿⡠⢖⠾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀${BLUE}⣿⣷⠀⣞⢙⣧⣠⣀⡉⠻⣶⣼⠃⢘⣿⠶⣄⡀⠀⠀⠀⠀"
	@echo "⢇⡽⠃⠀⠹⣿⠀⠉⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀${GREEN}⠀⠀⠀⠀⠀⠀⠀⢀⣼⣯⠗⠋⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠠${BLUE}⢹⢻⠀⢿⣿⠟⠉⢯⡙⠶⣌⠉⣑⣾⣇⠀⠉⢿⠀⠀⠀⠀"
	@echo "⠏⠀⣰⡆⠀⠹⣷⠀⠘⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀${GREEN}⠀⠀⠀⠀⠀⠀⢀⡾⠋⠁⠀⠀⠀⠀⣠⣾⠁⠀⠀⠀⠀⠀⡴⠃⠈⣏⡆⡀${BLUE}⣻⣦⠀⠘⣧⠀⠈⢻⡟⠓⢿⣄⠀⠘⣦⠀⠀⠀"
	@echo "⡤⢊⠼⡃⠀⠀⠻⣷⠀⠙⣆⠀⠀⠀⠀⠀⠀⠀⠀${GREEN}⠀⠀⠀⠀⠀⢠⡾⠁⠀⠀⠀⠀⠀⠀⣠⠏⠀⠀⠀⠀⠀⠀⢰⠀⠀⢹⣷⠀⠀${BLUE}⣿⣼⡀⠸⣇⠀⠀⢿⢦⠈⢿⡄⠀⢿⣦⡀⠀"
	@echo "⠋⠁⢸⣷⠀⠀⠀⠹⣷⡀⠘⢦⠀⠀⠀⠀⠀⠀⠀${GREEN}⠀⠀⠀⠀⢀⣼⠃⠀⠀⠀⠀⣀⡤⠞⠁⠀⠀⠀⠀⠀⠀⢰⣾⠆⠀⢸⠹⣆⢀${BLUE}⢻⣷⣱⣄⣽⣖⣂⣈⣾⣷⣨⣿⣄⠘⠇⠙⢆"
	@echo "${RED}⠀⣰⣿${BLUE}⠋⣧⠀⠀⠀⠈⢿⡀⠘⢧⡀⠀⠀⠀⠀⠀${GREEN}⠀⠀⠀⠀⣸⡏⠀⠀⢠⡴⠚⠁⣠⠴⡀⠀⠀⠀⠀⠀⠀⢸⠉⠀⢀⡟⠀⣿⠈⠈${BLUE}⣿⣿⢿⡻⣿⣏⣩⣝⣩⣍⣭⣿⡆⠀⢠⠤"
	@echo "${RED}⣾⣿⠃⠀${BLUE}⠘⣧⠀⠀⠀⠈⠻⣆⠀⠹⣦⡀⠀⠀⠀${GREEN}⠀⠀⠀⣰⡏⣀⣴⠧⠤⠼⡞⣯⠶⠚⣃⣠⠄⠀⠀⠀⠀⠀⠀⢤⢼⡅⣼⠟${BLUE}⠀⡇⡜⢿⡎⢧⣀⣷⣀⣀⠀⠀⠀⣸⠃⠀⢀⣤"
	@echo "${RED}⣿⠃⠀⠀${BLUE}⠈⠈⣷⣄⠀⠀⠀⠘⢷⡄⠙⢿⣦⠀⠀${GREEN}⠀⠀⣴⣿⠯⢵⣶⡿⠛⠛⠓⠲⢤⣅⠀⠓⢤⡀⠀⠀⠀⡐⠂⣸⠀⣼${BLUE}⠋⠀⠀⡇⢸⡜⢿⣯⠉⢯⠙⠛⠻⠯⣟⠈⣧⣴⠟⠁"
	@echo "${RED}⣧⡀⠀⠀⠀${BLUE}⠀⠈⢿⣦⡀⠀⠀⠀⠹⣧⣀⠙⢿⣦⡀${GREEN}⣿⢁${BEIGE}⣤⡴⠋⠁⠀⠀⠀⠀⠀⠀${GREEN}⠈⠻⣷⣖⠜⣆⠀⢸⡀⠀⣿⣾⠃${BLUE}⠀⠀⣴⡧⠀⢧⠈⢿⡆⠘⣧⠀⠀⠀⢀⠀⢹⣟⠀⠀"
	@echo "${RED}⠏⢧⠀⠀⠀⠀⠀${BLUE}⠀⠻⣾⣄⠀⠀⠀⠈⠻⣧⣄⠛⢿⣿${BEIGE}⣿⣯⣄⣀⡀⠀⠉⠛⢦⡀⠀⠀⠀${GREEN}⠈⣿⣲⣼⣮⡟⠀⠀⣿⠇⠀⠀${BLUE}⢠⠃⡇⠀⠈⡇⠸⣿⡆⠹⡆⠀⠀⢸⢦⠀⢻⡄⠀"
	@echo "${RED}⠀⢸⡆⠀⡀⠙⠒⣄${BLUE}⣀⣌⣿⠇⠀⠀⠀⠀⠈⠛⢷⣄⠙⠻⣿${BEIGE}⠀⠀⠈⠁⠀⠀⠀⢻⡀⠀⠀⢄⠸${GREEN}⣟⣟⣧⠀⠀⠀⣿⠀⠀${BLUE}⢠⠋⠀⠀⠀⠀⠃⢀⣽⣿⡀⢿⡀⠀⠈⡄⠳⡌⢷⡀"
	@echo "${RED}⣧⠀⢹⡀⠈⠑⠀${BLUE}⣻⣾⡟⠋⠀⢠⡞⡟⢦⡀⠀⢀⣹⣿⣤⣄⠙⠶⣄${BEIGE}⠀⠀⠀⠀⠀⠙⣄⡀⡈⡄⢸${GREEN}⣿⡟⢳⡄⠈⡟⠀${BLUE}⢀⠋⠀⡀⠀⠀⠀⢣⢿⡎⢹⣧⠀⣧⡀⠀⠙⣆⠀⠘⣧"
	@echo "${RED}⣉⣠⠞⠁⣶⢤⠀${BLUE}⠙⣯⣧⠀⢀⣸⣿⣜⠛⣿⠛⠉⠀⠉⣿⡏⠛⠛⠾⢹⡦${BEIGE}⠀⠀⠀⠀⣿⡘⡱⣻${GREEN}⣿⢟⢷⡄⢳⣾⡇⠀⠈${BLUE}⡤⠎⠀⠀⢀⣼⣣⠿⠀⠈⣿⣦⠿⠻⡖⣄⠸⡼⡄⠸"
	@echo "${RED}⠙⠁⠀⠀⣿⣎⣦⠀${BLUE}⠻⡾⡏⠀⠀⠙⠻⠿⠟⠀⠀⠀⢠⡿⠀⠀⠀⢀⣾⠇${BEIGE}⠀⠀⢀⡴⠃⢛⣽⢻⠇${GREEN}⠀⣞⣿⡾⡾${BLUE}⠀⠀⠛⠀⠀⠀⣠⣞⡝⠃⢀⠀⢸⣿⣿⡀⠀⠻⣯⠀⢳⣱⡄"
	@echo "${RED}⠀⠀⠀⠀⣿⢻⡙⡆⠀${BLUE}⢿⡼⣆⣠⣠⣄⠀⠀⠀⠀⣠⡿⠀⠀⠀⢨⣿⠏${BEIGE}⠀⠠⠔⠋⢀⣴⡿⠻⠋${GREEN}⠀⣠⣼⣟⡿⠁${BLUE}⠀⡠⠀⠀⢀⣴⣻⠟⠀⠀⢸⢀⣾⡛⣧⣷⠀⠀⢻⡄⠘⡿⠁"
	@echo "${RED}⠀⠀⠀⠀⣽⠀⠓⢿⡄${BLUE}⠈⣿⣿⣿⣿⠎⠀⠀⠀⣰⡿⠀⠀⠀⣨⣿⠇${BEIGE}⠐⠀⠀⣀⣴⣿⣋${GREEN}⣴⣷⣷⡾⠛⢩⡇⠀${BLUE}⡠⠞⠀⠀⣴⣿⠾⠁⠀⠀⠀⢈⣾⡟⠁⢹⣯⣧⠀⠀⣷⡼⢁⣶"
	@echo "${RED}⠀⠀⠀⢰⡿⡐⠀⡾⠀⠀${BLUE}⢱⣿⡟⠁⠀⠀⠀⣰⡿⠀⠀⠀⢶⣿⣇${BEIGE}⠀⢀⣴⣾⠋⠉${GREEN}⠀⠀⠀⠉⠁⠀⣀⣼⠗${BLUE}⠋⠀⢀⡠⣞⠟⠉⠀⠀⠀⠀⢨⣾⠟⠁⠀⠀⢿⣿⡆⠀⢹⣇⣾⠏"
	@echo "${RED}⠀⠀⣰⠟⢠⠃⣰⠃⠀${BLUE}⣠⣿⡟⠀⠀⠀⠀⣼⠟⠀⠀⠀⣀⣾⣧${BEIGE}⣿⡿⠟⠉⠈⠀${GREEN}⠀⠀⠀⣀⣤⣶${BLUE}⠿⠟⠉⢀⣀⣴⣿⠞⠁⠀⢀⢀⣠⣠⣶⢿⡏⠀⠀⠀⠀⠘⣿⣿⡀⠈⣿⡏⠀"
	@echo "${RED}⠀⣨⡥⠴⠾⠆⠃⠀${BLUE}⣼⢿⡟⠀⠀⠀⢀⣾⣏⠀⠀⠀⣯⣿⣟${BEIGE}⢏⠁⠈⠀${GREEN}⠀⠠⢤⢴⠒${BLUE}⠉⡿⡟⣀⣠⢴⣾⡻⠿⠊⠀⠀⠀⠀⢀⣠⣾⠟⢡⣾⠁⠀⠀⠀⠀⢠⠟⢿⣷⠴⠻⡇⠀"
	@echo "${RED}⠆⠀⠀⠀⠀⢰⢀${BLUE}⣾⢻⠟⠀⠀⠀⢀⡾⡿⠋⠀⠀⣶⣿⠟${GREEN}⢳⣈⡆⢀⡀⠀⠀⠀⣈${BLUE}⣀⣴⣷⠿⠿⠚⠉⠀⠀⠀⠀⡀⣀⡤⠶⠿⠋⣁⣴⠟⠹⣦⡠⣤⣴⣤⣻⡄⠀⢿⣦⠀⢱⡄"
	@echo "${RED}⠀⠀⠀⠀⢀⣀${BLUE}⣸⣭⠀⠀⠀⠀⣵⣿⡇⠁⢀⠄⣴⠿${GREEN}⢀⣠⣾⣿⣯⣙⣿⣿⠿⠿⡛⠉⠁⠀⠀⠀⠀⠀${BLUE}⣀⣠⡴⠷⠛⡭⢀⣀⣤⡾⠋⠁⢀⡴⢏⣵⣿⣯⣹⣿⠙⣝⣾⣿⡎⠉⠁"
clean:
	@echo "$(RED)Deleting Obj file in $(MLX_PATH)...\n$(NC)"
	@make clean -sC $(MLX_PATH)
	@echo "$(RED)Deleting Obj file in $(LIBFT_PATH)...\n$(NC)"
	@make clean -sC $(LIBFT_PATH)
	@echo "$(RED)Deleting So_long object...\n$(NC)"
	@rm -f $(OBJ)
	@echo "$(GREEN)Done\n$(NC)"

fclean: clean
	@echo "$(RED)Deleting so_long executable...$(NC)"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "$(GREEN)Done\n$(NC)"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀${NC}"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⡖⠊⠉⠁⣿⣿⢀⡤⠔⠉⠁⠀⠈⠉⠒⢤⡀⠀⠀⠀⠀⠀⠀⠀⠀${NC}"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠟⠛⠉⠁⣿⠙⡄⢠⠔⠉⠁⠒⢤⡀⣿⣿⣿⣿⣿⠈⠢⡀⠀⠀⠀⠀⠀⠀${NC}"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⢀⣠⠞⠁⠀⢠⠄⣿⢀⣀⠀⣽⠃⠀⠀⠀⠀⠀⠙⢆⣿⣿⣿⣿⣿⣿⠹⡄⠀⠀⠀⠀⠀${NC}"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⣠⡿⢡⠆⠀⡰⠁⣿⣰⣟⣿⣧⣴⣿⢻⡄⠀⠀⠀⠀⠈⢣⣿⣿⣿⣿⣿⣿⢻⡀⠀⠀⠀⠀${NC}"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⣰⡿⢠⡟⠀⡸⠁⣿⡼⠁⠀⠀⠉⠉⠀⠀⠹⡀⠀⠀⠀⠀⠈⢇⣿⣿⣿⣿⣿⠸⡇⠀⠀⠀⠀${NC}"
	@echo "${YELLOW}⠀⠀⠀⠀⠰⣿⠁⣾⠃⠀⣇⣿⢠⣇⠀⠀⠀⠀⠀⠀⠀⠀⡇⠰⡀⠀⡄⠘⣼⡷⣿⣿⣿⣿⣿⢻⠀⠀⠀⠀${NC}"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠹⣷⣿⡆⠀⣿⣦⡸⡏⠃⠀⠀⠀⠀⠀⠀⠰⣿⢠⠀⠀⡇⠀⢻⣧⡄⣿⣿⣿⣿⢸⠀⠀⠀⠀${NC}"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠈⠉⢻⣶⡿${CYAN}⣿⣻${WHITE}⣧⡀${CYAN}⠀⠀⠀⠀⢀⡀⣀⣧⡈⠀${YELLOW}⠀⡇⠆⢸⣿⠃⠀⠀⠀⠀⡿⠀⠀⠀⠀${NC}"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⡟⡏⠃${CYAN}⣿⣿⣿⠃⠀⠀⠀⠀⠷⢻⠋${WHITE}⣿⣷${YELLOW}⣦⣼⡷⣠⣾⡟⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀${NC}"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⡜⠀${BEIGE}⡇⠀${CYAN}⠘⠃⢃⠀⠀⠀⠀⠀⠀⣾⣿⣿⡿${BEIGE}${YELLOW}⢹⣯⢹⠋⠉⣻⣄⠀⠀⠀⢠⠁⠀⠀⠀⠀${NC}"
	@echo "${YELLOW}⠀⠀⠀⠀⠀⢀⠞⠀⠰${BEIGE}⡇⠀⠀⠀⠏⠀⠀⠀⠀⠀⠀${CYAN}⠘⠛⠛⠁⠘${YELLOW}⠓⡸⠀⢠⠏${BEIGE}⣋⡉⢙⠒⢺⢖⡦⠤⣀⡀${NC}"
	@echo "${YELLOW}⠀⠀⠀⠀⢠⠎⠀⠀⡜${BEIGE}⢣⠀⠀⠀⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀${YELLOW}⢀⠇⠀⡸⠀${BEIGE}⠈⣀⣻⡦⢤⣀⡠⠤⠟⠃${NC}"
	@echo "${YELLOW}⠀⠀⠀⢠⠋⠀⢀⠞⠀⠀${BEIGE}⣳⣄⠀⠀${RED}⠈⠉⠉⠉${YELLOW}⠀⠀⠀⠀⠀⠀⣀⡎⠀⢠⣧${BEIGE}⠀⣤⡬⠄⠒⠉${YELLOW}⣯⠀⠀⠀⠀⠀${NC}"
	@echo "${YELLOW}⠀⠀⣠⠃⠀⡰⠃⠀${GREEN}⢀⡔⣻⣏${BEIGE}⠳⢄⡀⠀⠀⠀⠀⢀⣀⣤⠔⠚${YELLOW}⠀⡿⠀⠀⡼⢀⣟⠀⠀⠀⠀${YELLOW}⢸⠀⠀⠀⠀⠀${NC}"
	@echo "${YELLOW}⠀⢰⠃⢀⣾⠃⠀⠀${GREEN}⠈⠉⠑⠚⠂${BEIGE}⠀⠉⠓⢶⣾⣿⡿⠟⠁⠀${YELLOW}⠀⡰⠁⠀⡰${GREEN}⢁⣞⡺⢦⡀⠀⠀${YELLOW}⠸⡄⠀⠀⠀⠀${NC}"
	@echo "${YELLOW}⢠⠇⢀⢊⠇⠀⠀${BEIGE}⠀⠀⢀⠠⠤⠄⣀⠀⠀⣤⣾⠋⠉⠀⠀⠀${YELLOW}⠀⡰⠃${GREEN}⢀⣴⠃⠛⠚⠉⠉⠁⠀${YELLOW}⠀⠀⢣⠀⠀⠀⠀${NC}"
	@echo "${YELLOW}⡞⢀⡎⡜⠀⠀${BEIGE}⢠⠊⠀⠀⠀⠀⠀⠉⢹⣿⡇⠀⠀⠀⢀${YELLOW}⠀⡜⠁⢠${BEIGE}⢿⣿⡇⠀⠀⠀⠀⠀⠀${YELLOW}⠀⠀⠘⡄⠀⠀⠀${NC}"
	@echo "${YELLOW}⡇⣼⣰⠃⠀${BEIGE}⢠⡇⠀⠀⠀⠢⣀⠀⠀⠀⠙⢻⣷⣤⣤${YELLOW}⠀⠊⠀${BEIGE}⣴⣿⡿⠋⠑⠤⣀⠀⠀⠀${YELLOW}⠀⠀⠀⠀⢳⠀⠀⠀${NC}"
	@echo "${YELLOW}⣷⡟⡟⠀⠀${BEIGE}⢸⡇⠀⢀⡼⠃⠈⠑⢄⠀⠀⠀${YELLOW}⠀⢀⠽⣁${BEIGE}⠴⠚⠉⠁⠀⠀⠀⠀⠀⠉⠓⠦⣄${YELLOW}⠀⠀⠠⠈⡆⠀⠀${NC}"
	@echo "${YELLOW}⠘⣇⡇⠀⠀${BEIGE}⢸⣇⡴⠋⠀⠀⠀⠀⠀⠀⠀${BEIGE}⢀⣴⡯⠚⠁⠀⠈⠉⠉⠉⠒⠒⠒⠒⠒⠒⠀⠈⢣${YELLOW}⠀⠀⢱⢻⠀⠀${NC}"
	@echo "${YELLOW}⠀⢸⠃⠀⠀${WHITE}⢸⠏⠉⠒⠤⡀⠀⠀⠀⠀${BEIGE}⢠⣾⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀${YELLOW}⠀⠀⢿⡆⠀${NC}"
	@echo "${YELLOW}⠀⢸⡆⠀⠀${WHITE}⡇⠀⠀⠀⠀⠈⠳⣄⠀${BEIGE}⣠⡿⠁⠀⠀${WHITE}⢀⣀⣀⣀⣀${BEIGE}⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀${YELLOW}⠘⣷⠀${NC}"
	@echo "${YELLOW}⠀⠀⣇⠀⠀${WHITE}⣧⠀⠀⠀⠀⠀⠀⠀⣽⡏⠉⠉⠉⠁⠀⠀⠀⠀⠉⠉⠒⠢⣤⠀${BEIGE}⠀⠀⢀⡞⠀⠀⠀⠀${YELLOW}⣿⠀${NC}"
	@echo "${YELLOW}⠀⠀⠸⣿⡄${WHITE}⢸⡆⠀⠀⠀⠀⠀⠀⢹⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡜⠀${BEIGE}⠀⠀⠀⡼⠁⠀⠀⠀${YELLOW}⢠⣿⠀${NC}"
	@echo "${YELLOW}⠀⠀⠀⢻⡘⢄${WHITE}⣳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡰⠁⠀${BEIGE}⠀⠀⣰⠃⠀⠀⠀${YELLOW}⢀⣮⡟⠀${NC}"

re: fclean all

.PHONY: all clean fclean re lib mlx
