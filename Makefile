##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC    =    main.c \
	    particule.c \


OBJ    =    $(SRC:.c=.o)

NAME    =    navy

CFLAGS    =     -L lib/ -I /lib/include -I include -lm -lmy

#LDLIBS    =    -lmy

NEWLIB    =    -fsanitize=address

all:     $(NAME)

$(NAME):	$(OBJ)
	@make -C lib
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -Wall
	echo -e "compilation complite"

valgrind:
	@make -C lib
	gcc src/*.c -g3

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:		clean
	make fclean -C lib
	rm -f $(NAME)

allclean: fclean
	rm -f $(USE)

re:	fclean	all

test_build:
	gcc $(TEST) -o unit_test --coverage -lcriterion -Wall

test_clean:
	rm -f *.gcno
	rm -f *.o
	rm -f *.gcda
	rm unit_test

test_run: test_build
	./unit_test
	make test_clean
