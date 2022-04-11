/*
** EPITECH PROJECT, 2022
** antman2
** File description:
** bwt_decode
*/

#include <stddef.h>

#include "my.h"
#include "antman.h"
#include "my_linked_list.h"

char *my_itoa(int n)
{
    int m = n;
    char *c;
    int i = 0;

    if (n == 0)
        return my_memset(sizeof(char) * 2, "0");
    for (; n != 0; i++)
        n /= 10;
    c = my_memset(sizeof(char) * (i + 2), NULL);
    if (c == NULL)
        return NULL;
    for (i = 0; m != 0; m /= 10)
        c[i++] = (m % 10) + 48;
    c[i] = '\0';
    return (c);
}

int *init_index_loop(char *str)
{
    int len = my_strlen(str);
    int *dest = my_memset(sizeof(int) * (len), NULL);
    unsigned char *sorted = my_memset(sizeof(char) * (len + 1), str);
    linked_list_t *array[256] = {NULL};
    int *buf = NULL;

    if (sort_char(sorted, NULL) == 84 || dest == NULL || sorted == NULL)
        return NULL;
    for (int i = 0; i < len; i++) {
        buf = my_memset(sizeof(int) * 1, NULL);
        *buf = i;
        if (add_end_node(buf, &(array[(unsigned char)str[i]])) == 84)
            return NULL;
    }
    for (int i = 0; i < len; i++) {
        dest[i] = DATA(array[sorted[i]]);
        delete_node(&(array[sorted[i]]));
    }
    return dest;
}

char *bwt_decode(char *str)
{
    int len = my_strlen(str);
    int *index_loop = init_index_loop(str);
    int line = 0;
    char *dest = my_memset(sizeof(int) * (len + 1), NULL);

    if (index_loop == NULL || dest == NULL)
        return NULL;
    for (int i = 0; i < len; i++)
        if (str[i] == '\003')
            line = i;
    for (int i = 0; i < len - 1; i++) {
        line = index_loop[line];
        dest[i] = str[line];
    }
    return dest;
}
