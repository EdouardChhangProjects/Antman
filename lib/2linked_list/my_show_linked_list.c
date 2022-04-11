/*
** EPITECH PROJECT, 2021
** libmy.a function
** File description:
** shows content of a linked list
*/

#include <unistd.h>
#include "my_linked_list.h"

void my_printf(char *str, ...);

static int data_printer(linked_list_t *node)
{
    if (node->data != NULL)
        my_printf("data = %i, ", DATA(node));
    else
        my_printf("data = (nil), ");
    if (node->next == NULL)
        my_printf("next = NULL, ");
    else
        if (node->next->data != NULL)
            my_printf("next.data = %i, ", DATA(node));
        else
            my_printf("next.data = (nil), ");
    if (node->next == NULL)
        my_printf("next = NULL, ");
    else
        if (node->prev->data != NULL)
            my_printf("prev.data = %i\n", DATA(node));
        else
            my_printf("prev.data = (nil)\n");
}

void my_show_linked_list(linked_list_t *l)
{
    const void *first = l;

    if (l == NULL)
        return my_printf("NULL\n");
    while (l->next != first) {
        data_printer(l);
        l = l->next;
    }
    data_printer(l);
    l = l->next;
}
