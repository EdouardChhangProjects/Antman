/*
** EPITECH PROJECT, 2022
** bs
** File description:
** giantman
*/

#include "my.h"
#include "my_linked_list.h"
#include "antman.h"

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
        write(2, "giantman: Failed to find the file: ", 35);
        my_put_error(my_strcat(filepath, "\n"));
        return NULL;
    }
    dest = my_memset(buffer.st_size + 1, NULL);
    size = read(fd, dest, buffer.st_size);
    if (size == -1 || size != buffer.st_size) {
        write(2, "giantman: Failed to read the file: ", 35);
        my_put_error(my_strcat(filepath, "\n"));
        return NULL;
    }
    return (dest);
}

int my_isnum(char element)
{
    if ('1' <= element && element <= '9')
        return 1;
    return 0;
}

int giantman(char *argv)
{
    char *str = load_file_in_mem(argv);

    if (str == NULL)
        return 84;
    str = run_length_decode(str);
    if (str == NULL)
        return 84;
    str = bwt_decode(str);
    if (str == NULL)
        return 84;
    my_printf("%s", str);
    return 0;
}
