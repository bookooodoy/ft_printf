# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nraymond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 03:29:37 by nraymond          #+#    #+#              #
#    Updated: 2023/12/18 20:30:05 by nraymond         ###   ########.fr        #
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
     headers/libft.h\

SRCS=ft_printf.c\
     ft_parse.c\
     ft_writechars.c\
     convert_p.c\
     convert_c.c\
     convert_s.c\
     convert_x.c\
     convert_integers.c\
     init_prt_func.c\
     convert_precision_buff.c\
     convert_fwidth_buff.c\
     append_flags.c

OBJ=$(SRCS:.c=.o)

LIBFT_DIR = headers/

LIBFT=$(LIBFT_DIR)libft.a

GCH=$(LIBFT_DIR)libft.h.gch\
    $(LIBFT_DIR)ft_printf.h.gch\

CFLAGS=-Werror -Wextra -Wall -I . -I $(LIBFT_DIR) 

CC=cc

all: $(NAME)

$(NAME): $(OBJ) $(INCL) Makefile $(LIBFT)
	@echo "$(BOLD)$(CYAN)Executing all...$(RESET)"
	@echo "$(BOLD)$(BLUE)Creating library...$(RESET)\n"
	ar -rcs $(NAME) $(OBJ) $(LIBFT)
	@echo "$(BOLD)$(GREEN)Done.$(RESET)\n"

$(LIBFT):
	@echo "libft.a is already in headers/"

%.o : %.c $(INCL) Makefile
	@echo "\n$(BLUE)Compiling object...$(RESET)\n"
	$(CC) -o $@ -c $< $(CFLAGS)

compile: 
	@echo "$(BOLD)$(CYAN)Compiling...$(RESET)"
	$(CC) $(CLFAGS) -g3 $(SRCS) $(INCL) $(LIBFT)
	@echo "$(BOLD)$(MAGENTA)Done.$(RESET)\n"

clean:
	@echo "$(BOLD)$(CYAN)Executing clean...$(RESET)"
	@echo "\n$(BOLD)$(RED)Deleting object files...$(RESET)\n"
	$(RM) -f $(OBJ)
	@echo "$(BOLD)$(MAGENTA)Done.$(RESET)\n"

fclean: clean
	@echo "$(BOLD)$(CYAN)Executing fclean...$(RESET)"
	@echo "\n$(BOLD)$(RED)Deleting the library... $(RESET)\n"
	$(RM) -f $(NAME)
	@echo "\n$(BOLD)$(YELLOW)Deleting .gch header files...$(RESET)\n"
	$(RM) -f $(GCH)
	@echo "$(BOLD)$(MAGENTA)Done.$(RESET)\n"
	@echo "\n$(BOLD)$(YELLOW)Deleting executable...$(RESET)\n"
	$(RM) -f a.out
	@echo "$(BOLD)$(MAGENTA)Done.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re

