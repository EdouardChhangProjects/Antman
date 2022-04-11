##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC    =		antman.c				\
				sort.c					\
				bwdt.c					\
				run_length_encoding.c	\

TEST_SRC    =

TEST_OBJ    =    $(TEST_SRC:.c=.o)

MAIN_SRC    =   main.c

MAIN_OBJ    =    $(MAIN_SRC:.c=.o)

OBJ    =    $(SRC:.c=.o)

NAME    =    antman

LIBMY    = 	   ../lib/libmy2ll.a

CPPFLAGS    += -I ../include -g
CFLAGS        +=
LDFLAGS        += -L ../lib/ -lmy2ll

all:	$(NAME)

$(NAME):    $(LIBMY) $(OBJ) $(MAIN_OBJ)
	gcc -o $(NAME) $(OBJ) $(MAIN_OBJ) $(LDLIB) $(LDFLAGS) $(CPPFLAGS)

$(LIBMY):
	make -C ../lib/2linked_list/

clean:
	make clean -C ../lib/2linked_list/
	rm -f $(OBJ) $(MAIN_OBJ) $(OBJ_GIANT)
	rm -f $(TEST_OBJ)

fclean: clean
	make fclean -C ../lib/2linked_list/
	rm -f unit_tests
	rm -f $(TEST_OBJ)
	rm -f $(NAME)
	rm -f *.gc*

re:	fclean all

.PHONY:	all clean fclean re antman
