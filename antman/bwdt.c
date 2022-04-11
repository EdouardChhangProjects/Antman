/*
** EPITECH PROJECT, 2022
** antman
** File description:
** bwdt
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"
#include "antman.h"

int cmpfunc(const void *x, const void *y)
{
    char_rotation_t *rx = (char_rotation_t *)x;
    char_rotation_t *ry = (char_rotation_t *)y;
    return my_strcmp(rx->suffix, ry->suffix);
}

int *make_suffix_array(char *input_text, int len)
{
    int *suffix_array = my_memset(sizeof(int) * (len + 1), NULL);
    char_rotation_t **suffix = my_memset(sizeof(void *) * (len + 1), NULL);

    for (int index = 0; index < len; index++)
        suffix[index] = my_memset(sizeof(char_rotation_t), NULL);
    for (int index = 0; index < len; index++) {
        suffix[index]->index = index;
        suffix[index]->suffix = (input_text + index);
    }
    sort((void **)suffix, (int (*)(void *, void *))cmpfunc);
    for (int index = 0; index < len; index++)
        suffix_array[index] = suffix[index]->index;
    return suffix_array;
}

char *find_last_char(char *input_text, int *suffix_array, int len_text)
{
    char *bwt_array = my_memset(sizeof(char) * (len_text + 1), NULL);
    int index;
    int last_char = 0;

    for (index = 0; index < len_text; index++) {
        last_char = suffix_array[index] - 1;
        if (last_char < 0)
            last_char = last_char + len_text;
        bwt_array[index] = input_text[last_char];
    }
    bwt_array[index] = '\0';
    return bwt_array;
}

char *bwdt_encode(char *str)
{
    int len_text = my_strlen(str);
    int *suffix_array = make_suffix_array(str, len_text);
    char *bwt_array = find_last_char(str, suffix_array, len_text);

    return bwt_array;
}
