# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sholz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/22 13:45:12 by sholz             #+#    #+#              #
#    Updated: 2025/03/22 13:45:15 by sholz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
BNAME       = checker
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

HFILES      = ./includes/push_swap.h
FT_PRINTF   = ./ft_printf/libftprintf.a
OUTDIR      = ./obj/
INDIR       = ./src/
INSTRDIR    = ./instructions/
SRC         = $(wildcard $(INDIR)*.c) $(wildcard $(INSTRDIR)*.c)
OBJ         = $(SRC:%.c=$(OUTDIR)%.o)

ARGS        = 42 17 8 23 15 6 3 9 12 19

all: $(NAME)

$(NAME): $(OBJ)
	@cd ft_printf && make
	@$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) -o $(NAME)

$(OUTDIR)%.o: %.c $(HFILES)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

leaks:
	@valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --error-limit=no --tool=memcheck -s ./push_swap $(ARGS)

clean:
	@cd ft_printf && make clean
	@rm -rf $(OUTDIR)

fclean: clean
	@cd ft_printf && make fclean
	@rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: all clean fclean re

