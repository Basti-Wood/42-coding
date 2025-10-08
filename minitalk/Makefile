# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Source files
SRC_CLIENT = client.c
SRC_SERVER = server.c

# Object files
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

# Output binaries
NAME_CLIENT = client
NAME_SERVER = server

# Default target: build both client and server
all: $(NAME_CLIENT) $(NAME_SERVER)

# Client
$(NAME_CLIENT): $(OBJ_CLIENT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(PRINTF)

# Server
$(NAME_SERVER): $(OBJ_SERVER) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) $(PRINTF)

# Compile the client and server source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build printf (if not already compiled)
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)  # Ensure ft_printf is compiled

# Clean object files and binaries
clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	$(MAKE) clean -C $(PRINTF_DIR)

# Clean everything (binaries and objects)
fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	$(MAKE) fclean -C $(PRINTF_DIR)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re

