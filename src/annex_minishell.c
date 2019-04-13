/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** annex for minishell
*/

#include "my.h"

void cond_name(char **save_env, int i, char **name)
{
    for (int j = 0; save_env[i][j] != '\0'; j++)
        (*name)[j] = save_env[i][j];
    (*name)[my_strlen(save_env[i])] = '\0';
    for (int j = 0; (*name)[j] != '\0'; j++) {
        if ((*name)[j] == '=') {
            *name += (j + 1);
            j = 0;
        }
    }
}

void cond_path(char **save_env, int i, char **path)
{
    for (int j = 0; save_env[i][j] != '\0'; j++)
        (*path)[j] = save_env[i][j];
    (*path)[my_strlen(save_env[i])] = '\0';
    for (int j = 0; (*path)[j] != '\0'; j++) {
        if ((*path)[j] == '/' || (*path)[j] == '=') {
            *path += (j + 1);
            j = 0;
        }
    }
}

void disp_prompt(char **name, char **path)
{
    if (isatty(0) == 0)
        return;
    if (*name != NULL && *path != NULL) {
        my_printf("%s[", BLUE);
        my_printf("%s%s%s~%s%s", GREEN, *name, BLUE, GREEN, *path);
        my_printf("%s] %s▄︻̷┻̿═━一 ⫸  %s", BLUE, RED, RESET);
    }
    else
        my_printf("%s[✨%sMYSH%s✨] %s➼ %s", BLUE, GREEN, BLUE, RED, RESET);
}

int prompt(char **buf, char **save_env)
{
    size_t len = 0;
    char *path = NULL;
    char *name = NULL;
    int i;

    for (i = 0; save_env[i] != NULL; i++) {
        if (my_strncmp(save_env[i], "LOGNAME", '=') == 0) {
            name = malloc(my_strlen(save_env[i]) + 1);
            cond_name(save_env, i, &name);
        }
        if (my_strncmp(save_env[i], "PWD", '=') == 0) {
            path = malloc(my_strlen(save_env[i]) + 1);;
            cond_path(save_env, i, &path);
        }
    }
    disp_prompt(&name, &path);
    if (getline(buf, &len, stdin) == -1)
        return (1);
    (*buf)[my_strlen(*buf) - 1] = '\0';
    return (0);
}

void last_free(char ***save_env)
{
    for (int i = 0; (*save_env)[i] != NULL; i++)
        free((*save_env)[i]);
    free(*save_env);
}
