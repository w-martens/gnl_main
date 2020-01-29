# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: wmartens <wmartens@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/06 17:49:19 by wmartens       #+#    #+#                 #
#    Updated: 2020/01/28 13:59:04 by wmartens      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
HEAD = get_next_line.h

SRC = 	get_next_line.c\
		get_next_line_utils.c\
		testy.c\

all: $(NAME)

$(NAME):
	gcc -g -Wall -Wextra -Werror $(SRC) -o $(NAME) $(HEAD) -fsanitize=address

clean:
	rm -f $(NAME)

dbclean:
	rm -r get_next_line.dSYM

runno:
	./get_next_line

re: clean all

run: clean all runno

debuggo:
	gcc -g -Wall -Wextra -Werror $(SRC) -o $(NAME) $(HEAD)

debug: clean dbclean debuggo