##
## EPITECH PROJECT, 2021
## cpoolday10 task01
## File description:
## Makefile
##

SRC =	my_list_size.c 			\
		my_params_to_list.c 	\
		my_rev_list.c 			\
		my_show_linked_list.c 	\
		delete_node.c 			\
		destroy_list.c 			\
		first_node.c 			\
		add_node.c 				\
		list_to_array.c 		\

OBJ	=		$(SRC:.c=.o)

NAME =		lib2linkedlist.a

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ../my/
	ar rc -o $(NAME) $(OBJ)
	ar -q ../libmy.a $(NAME) $(OBJ)
	mv ../libmy.a ../libmy2ll.a
	cp my_linked_list.h ../../include/

clean:
	make clean -C ../my/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ../my/
	rm -f ../libmy2ll.a
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
