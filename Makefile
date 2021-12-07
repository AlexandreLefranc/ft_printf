# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 23:07:15 by alefranc          #+#    #+#              #
#    Updated: 2021/12/07 12:47:29 by alefranc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang
INCLUDES = includes
FLAGS = -Wall -Wextra -Werror -I$(INCLUDES)
LIBFTDIR = libft/
LIBFT = libft.a

SRCDIR = src/
SRCFILES =	ft_printf.c \
			ft_putarg_size.c \
			ft_putnbr_size.c \
			ft_putstr_size.c \
			ft_putptr_puthexa_putunsigned_size.c
SRC = $(addprefix $(SRCDIR), $(SRCFILES))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTDIR)
	mv $(LIBFTDIR)$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make -C $(LIBFTDIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
