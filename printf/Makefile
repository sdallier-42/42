# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 17:13:37 by sdallier          #+#    #+#              #
#    Updated: 2025/11/20 13:03:32 by sdallier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
CC = gcc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
RN = ranlib
LIBFT = libft

SRC_FILES =	ft_print_char.c \
			ft_print_hex.c \
			ft_print_int.c \
			ft_print_pointer.c \
			ft_print_string.c \
			ft_print_unsigned.c \
			ft_printf.c

OBJ	= $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	make -C $(LIBFT)
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

%.o: %.c libft.h ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/libft.a

re: fclean all


