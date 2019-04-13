/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** minishell
*/

#include "my.h"

int minishell(char **env)
{
    char **save_env = NULL;
    char *buf = NULL;
    arg_t arg;

    malloc_env(env, &save_env, &arg);
    signal(SIGINT, SIG_IGN);
    arg.used_cd = 1;
    while (69) {
        if (in_loop(&save_env, &arg, &buf) == 1)
            break;
    }
    signal(SIGINT, SIG_DFL);
    last_free(&save_env);
    (isatty(0)) ? (my_printf("exit\n")) : (0);
    return (arg.return_value);
}
