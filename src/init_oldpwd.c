/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** init
*/

#include "my.h"

void find_pwd(char ***save_env, char **get_pwd)
{
    for (int i = 0; (*save_env)[i] != NULL; i++) {
        if (my_strncmp((*save_env)[i], "PWD", '=') == 0) {
            *get_pwd = my_strdup((*save_env)[i]);
            break;
        }
    }
}

void init_oldpwd(char ***save_env)
{
    char *pwd = "setenv OLDPWD ";
    char *get_pwd = NULL;
    char *send_pwd = NULL;

    for (int i = 0; (*save_env)[i] != NULL; i++) {
        if (my_strncmp((*save_env)[i], "OLDPWD", '=') == 0) {
            return;
        }
    }
    find_pwd(save_env, &get_pwd);
    get_pwd += 4;
    send_pwd = malloc(my_strlen(pwd) + my_strlen(get_pwd));
    send_pwd = my_strcat(pwd, get_pwd, send_pwd);
    malloc_setenv(save_env, send_pwd);
}
