/*
** EPITECH PROJECT, 2022
** antman2
** File description:
** list_to_array
*/

#include <stdlib.h>

#include "my_linked_list.h"

void **list_to_array(linked_list_t *list)
{
    int size = my_list_size(list);
    void **data = malloc(sizeof(void *) * (size + 1));

    for (int i = 0; i < size; i++) {
        data[i] = list->data;
        list = list->next;
    }
    data[size] = NULL;
    return data;
}
