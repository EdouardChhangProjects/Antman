/*
** EPITECH PROJECT, 2021
** libmy.a
** File description:
** puts params into linked list
*/

#include "my_linked_list.h"
#include <stdlib.h>

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *ptr = NULL;
    linked_list_t *cur_element = malloc(sizeof(linked_list_t));
    linked_list_t *first_element = cur_element;

    if (av == NULL || cur_element == NULL)
        return (NULL);
    cur_element->data = av[0];
    cur_element->next = NULL;
    for (int i = 1; i < ac; i++) {
        ptr = cur_element;
        cur_element = malloc(sizeof(linked_list_t));
        if (cur_element == NULL)
            return (NULL);
        cur_element->data = av[i];
        cur_element->next = ptr;
        cur_element->next->prev = cur_element;
    }
    cur_element->prev = first_element;
    first_element->next = cur_element;
    return (cur_element);
}
