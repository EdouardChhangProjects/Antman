/*
** EPITECH PROJECT, 2022
** antman2
** File description:
** run_length_encoding
*/

#include "my.h"
#include "antman.h"
#include "my_linked_list.h"

#include <stddef.h>

char *list_to_chars(linked_list_t *list)
{
    char **tab = (char **)list_to_array(list);

    int size = my_tab_size((void **)tab);
    char *dest = my_memset(sizeof(char) * (size + 1), NULL);

    if (dest == NULL || tab == NULL)
        return NULL;
    for (int i = 0; tab[i] != NULL; i++)
        dest[i] = *(tab[i]);
    return dest;
}

char *run_length_decode(char *str)
{
    unsigned char count = 0;
    char *letter = NULL;
    int index = 0;
    int dest_index = 0;
    linked_list_t *dest = NULL;

    while (index < my_strlen(str)) {
        letter = my_memset(sizeof(int), NULL);
        *letter = str[index++];
        count = 1;
        if (*letter == str[index]) {
            count = str[++index];
            index++;
        }
        for (int i = 0; i < count; i++)
            add_end_node(letter, &dest);
    }
    return list_to_chars(dest);
}
