# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malbrand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 17:52:43 by malbrand          #+#    #+#              #
#    Updated: 2020/10/28 18:21:07 by malbrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= srcs/do_op.c    srcs/ft_putchar.c 

OBJS		= ${SRCS:.c=.o}

NAME		= do-op

CFLAGS		= -Wall -Wextra -Werror

DIR			= srcs/

COMMAND		= gcc

RM			= rm -f

.c.o:
	$(COMMAND) $(CFLAGS) -I./ft.h -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${COMMAND} ${CFLAGS} ${SRCS} -o ${NAME}

all: ${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY: all clean fclean re
