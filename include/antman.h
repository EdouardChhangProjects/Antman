/*
** EPITECH PROJECT, 2021
** ex
** File description:
** ex header
*/

#ifndef ANTMAN_H_
    #define ANTMAN_H_

    typedef struct char_rotation_s {
        long long index;
        char *suffix;
    } char_rotation_t;

    int swap(void **ptr_a, void **ptr_b);
    char *load_file_in_mem(char *filepath);
    void **sort(void **array, int (*cmp)(void *, void *));
    char *run_length_decode(char *str);
    void **sort(void **array, int (*cmp)(void *, void *));
    char *bwt_decode(char *str);
    int sort_char(char *array, int (*cmp)(char, char));
    char *bwdt_encode(char *filepath);

#endif
