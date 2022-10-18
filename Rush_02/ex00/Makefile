# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 11:49:19 by vismaily          #+#    #+#              #
#    Updated: 2022/10/18 12:51:17 by vismaily         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= rush-02

SRCS		= $(wildcard *.c)

OBJS		= $(SRCS:.c=.o)

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

.c.o:
			@$(CC) $(CFLAGS) -o $(<:.c=.o) -c $<

all:		$(NAME)

$(NAME): 	$(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
