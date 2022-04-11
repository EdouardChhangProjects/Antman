/*
** EPITECH PROJECT, 2021
** libmyll.a
** File description:
** rev linked list
*/

#include "my_linked_list.h"
#include <stddef.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *current = *begin;
    linked_list_t *tmp = NULL;
    linked_list_t *first = current;

    while (first->next != current) {
        tmp = current->next;
        current->next = current->prev;
        current->prev = tmp;
        current = tmp;
    }
    tmp = current->next;
    current->next = current->prev;
    current->prev = tmp;
    *begin = tmp->next;
}

/*         tmp = current->next;
        current->next = current->prev;
        current->prev = tmp;
        current = tmp; */
