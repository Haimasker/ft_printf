# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumfred <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 10:25:18 by lumfred           #+#    #+#              #
#    Updated: 2021/10/31 14:21:16 by lumfred          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAG = -Wall -Wextra -Werror
 
HEADER = ft_printf.h

SRC = process.c \
		flags.c \
		funcs.c \
		put.c \
		ft_printf.c

OBJ = $(SRC:.c=.o)

CC := gcc

all: $(NAME) 

$(NAME): $(OBJ) $(HEADER)
	@$(MAKE) -C libft
	@cp libft/libft.a $(NAME)
	@$(CC) $(FLAG) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo printf compiled

bonus: all

clean:
	@$(MAKE) clean -C ./libft
	@rm -f $(OBJ)
	@echo printf files cleaned

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)
	@echo printf cleaned

re: fclean all
 
.PHONY: re, clean, fclean, all, bonus