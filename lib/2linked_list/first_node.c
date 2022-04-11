/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** empty_list
*/

#include "my_linked_list.h"
#include <stddef.h>
#include <stdlib.h>

void *my_memset(int size, char *str);

linked_list_t *first_node(void *data)
{
    linked_list_t *dest = malloc(sizeof(linked_list_t));

    if (dest == NULL)
        return NULL;
    dest->next = dest;
    dest->prev = dest;
    dest->data = data;
    return dest;
}
