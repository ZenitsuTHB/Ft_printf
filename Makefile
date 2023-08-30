# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 18:32:47 by avolcy            #+#    #+#              #
#    Updated: 2023/07/31 15:35:08 by avolcy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variable que contiene el nombre de la biblio estatica
NAME = libftprintf.a
CC = cc #var. con opcion de compilacion
CFLAGS = -Wall -Wextra -Werror -I. #opciones de compilacion adicionales
HEADER = ft_printf.h
#variable que contiene la lista de archivos fuente que se deben compilar
SRC = ft_print_char.c ft_print_unsigned.c ft_printf.c ft_print_string.c \
	  ft_itoa.c ft_print_nbr.c ft_print_hexadec.c ft_print_ptr.c 
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

.PHONY : clean fclean re all

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
