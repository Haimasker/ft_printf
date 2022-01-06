NAME = libft.a

FLAG = -Wall -Wextra -Werror
 
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c ft_strlen.c \
	ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c \
	ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c
 
OBJ = $(SRC:.c=.o)

CC := gcc
 
BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c	
 
BONUS_OBJ = $(BONUS_SRC:.c=.o)
 
all: $(NAME) 

$(NAME): $(OBJ)
	@$(CC) $(FLAG) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo mandatory part compiled
 
 
bonus: $(NAME)
	@$(CC) $(FLAG) -c $(BONUS_SRC)
	@ar rc $(NAME) $(BONUS_OBJ)
	@ranlib $(NAME)
	@echo bonus part compiled
 
clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo object files cleaned
 
fclean: clean
	@rm -f $(NAME)
	@echo $(NAME) cleaned
 
re: fclean all
 
.PHONY: re, clean, fclean, all, bonus
