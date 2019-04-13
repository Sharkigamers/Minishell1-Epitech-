/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** setenv
*/

#include "my.h"

int gest_set_error(char *buf)
{
    int space = 0;

    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == ' ' && (buf[i + 1] > 32))
            space++;
    }
    if (space > 2) {
        write(2, "setenv: Too many arguments.\n", 28);
        return (1);
    }
    else
        return (0);
}

void fill_in_setenv(char ***save_env, char *buf, int i)
{
    int j;
    int k = 0;

    for (j = 0; buf[j] != '\0' && buf[j] != ' ' && buf[j] != '\t'; j++) {
            (*save_env)[i][k] = buf[j];
            k++;
        }
    for (; buf[j] != '\0' && buf[j] == ' ' && buf[j] != '\t'; j++);
    (*save_env)[i][k] = '=';
    for (; buf[j] != '\0' && buf[j] != ' ' && buf[j] != '\t'; j++) {
        k++;
        (*save_env)[i][k] = buf[j];
    }
    (*save_env)[i][k + 1] = '\0';
}

int cond_error(char *buf)
{
    char *check = "éèàùµ";
    int counter = 0;

    if (buf[0] != '_' && (buf[0] < 'A' || buf[0] > 'Z') && (buf[0] < 'a' ||
        buf[0] > 'z')) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return (1);
    }
    for (int i = 1; buf[i] != ' ' && buf[i] != '\0'; i++, counter = 0) {
        for (int k = 0; check[k] != '\0'; k++)
            buf[i] == check[k] ? counter++ : 0;
        if (((buf[i] < 'A' || buf[i] > 'Z') && (buf[i] < 'a' || buf[i] > 'z') &&
            (buf[i] < '0' || buf[i] > '9')) &&
            buf[i] != '.' && buf[i] != '_' && counter == 0) {
            write(2,
            "setenv: Variable name must contain alphanumeric characters.\n",60);
            return (1);
        }
    }
    return (0);
}

int fill_setenv(char ***save_env, char **buf)
{
    int i = 0;
    int start = 7;

    for (; (*buf)[start] == ' '; start++);
    *buf += start;
    if (cond_error(*buf) == 1)
        return (1);
    for (i = 0; (*save_env)[i] != NULL; i++) {
        if (my_strdbncmp((*save_env)[i], *buf, '=', ' ') == 0) {
            free((*save_env)[i]);
            (*save_env)[i] = malloc(my_strlen(*buf) + 2);
            fill_in_setenv(save_env, *buf, i);
            return (1);
        }
    }
    return (0);
}

void malloc_setenv(char ***save_env, char *buf)
{
    char **cpy_save_env;
    int i = 0;

    if (gest_set_error(buf) == 1 || fill_setenv(save_env, &buf) == 1)
        return;
    for (i = 0; (*save_env)[i] != NULL; i++);
    cpy_save_env = malloc(sizeof(char *) * (i + 1));
    for (i = 0; (*save_env)[i] != NULL; i++) {
        cpy_save_env[i] = my_strdup((*save_env)[i]);
        free((*save_env)[i]);
    }
    cpy_save_env[i] = NULL;
    free(*save_env);
    *save_env = malloc(sizeof(char *) * (i + 2));
    for (i = 0; cpy_save_env[i] != NULL; i++)
        (*save_env)[i] = my_strdup(cpy_save_env[i]);
    (*save_env)[i] = malloc(my_strlen(buf) + 2);
    fill_in_setenv(save_env, buf, i);
    (*save_env)[i + 1] = NULL;
    free_cpy(&cpy_save_env);
}
