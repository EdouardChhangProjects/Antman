/*
** EPITECH PROJECT, 2022
** antman2
** File description:
** sort
*/

#include <stddef.h>

int swap(void **ptr_a, void **ptr_b)
{
    void *tmp = *ptr_a;

    *ptr_a = *ptr_b;
    *ptr_b = tmp;
    return 0;
}

void **sort(void **array, int (*cmp)(void *, void *))
{
    int curr = 0;

    if (array == NULL || array[0] == NULL)
        return array;
    for (int i = 1; array[i] != NULL; i++) {
        curr = i;
        while (curr >= 1 && cmp(array[curr - 1], array[curr]) > 0) {
            swap(&array[curr], &array[curr - 1]);
            curr -= 1;
        }
    }
    return array;
}
