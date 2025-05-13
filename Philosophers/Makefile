# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Sources and objects
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Output program name
NAME = philo

# Default rule
all: $(NAME)

# Linking the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Compiling source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up object files and executable
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
