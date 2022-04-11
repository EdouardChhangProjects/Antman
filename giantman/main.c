/*
** EPITECH PROJECT, 2022
** bs
** File description:
** main
*/

#include "my.h"

int giantman(char *argv);
int bwt(void);

int main(int argc, char **argv)
{
    if (argc == 2)
        return giantman(argv[1]);
    return my_put_error("Invalid arguments");
}
