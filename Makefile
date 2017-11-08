# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:13:32 by ccazuc            #+#    #+#              #
#    Updated: 2017/11/08 16:27:38 by ccazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C=gcc

CFLAGS=-Wall -Werror -Wextra

EXEC=fillit

SRC=main.c parser.c check_piece.c libft.a -Iincludes

OBJ=$(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
		$(CC) -o $@ $^

%.o: %.c
		@$(CC) -o $@ -c $< $(CFLAGS)

fclean:
	rm -rf $(EXEC)

clean:
		rm -rf *.o

re: clean fclean all
