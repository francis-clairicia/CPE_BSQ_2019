##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

MAIN	=	main.c

SRC	=	src/bsq.c			\
		src/check_error.c		\
		src/find_biggest_square.c	\
		src/find_square.c		\
		src/fill_biggest_square.c

CFLAGS	=	-I./include/ -Wall -Wextra -Werror

OBJ	=	$(MAIN:.c=.o) $(SRC:.c=.o)

NAME	=	bsq

all:	$(NAME)

lib:
	make -s -C ./lib/my

$(NAME):	lib $(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib -lmy
	rm -f $(OBJ)

build_test:	lib
	@find . -name "*.gc*" -delete
	gcc -o unit_tests $(SRC) tests/*.c -L./lib -lmy $(CFLAGS) --coverage -lcriterion
	./unit_tests
	mkdir -p coverage
	mv *.gc* coverage/

tests_run:	build_test clean

debug:	lib
	gcc -g -o $(NAME) $(MAIN) $(SRC) $(CFLAGS) -L./lib -lmy

clean:
	rm -f $(OBJ)
	rm -f unit_tests test*.gc*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all lib tests_run build_test debug clean fclean re
