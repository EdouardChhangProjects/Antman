/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** destroy_list
*/

#include <stdlib.h>

#include "my_linked_list.h"

void destroy_list(linked_list_t *list)
{
    linked_list_t *first = list;

    while (list->next != first) {
        list = list->next;
        free(list->prev);
    }
    free(list);
}
