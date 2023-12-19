# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nraymond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 03:29:37 by nraymond          #+#    #+#              #
#    Updated: 2023/12/19 18:45:27 by nraymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color codes
RESET   = \033[0m
BOLD    = \033[1m
RED     = \033[31m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
MAGENTA = \033[35m
CYAN    = \033[36m
WHITE   = \033[37m

NAME=libftprintf.a

INCL=headers/ft_printf.h\

SRCS=src/ft_printf.c\
     src/ft_parse.c\
     src/ft_writechars.c\
     src/convert_p.c\
     src/convert_c.c\
     src/convert_s.c\
     src/convert_x.c\
     src/convert_integers.c\
     src/init_prt_func.c\
     src/convert_precision_buff.c\
     src/convert_fwidth_buff.c\
     src/append_flags.c

LIBFTSRCS = inc/libft/ft_atoi.c\
        inc/libft/ft_isascii.c\
        inc/libft/ft_memcmp.c\
        inc/libft/ft_putendl_fd.c\
        inc/libft/ft_strdup.c\
        inc/libft/ft_strlen.c\
        inc/libft/ft_strtrim.c\
        inc/libft/ft_bzero.c\
        inc/libft/ft_isdigit.c\
        inc/libft/ft_memcpy.c\
        inc/libft/ft_putnbr_fd.c\
	inc/libft/ft_striteri.c\
        inc/libft/ft_strmapi.c\
        inc/libft/ft_substr.c\
        inc/libft/ft_calloc.c\
        inc/libft/ft_isprint.c\
        inc/libft/ft_memmove.c\
        inc/libft/ft_putstr_fd.c\
        inc/libft/ft_strjoin.c\
        inc/libft/ft_strncmp.c\
        inc/libft/ft_tolower.c\
        inc/libft/ft_isalnum.c\
        inc/libft/ft_itoa.c\
        inc/libft/ft_memset.c\
        inc/libft/ft_split.c\
        inc/libft/ft_strlcat.c\
        inc/libft/ft_strnstr.c\
        inc/libft/ft_toupper.c\
        inc/libft/ft_isalpha.c\
        inc/libft/ft_memchr.c\
        inc/libft/ft_putchar_fd.c\
        inc/libft/ft_strchr.c\
        inc/libft/ft_strlcpy.c\
        inc/libft/ft_strrchr.c\

OBJ=$(SRCS:.c=.o)

OBJLIBFT=$(LIBFTSRCS:.c=.o)

LIBFT=inc/libft/

LIBFTA=inc/libft/libft.a

CFLAGS=-Werror -Wextra -Wall -I . 

CC=cc

all: $(NAME)

$(NAME): $(LIBFTA) $(OBJ) $(INCL) Makefile
	@echo "$(BOLD)$(CYAN)Executing all...$(RESET)"
	@echo "$(BOLD)$(BLUE)Creating library...$(RESET)\n"
	ar -rcs $(NAME) $(OBJ) $(LIBFTA)
	@echo "$(BOLD)$(GREEN)Done.$(RESET)\n"

$(LIBFTA):
	$(MAKE) -C $(LIBFT)

%.o : %.c $(INCL) Makefile
	@echo "\n$(BLUE)Compiling object...$(RESET)\n"
	$(CC) -o $@ -c $< $(CFLAGS)

compile: re 
	@echo "$(BOLD)$(CYAN)Compiling...$(RESET)"
	$(CC) $(CLFAGS) -g3 $(SRCS) headers/ft_printf.h $(LIBFTA)
	@echo "$(BOLD)$(MAGENTA)Done.$(RESET)\n"

clean:
	@echo "$(BOLD)$(CYAN)Executing clean...$(RESET)"
	@echo "\n$(BOLD)$(RED)Deleting libftprintf object files...$(RESET)\n"
	$(RM) -f $(OBJ)
	@echo "$(BOLD)$(MAGENTA)Done.$(RESET)\n"
	@echo "\n$(BOLD)$(RED)Deleting libft object files...$(RESET)\n"

fclean: clean
	@echo "$(BOLD)$(CYAN)Executing fclean...$(RESET)"
	@echo "\n$(BOLD)$(RED)Deleting the library... $(RESET)\n"
	$(RM) -f $(NAME)
	@echo "$(BOLD)$(MAGENTA)Done.$(RESET)\n"
	@echo "\n$(BOLD)$(YELLOW)Deleting executable...$(RESET)\n"
	$(RM) -f a.out
	@echo "$(BOLD)$(MAGENTA)Done.$(RESET)\n"
	$(MAKE) fclean -C $(LIBFT) 

re: fclean all

.PHONY: all clean fclean re

