# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: wmartens <wmartens@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/06 17:49:19 by wmartens       #+#    #+#                 #
#    Updated: 2020/01/15 12:56:26 by wmartens      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
HEAD = get_next_line.h

SRC = 	get_next_line.c\
		get_next_line_utils.c\
		testy.c\

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRC) -o $(NAME) -I $(HEAD)

clean:
	rm -f $(NAME)

dbclean:
	rm -r get_next_line.dSYM

runno:
	./get_next_line

re: clean all

run: clean all runno

debuggo:
	gcc -g -Wall -Wextra -Werror $(SRC) -o $(NAME) -I $(HEAD)

debug: clean dbclean debuggo