# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:13:32 by ccazuc            #+#    #+#              #
#    Updated: 2017/11/09 09:01:14 by ccazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

CFLAGS=-Wall -Werror -Wextra

EXEC=fillit

SRC=main.c parser.c check_piece.c

OBJ=$(SRC:.c=.o)

all: $(EXEC) libft

$(EXEC): $(OBJ)
		@$(CC) -o $@ $^

%.o: %.c
		@$(CC) -o $@ -c $< $(CFLAGS)

fclean: clean
	rm -rf $(EXEC)

libft:
	libft.a -Iincludes

clean:
		rm -rf *.o

re: fclean all
