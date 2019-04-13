/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** environement
*/

#include "my.h"

void free_cpy(char ***cpy_save_env)
{
    for (int i = 0; (*cpy_save_env)[i] != NULL; i++)
        free((*cpy_save_env)[i]);
    free(*cpy_save_env);
}

void cond_save_path(arg_t *arg, char **save_env)
{
    for (int i = 0; save_env[i] != NULL; i++) {
        if (my_strncmp(save_env[i], "PATH", '=') == 0) {
            arg->save_path = my_strdup(save_env[i]);
            arg->save_path += 5;
        }
    }
}

int cond_setenv(char ***save_env, char *buf, arg_t *arg)
{
    if (my_strncmp(buf, "setenv", ' ') == 0) {
        malloc_setenv(save_env, buf);
        cond_save_path(arg, *save_env);
        return (1);
    }
    if (my_strncmp(buf, "unsetenv", ' ') == 0 ||
        my_strcmp(buf, "unsetenv") == 0) {
        malloc_unsetenv(save_env, buf);
        return (1);
    }
    return (0);
}

int cond_env(char ***save_env, char *buf, arg_t *arg)
{
    int space = 0;

    for (int i = 0; buf[i] != '\0'; i++)
        buf[i] == ' ' && buf[i + 1] != ' ' && buf[i + 1] != '\0' ? space++ : 0;
    if (my_strcmp(buf, "env") == 0 || my_strcmp(buf, "setenv") == 0 ||
        (space == 0 && my_strncmp(buf, "setenv", ' ') == 0)) {
        for (int i = 0; (*save_env)[i] != NULL; i++)
            my_printf("%s\n", (*save_env)[i]);
        return (1);
    }
    if (cond_setenv(save_env, buf, arg) == 1)
        return (1);
    return (0);
}

void malloc_env(char **env, char ***save_env, arg_t *arg)
{
    int i;

    arg->return_value = 0;
    for (i = 0; env[i] != NULL; i++);
    *save_env = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; j != i; j++) {
        (*save_env)[j] = my_strdup(env[j]);
        if (my_strncmp((*save_env)[j], "PATH", '=') == 0) {
            arg->save_path = my_strdup((*save_env)[j]);
            arg->save_path += 5;
        }
    }
    (*save_env)[i] = NULL;
}
