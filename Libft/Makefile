# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sholz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 13:52:52 by sholz             #+#    #+#              #
#    Updated: 2024/10/28 13:52:53 by sholz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rc
RANLIB  = ranlib

NAME    = libft.a
HEAD    = libft.h
SRCS    = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isprint.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c \
ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
ft_tolower.c ft_toupper.c

OBJS    = $(SRCS:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME):
		@$(CC) $(CFLAGS) -c $(SRCS)
		@$(AR) $(NAME) $(OBJS)
		@$(RANLIB) $(NAME)
		@echo "[INFO] Library [$(NAME)] created!"

clean:
		@rm -f $(OBJS)
		@echo "[INFO] Objects removed!"

fclean: clean
		@rm -f $(NAME)
		@echo "[INFO] Library [$(NAME)] removed!"

re:		fclean all
