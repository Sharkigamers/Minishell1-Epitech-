/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** annex for cd
*/

#include "my.h"

void cond_dash(char **oldpwd, char ***save_env, int i)
{
    *oldpwd = my_strdup((*save_env)[i]);
    (*oldpwd) += 6;
    (*oldpwd)[0] = '/';
}

void fill_pwd(char ***save_env, int i, char *pwd)
{
    char *start_pwd = "PWD=";
    char *filled_pwd = malloc(my_strlen(pwd) + 5);

    filled_pwd = my_strcat(start_pwd, pwd, filled_pwd);
    free((*save_env)[i]);
    (*save_env)[i] = my_strdup(filled_pwd);
    free(filled_pwd);
}

void fill_oldpwd(char ***save_env, int i, char *pwd)
{
    char *start_pwd = "OLDPWD=";
    char *filled_oldpwd;

    filled_oldpwd = malloc(my_strlen(pwd) + 8);
    filled_oldpwd = my_strcat(start_pwd, pwd, filled_oldpwd);
    (*save_env)[i] = my_strdup(filled_oldpwd);
    free(filled_oldpwd);
}

void change_pwd(char ***save_env)
{
    char *pwd = NULL;
    char *ptr;
    int i;

    for (size_t size = 2; 69; size *= 2) {
        pwd = malloc(size + 1);
        pwd[size] = '\0';
        ptr = getcwd(pwd, size);
        if (ptr == NULL && errno == ERANGE)
            free(pwd);
        else
            break;
    }
    for (i = 0; (*save_env)[i] != NULL; i++) {
        if (my_strncmp((*save_env)[i], "PWD", '=') == 0) {
            fill_pwd(save_env, i, pwd);
        }
    }
}

int cond_last_dash(arg_t *arg)
{
    if (arg->used_cd == 1) {
        write(2, ": No such file or directory.\n", 29);
        arg->return_value = 1;
        return (1);
    }
    return (0);
}
