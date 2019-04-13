/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** fill argv
*/

#include "my.h"

void fill_in(char *buf, char ***argv, int real_space)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int save = 0;

    for (; i < real_space; i++) {
        save = k;
        for (; buf[k] != '\0' && buf[k] != ' ' && buf[k] != '\t' &&
            buf[k] != ';'; k++, j++);
        (*argv)[i] = malloc(j + 1);
        k = save;
        for (j = 0; buf[k] != '\0' && buf[k] != ' ' && buf[k] != '\t' &&
            buf[k] != ';'; j++, k++)
            (*argv)[i][j] = buf[k];
        (*argv)[i][j] = '\0';
        for (; buf[k] == ' ' || buf[k] == '\t'; k++);
    }
    (*argv)[i] = NULL;
}

char **fill_argv(char *buf)
{
    char **argv;
    int real_space = 0;
    int i;

    for (i = 0; buf[i] == ' ' && buf[i] == '\t'; i++);
    buf += i;
    for (i = 0; buf[i] != '\0' && buf[i] != ';'; i++) {
        i == 0 ? real_space = 1 : 0;
        if ((buf[i] == ' ' || buf[i] == '\t') && (buf[i + 1] != ' ' &&
            buf[i + 1] != '\t' && buf[i + 1] != '\0' && buf[i + 1] != ';'))
            real_space++;
    }
    argv = malloc(sizeof(char *) * (real_space + 1));
    fill_in(buf, &argv, real_space);
    return (argv);
}

int fill_argc(arg_t *arg)
{
    int i = 0;

    for (; arg->argv[i] != NULL; i++);
    return (i);
}
