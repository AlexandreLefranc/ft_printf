# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 23:07:15 by alefranc          #+#    #+#              #
#    Updated: 2021/12/05 23:32:25 by alefranc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFTDIR = libft/
LIBFT = libft.a
SRC =   ft_printf.c \
		ft_putarg_size.c \
		ft_putnbr_size.c \
		ft_putstr_size.c \
		ft_putptr_puthexa_putunsigned_size.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFTDIR)$(LIBFT) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(LIBFTDIR)$(LIBFT):
	make -C $(LIBFTDIR) bonus

%.o: %.c libftprintf.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
