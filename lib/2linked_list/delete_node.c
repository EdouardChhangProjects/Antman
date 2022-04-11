/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** delete_node
*/

#include <stddef.h>

#include "my_linked_list.h"

void delete_node(linked_list_t **node)
{
    if ((*node) == NULL || (*node)->next == (*node))
        (*node) = NULL;
    else {
        (*node)->next->prev = (*node)->prev;
        (*node)->prev->next = (*node)->next;
        (*node) = (*node)->next;
    }
}
