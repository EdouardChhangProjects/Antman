/*
** EPITECH PROJECT, 2022
** antman2
** File description:
** add_node
*/

#include <stddef.h>
#include <stdlib.h>

#include "my_linked_list.h"

int second_node(void *data, linked_list_t **list)
{
    linked_list_t *dest = malloc(sizeof(linked_list_t));

    if (dest == NULL)
        return 84;
    dest->data = data;
    dest->next = (*list);
    dest->prev = (*list);
    (*list)->next = dest;
    (*list)->prev = dest;
    (*list) = dest;
    return 0;
}

int add_node(void *data, linked_list_t **list)
{
    linked_list_t *dest = NULL;

    if (list == NULL)
        return 84;
    if ((*list) == NULL) {
        *list = first_node(data);
        return 0;
    }
    if ((*list)->next == (*list))
        return second_node(data, list);
    if ((dest = malloc(sizeof(linked_list_t))) == NULL)
        return 84;
    dest->data = data;
    (*list)->prev->next = dest;
    dest->prev = (*list)->prev;
    (*list)->prev = dest;
    dest->next = (*list);
    (*list) = dest;
    return 0;
}

int add_end_node(void *data, linked_list_t **list)
{
    if (list == NULL)
        return 84;
    if ((*list) == NULL) {
        (*list) = first_node(data);
        return 0;
    }
    if ((*list)->next == (*list)) {
        if (second_node(data, list) == 84)
            return 84;
        *list = (*list)->next;
        return 0;
    }
    add_node(data, list);
    *list = (*list)->next;
    return 0;
}
