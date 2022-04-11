/*
** EPITECH PROJECT, 2022
** antman
** File description:
** run_length_encoding
*/

#include "my.h"
#include "antman.h"

#include <stddef.h>

int run_length_encode(char *str)
{
    int len = my_strlen(str);
    unsigned char count = 0;
    char letter = 0;
    int index = 0;

    if (str == NULL)
        return 84;
    while (index < len) {
        letter = str[index];
        count = 1;
        while (str[++index] == letter && index < len && count < 127)
            count++;
        my_printf("%c", letter);
        if (count > 1)
            my_printf("%c", letter);
        if (count >= 2)
            my_printf("%c", count);
    }
    return 0;
}