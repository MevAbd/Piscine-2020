# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malbrand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 13:12:11 by malbrand          #+#    #+#              #
#    Updated: 2020/10/27 13:57:19 by malbrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET=libft.a
C_FILES=$(addprefix srcs/, ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c)
O_FILES=$(C_FILES:.c=.o)
HEADERS=includes
FLAGS=-Wall -Wextra -Werror

all: $(TARGET)

$(TARGET): $(O_FILES)
	ar -rc $(TARGET) $(O_FILES)
	ranlib $(TARGET)

$(O_FILES): %.o: %.c
	gcc $(FLAGS) -c $< -o $@ -I$(HEADERS)

clean:
	rm $(O_FILES)

fclean: clean
	rm $(TARGET)

re: fclean all
