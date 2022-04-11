/*
** EPITECH PROJECT, 2022
** bs
** File description:
** antman
*/

#include "antman.h"
#include "my.h"

#include <stddef.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *load_file_in_mem(char *filepath)
{
    struct stat buffer;
    int fd = open(filepath, O_RDONLY);
    char *dest;
    ssize_t size;

    if (stat(filepath, &buffer) == -1) {
        write(2, "antman: Failed to find the file\n", 33);
        return NULL;
    }
    dest = my_memset(buffer.st_size + 2, NULL);
    size = read(fd, dest, buffer.st_size);
    if (size == -1 || size != buffer.st_size) {
        write(2, "antman: Failed to read the file\n", 33);
        return NULL;
    }
    dest[size] = '\003';
    dest[++size] = '\0';
    return (dest);
}

void my_print_count(int count, int letter)
{
    my_printf("%c", letter);
    if (count > 1)
        my_printf("%c", letter);
    if (count >= 2)
        my_printf("%c", count);
    return;
}

int antman(char *argv)
{
    char *str = load_file_in_mem(argv);
    int len = 0;
    unsigned char count = 0;
    char letter = 0;
    int index = 0;

    if (str == NULL)
        return 84;
    str = bwdt_encode(str);
    if (str == NULL)
        return 84;
    len = my_strlen(str);
    while (index < len) {
        letter = str[index];
        count = 1;
        while (str[++index] == letter && index < len && count < 127)
            count++;
        my_print_count(count, letter);
    }
    return 0;
}
