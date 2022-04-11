/*
** EPITECH PROJECT, 2022
** antman2
** File description:
** sort_chars
*/

#include <stddef.h>

int swap(char *ptr_a, char *ptr_b)
{
    char tmp = *ptr_a;

    *ptr_a = *ptr_b;
    *ptr_b = tmp;
    return 0;
}

int charcmp(char a, char b)
{
    return a - b;
}

int sort_char(char *array, int (*cmp)(char, char))
{
    int curr = 0;

    if (cmp == NULL)
        cmp = charcmp;
    if (array == NULL || array[0] == '\0')
        return 84;
    for (int i = 1; array[i] != '\0'; i++) {
        curr = i;
        while (curr >= 1 && cmp(array[curr - 1], array[curr]) > 0) {
            swap(&array[curr], &array[curr - 1]);
            curr -= 1;
        }
    }
    return 0;
}
