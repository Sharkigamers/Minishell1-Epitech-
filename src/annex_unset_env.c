/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** annex for unsetenv
*/

#include "my.h"

int gest_unset_error(char *buf)
{
    int space = 0;

    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == ' ' && (buf[i + 1] > 32))
            space++;
    }
    if (space == 0) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return (1);
    }
    else
        return (0);
}

void free_uncpy(char ***cpy_save_env)
{
    for (int i = 0; (*cpy_save_env)[i] != NULL; i++)
        free((*cpy_save_env)[i]);
    free(*cpy_save_env);
}
