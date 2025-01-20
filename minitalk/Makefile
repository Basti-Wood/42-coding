# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source files
SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_BONUS = _bonus.c  # Assuming the bonus source file

# Object files
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)  # Assuming the bonus object file

# Output binaries
NAME_CLIENT = client
NAME_SERVER = server

# Rules

# Default target: build both client and server
all: $(NAME_CLIENT) $(NAME_SERVER)

# Client
$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIBFT)

# Server
$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) $(LIBFT)

# Bonus: Adds bonus source files if present
bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT)_bonus $(OBJ_CLIENT) $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_SERVER)_bonus $(OBJ_SERVER) $(OBJ_BONUS) $(LIBFT)

# Compile the client and server source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Library (build it if not already compiled)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Clean object files and binaries
clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_BONUS)
	$(MAKE) clean -C $(LIBFT_DIR)

# Clean everything (binaries and objects)
fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT)_bonus $(NAME_SERVER)_bonus

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus
