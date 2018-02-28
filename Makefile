# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cormarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 23:00:19 by cormarti          #+#    #+#              #
#    Updated: 2018/02/28 13:30:00 by cormarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIB = libft/libft.a
FLAGS = -Wall -Wextra -Werror
SRCS = arg_parser.c extract.c long_display.c long_display2.c printers.c \
	   lists.c long_display3.c errors.c file_process.c sorting.c recursive.c \
	   ft_ls.c dir_process.c printers2.c structs.c valid_path.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
		@$(MAKE) -C libft/ re
		@gcc $(FLAGS) $(SRCS) $(LIB) -o $(NAME)

clean: 
		@$(MAKE) -C libft/ clean
		@/bin/rm -rf $(OBJ)

fclean: clean
		@$(MAKE) -C libft/ fclean
		@/bin/rm -rf $(NAME)

re: fclean all
