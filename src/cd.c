/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** cd
*/

#include "my.h"

void change_oldpwd(char ***save_env, arg_t *arg)
{
    char *oldpwd = NULL;
    int success = 0;
    int i;

    for (i = 0; (*save_env)[i] != NULL; i++) {
        if (my_strncmp((*save_env)[i], "PWD", '=') == 0) {
            oldpwd = my_strdup((*save_env)[i]);
            oldpwd += 5;
            success = 1;
            break;
        }
    }
    for (i = 0; success == 1 && (*save_env)[i] != NULL; i++) {
        if (my_strncmp((*save_env)[i], "OLDPWD", '=') == 0) {
            free((*save_env)[i]);
            fill_oldpwd(save_env, i, oldpwd);
        }
    }
    arg->return_value = 0;
    arg->used_cd = 0;
}

void gest_error_cd(arg_t *arg)
{
    if (arg->argc == 3) {
        write(2, "cd: string not in pwd: ", 23);
        my_printf("%s\n", arg->argv[2]);
        arg->return_value = 1;
    }
    if (arg->argc > 3) {
        write(2, "cd: too many arguments.\n", 23);
        arg->return_value = 1;
    }
}

void home(char ***save_env, arg_t *arg)
{
    char *home = NULL;

    for (int i = 0; (*save_env)[i] != NULL; i++) {
        if (my_strncmp((*save_env)[i], "HOME", '=') == 0) {
            home = my_strdup((*save_env)[i]);
            home += 5;
            if (home[0] == '\0') {
                arg->return_value = 1;
                arg->used_cd = 0;
                return;
            }
            if (chdir(home) == -1) {
                arg->return_value = 1;
                write(2, "cd: Can't change to home directory.\n", 36);
            }
            else
                change_oldpwd(save_env, arg);
        }
    }
}

void dash(char ***save_env, arg_t *arg)
{
    char *oldpwd = NULL;

    if (cond_last_dash(arg) == 1)
        return;
    for (int i = 0; (*save_env)[i] != NULL; i++) {
        if (my_strncmp((*save_env)[i], "OLDPWD", '=') == 0) {
            cond_dash(&oldpwd, save_env, i);
            if (oldpwd[0] == '\0') {
                arg->return_value = 1;
                return;
            }
            if (chdir(oldpwd) == -1) {
                arg->return_value = 1;
                write(2, "cd: Can't change to home directory.\n", 36);
            }
            else
                change_oldpwd(save_env, arg);
        }
    }
}

void cond_cd(arg_t *arg, char ***save_env)
{
    gest_error_cd(arg);
    if (arg->argc == 1 || (arg->argc == 2 && my_strcmp(arg->argv[1], "~") == 0))
        home(save_env, arg);
    else if (arg->argc == 2) {
        if (my_strcmp(arg->argv[1], "--") == 0) {
            home(save_env, arg);
            change_oldpwd(save_env, arg);
            change_pwd(save_env);
            return;
        }
        if (my_strcmp(arg->argv[1], "-") == 0)
            dash(save_env, arg);
        else if (chdir(arg->argv[1]) == -1) {
            arg->return_value = 1;
            my_printf("%s: ", arg->argv[1]);
            my_printf("%s.\n", strerror(errno));
        } else
            change_oldpwd(save_env, arg);
    }
    change_pwd(save_env);
}
