# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nraymond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 16:14:19 by nraymond          #+#    #+#              #
#    Updated: 2023/12/16 20:17:39 by nraymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

INCL=ft_printf.h\
     #ft_printf_bonus.h

SRCS=ft_printf.c

#SRCS_B=

OBJ = $(SRCS:.c=.o)

#OBJ_B=$(SRCS_B:.c=.o)

CFLAGS=-Werror -Wextra -Wall -I .

CC=cc

all: $(NAME)

$(NAME): $(OBJ) $(INCL) Makefile
	ar -rcs $(NAME) $(OBJ)

%.o : %.c $(INCL) Makefile
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
