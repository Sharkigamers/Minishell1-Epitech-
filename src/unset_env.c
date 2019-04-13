/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** unset_env
*/

#include "my.h"

int find_start(char *buf)
{
    int i = 0;

    for (; buf[i] != ' ' && buf[i] != '\0'; i++);
    for (; buf[i] == ' ' || buf[i] == '\0'; i++);
    return (i);
}

void fill_unsetenv(char *buf, char ***cpy_save_env, char ***save_env, int i)
{
    int k = 0;
    int l;

    (*cpy_save_env)[i] = NULL;
    free(*save_env);
    *save_env = malloc(sizeof(char *) * i);
    for (l = 0; buf[l] != ' ' && buf[l] != '\0'; l++);
    buf[l] = '\0';
    for (i = 0; (*cpy_save_env)[i] != NULL; i++) {
        if (my_strncmp((*cpy_save_env)[i], buf, '=') != 0) {
            (*save_env)[k] = my_strdup((*cpy_save_env)[i]);
            k++;
        }
    }
    (*save_env)[k] = NULL;
}

int found_existing(char **buf, char **save_env)
{
    int i;
    int l;

    *buf += find_start(*buf);
    for (l = 0; (*buf)[l] != ' ' && (*buf)[l] != '\0'; l++);
    (*buf)[l] = '\0';
    for (i = 0; save_env[i] != NULL; i++) {
        if (my_strncmp(save_env[i], *buf, '=') == 0)
            return (0);
    }
    return (1);
}

int nb_arguments(char *buf)
{
    int nb_arg = 0;
    int j = 0;

    for (; buf[j] != '\0'; j++) {
        buf[j] == ' ' && buf[j + 1] != ' ' && buf[j + 1] != '\0' ? nb_arg++ : 0;
    }
    return (nb_arg);
}

void malloc_unsetenv(char ***save_env, char *buf)
{
    int nb_arg = nb_arguments(buf);;
    char **cpy_save_env;
    int i = 0;

    if (gest_unset_error(buf) == 1)
        return;
    for (int j = 0; j < nb_arg; j++) {
        if (found_existing(&buf, *save_env) == 1)
            return;
        for (i = 0; (*save_env)[i] != NULL; i++);
        cpy_save_env = malloc(sizeof(char *) * (i + 1));
        for (i = 0; (*save_env)[i] != NULL; i++) {
            cpy_save_env[i] = my_strdup((*save_env)[i]);
            free((*save_env)[i]);
        }
        fill_unsetenv(buf, &cpy_save_env, save_env, i);
        free_uncpy(&cpy_save_env);
    }
}
