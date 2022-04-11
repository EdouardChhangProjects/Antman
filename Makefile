##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC    =		antman/antman.c					\
				antman/sort.c 					\
				antman/bwdt.c					\
				antman/run_length_encoding.c	\

SRC_GIANT	=	giantman/giantman.c				\
				giantman/main.c					\
				giantman/run_length_decoding.c	\
				giantman/bwt_decode.c 			\
				giantman/sort_chars.c			\

TEST_SRC    =

TEST_OBJ    =    $(TEST_SRC:.c=.o)

OBJ    =    $(SRC:.c=.o)

OBJ_GIANT    =    $(SRC_GIANT:.c=.o)

LDLIB    =    -lmy2ll
LIBMY    = 	   lib/libmy2ll.a

CPPFLAGS    += -I ./include
CFLAGS        +=
LDFLAGS        += -L ./lib/ -lmy2ll

all:	antman giantman

antman:
	make -C ./antman
	mv antman/antman ant

giantman:
	make -C ./giantman
	mv giantman/giantman giant

$(LIBMY):
	make -C lib/2linked_list/

unit_tests:    fclean
unit_tests:    $(LIBMY)
unit_tests:    CFLAGS    += --coverage
unit_tests:    LDFLAGS    += --coverage -lcriterion
unit_tests:		$(TEST_OBJ) $(OBJ)
	gcc -o $@ $(TEST_OBJ) $(OBJ) $(LIB) $(LDFLAGS)
	./$@

debug:	CPPFLAGS += -g
debug:	NAME = debug
debug:
	all
	valgrind ./debug

gcovr:
	gcovr --exclude tests
	gcovr --exclude tests --branches

clean:
	make clean -C ./lib/2linked_list/
	make clean -C ./antman
	make clean -C ./giantman
	rm -f ant
	rm -f giant
	rm -f $(OBJ) $(MAIN_OBJ) $(OBJ_GIANT)
	rm -f $(TEST_OBJ)

fclean: clean
	make fclean -C ./lib/2linked_list/
	make fclean -C ./antman
	make fclean -C ./giantman
	rm -f unit_tests
	rm -f $(TEST_OBJ)
	rm -f *.gc*

re:	fclean all

.PHONY:	all clean fclean re debug antman giantman
