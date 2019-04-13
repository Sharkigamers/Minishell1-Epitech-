/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** main loop
*/

#include "my.h"

int simple_args(arg_t *arg, char *buf, char ***save_env)
{
    arg->argv = fill_argv(buf);
    arg->argc = fill_argc(arg);
    if (cond_env(save_env, buf, arg) == 1)
        return (1);
    if (my_strcmp(arg->argv[0], "cd") == 0) {
        init_oldpwd(save_env);
        cond_cd(arg, save_env);
        return (1);
    }
    return (0);
}

int cond_before_loop(char **buf, char ***save_env, int *nb_rep)
{
    if (prompt(buf, *save_env) == 1)
        return (1);
    for (int i = 0; (*buf)[i] != '\0'; i++)
        (*buf)[i] == ';' ? (*nb_rep)++ : 0;
    return (0);
}

void inter_loop(arg_t *arg, char **buf, char ***save_env, int *res)
{
    int enter = 0;
    int j = 0;

    if ((*res) == 0) {
        if (simple_args(arg, *buf, save_env) == 1)
            enter = 1;
        if (enter == 0 && exec(*save_env, arg) == 1)
            enter = 2;
    }
    for (j = 0; (*buf)[j] != '\0' && (*buf)[j] != ';'; j++);
    j++;
    (*buf) += j;
    (*res) = 0;

}

int in_loop(char ***save_env, arg_t *arg, char **buf)
{
    int res = 0;
    int nb_rep = 0;
    int return_value = 0;

    if (cond_before_loop(buf, save_env, &nb_rep) == 1)
        return (1);
    for (int i = 0; i <= nb_rep; i++) {
        if ((res = exit_cond(buf, arg)) == 1)
            return_value = 1;
        inter_loop(arg, buf, save_env, &res);
    }
    return (return_value);
}
