/*
** EPITECH PROJECT, 2022
** antman2
** File description:
** my_tab_size
*/

#include <stddef.h>

int my_tab_size(void **tab)
{
    int count = 0;

    if (tab == NULL)
        return -1;
    for (int i = 0; tab[i] != NULL; i++)
        count++;
    return count;
}
