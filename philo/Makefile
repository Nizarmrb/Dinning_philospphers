# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 21:33:08 by nelmrabe          #+#    #+#              #
#    Updated: 2023/11/06 21:19:27 by nelmrabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRCS = philo.c parsing.c routine.c init.c print.c finish.c

OBJS = $(SRCS:c=o)

all: $(NAME) 

$(NAME): $(OBJS) philo.h
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re 