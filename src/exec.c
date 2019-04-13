/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** exec
*/

#include "my.h"

void cond_exec(int nb_arg, char ***from_path, arg_t *arg)
{
    char *s_path = NULL;
    int k = 0;

    *from_path = malloc(sizeof(char *) * (nb_arg + 1));
    (*from_path)[nb_arg] = NULL;
    s_path = my_strdup(arg->save_path);
    for (int j = 0; j < nb_arg; j++) {
        for (k = 0; s_path[k] != ':' && s_path[k] != '\0'; k++);
        (*from_path)[j] = malloc(k + 2);
        for (k = 0; s_path[k] != ':' && s_path[k] != '\0'; k++)
            (*from_path)[j][k] = s_path[k];
        (*from_path)[j][k] = '/';
        (*from_path)[j][k + 1] = '\0';
        s_path += (k + 1);
    }
}

int last_cond(char *full_path, arg_t *arg, char **save_env, int success)
{
    int status = 0;
    pid_t pid;

    if (success == 1) {
        if (check_folder(full_path, arg) == 1)
            return (1);
        if ((pid = fork()) == 0) {
            signal(SIGINT, SIG_DFL);
            execve(full_path, arg->argv, save_env);
            check_binary(arg->argv[0]) == 1 ? exit(126) : 0;
        }
        waitpid(pid, &status, WUNTRACED);
        arg->return_value = WEXITSTATUS(status);
        seg_error(arg, status);
        free(full_path);
        return (0);
    } else
        print_error(arg->argv[0], arg);
    return (1);
}

int exec_execve(char **from_path, char *full_path, arg_t *arg, char **save_env)
{
    int success = 0;

    for (int j = 0; from_path[j] != NULL; j++) {
        full_path = malloc(my_strlen(from_path[j]) +
                            my_strlen(arg->argv[0]) + 1);
        full_path = my_strcat(from_path[j], arg->argv[0], full_path);
        if (access(full_path, X_OK) == 0) {
            success = 1;
            break;
        }
        free(full_path);
    }
    last_check_failed_exec(&success, &full_path, arg);
    if (last_cond(full_path, arg, save_env, success) == 1)
        return (1);
    return (0);
}

int my_binary(char **save_env, arg_t *arg)
{
    int status = 0;
    pid_t pid;
    int res = 0;

    if (arg->argv[0][0] == '~' && wave(arg, save_env) == 1)
        return (1);
    if (access(arg->argv[0], F_OK) == 0 && access(arg->argv[0], X_OK) == 0 &&
        (res = check_folder(arg->argv[0], arg)) == 0) {
        if ((pid = fork()) == 0) {
            signal(SIGINT, SIG_DFL);
            execve(arg->argv[0], arg->argv, save_env);
            check_binary(arg->argv[0]) == 1 ? exit(126) : 0;
        }
        waitpid(pid, &status, WUNTRACED);
        arg->return_value = WEXITSTATUS(status);
        seg_error(arg, status);
        return (0);
    }
    res != 1 ? print_error(arg->argv[0], arg) : 0;
    return (1);
}

int exec(char **save_env, arg_t *arg)
{
    char **from_path;
    char *full_path = NULL;
    int nb_arg = 0;

    if (arg->argv[0][0] == '.' || arg->argv[0][0] == '/' ||
        arg->argv[0][0] == '~') {
        if (my_binary(save_env, arg) == 0)
            return (0);
        else
            return (1);
    }
    for (int i = 0; arg->save_path[i] != '\0'; i++)
        arg->save_path[i] == ':' ? nb_arg++ : 0;
    nb_arg++;
    cond_exec(nb_arg, &from_path, arg);
    if (exec_execve(from_path, full_path, arg, save_env) == 1)
        return (1);
    return (0);
}
