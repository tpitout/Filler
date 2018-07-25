# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpitout <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/11 10:00:13 by tpitout           #+#    #+#              #
#    Updated: 2018/07/20 13:20:59 by tpitout          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tredx.filler
CC = gcc -o
CFLAGS = -Wall -Wextra -Werror
SRCS = ./srcs/*.c
INC = -I ./includes/
OBJS = *.o
MAKE = make -C ./libft/
RM = rm -rf

all:
	@$(MAKE)
	@mv ./libft/libft.a .
	@$(CC) $(NAME) $(CFLAFS) $(SRCS) $(INC) libft.a

clean:
	@make clean -C ./libft/
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C ./libft/
	@$(RM) libft.a
	@$(RM) $(NAME)

re: fclean all
