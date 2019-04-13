/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** cond exec
*/

#include "my.h"

int wave(arg_t *arg, char **save_env)
{
    char *save = my_strdup(arg->argv[0]);
    char *var_env;
    char *final_res;

    save += 1;
    free(arg->argv[0]);
    for (int i = 0; save_env[i] != NULL; i++) {
        if (my_strncmp(save_env[i], "HOME", '=') == 0) {
            var_env = my_strdup(save_env[i]);
            var_env += 5;
            final_res = malloc(my_strlen(save) + my_strlen(var_env) + 1);
            final_res = my_strcat(var_env, save, final_res);
            arg->argv[0] = my_strdup(final_res);
            return (0);
        }
    }
    my_printf("%s", arg->argv[0]);
    write(2, ": Command not found.\n", 21);
    arg->return_value = 1;
    return (1);
}

void last_check_failed_exec(int *success, char **full_path, arg_t *arg)
{
    if (*success == 0) {
        *full_path = malloc(2 + my_strlen(arg->argv[0]) + 1);
        *full_path = my_strcat("./", arg->argv[0], *full_path);
        if (access(*full_path, X_OK) == 0)
            *success = 1;
        else
            free(*full_path);
    }
}

int check_folder(char *path, arg_t *arg)
{
    DIR *dir;
    struct stat sb;

    dir = opendir(path);
    stat(path, &sb);
    if (dir == NULL) {
        if (S_ISREG(sb.st_mode))
            return (0);
    }
    my_printf("%s", arg->argv[0]);
    write(2, ": Permission denied.\n", 21);
    return (1);
}

void print_error(char *str, arg_t *arg)
{
    my_printf("%s", str);
    write(2, ": Command not found.\n", 21);
    arg->return_value = 1;
}

int check_binary(char *argu)
{
    if (errno == ENOEXEC) {
        my_printf("%s", argu);
        write(2, ": cannot execute binary file\n", 29);
        return (1);
    }
    return (0);
}
