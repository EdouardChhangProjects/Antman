/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "my.h"

int antman(char *argv);
char *bwdt_encode(char *argv);

int main(int argc, char **argv)
{
    if (argc == 2)
        return antman(argv[1]);
    return my_put_error("Invalid number of arguments\n");
}
