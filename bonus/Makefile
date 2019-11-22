##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

MAIN	=	main.c

CSFML	=	csfml/framebuffer.c			\
			csfml/create_window.c		\
			csfml/put_pixel.c			\
			csfml/draw_square.c			\
			csfml/clock.c

SRC 	=	src/bsq.c					\
			src/check_error.c			\
			src/find_biggest_square.c	\
			src/find_square.c			\
			src/free_buffer.c			\
			src/window.c				\
			src/window_square.c

CFLAGS	=	-I./include/ -Wall -Wextra -Werror

OBJ	=	$(MAIN:.c=.o) $(SRC:.c=.o) $(CSFML:.c=.o)

NAME	=	bsq

all:	$(NAME)

lib:
	make -s -C ./lib/my

$(NAME):	lib $(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib -lmy -lcsfml-system -lcsfml-graphics
	rm -f $(OBJ)

tests_run:	lib
	@find . -name "*.gc*" -delete
	gcc -o unit_tests $(SRC) tests/*.c -L./lib -lmy $(CFLAGS) --coverage -lcriterion
	./unit_tests
	mkdir -p coverage
	mv *.gc* coverage/

debug:	lib
	gcc -g -o $(NAME) $(MAIN) $(SRC) $(CFLAGS) -L./lib -lmy

clean:
	rm -f $(OBJ)
	rm -f unit_tests test*.gc*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all lib tests_run debug clean fclean re
