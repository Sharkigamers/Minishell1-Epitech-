/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** exit
*/

#include "my.h"

int check_match(char *buf)
{
    int star = 0;
    int j = 0;

    for (; buf[j] != '\0'; j++)
        buf[j] == '*' ? star++ : 0;
    if (star > 0 && star < j) {
        my_printf("%s", buf);
        write(2, ": No match.\n", 12);
        return (42);
    }
    return (0);
}

int check_error(char *buf, int i, char **save_nb)
{
    if (buf[0] == '-' && (buf[i] < '0' || buf[i] > '9') && i != 0) {
        write(2, "exit: Badly formed number.\n", 27);
        return (42);
    }
    if (buf[i] != '-' && (buf[i] < '0' || buf[i] > '9')) {
        write(2, "exit: Expression Syntax.\n", 25);
        return (42);
    }
    (*save_nb)[i] = buf[i];
    return (0);
}

int in_exit(char *buf, arg_t *arg)
{
    int i;
    char *save_nb;
    int len;

    for (i = 4; buf[i] == ' ' || buf[i] == '\t'; i++);
    buf += i;
    for (len = 0; buf[len] != '\0' && buf[len] != ';'; len++);
    save_nb = malloc(len + 1);
    if (check_match(buf) == 42)
        return (42);
    for (i = 0; buf[i] != '\0' && buf[i] != ';'; i++) {
        if (check_error(buf, i, &save_nb) == 42) {
            arg->return_value = 1;
            return (42);
        }
    }
    save_nb[i] = '\0';
    arg->return_value = (my_atoi(save_nb) % 256);
    free(save_nb);
    return (1);
}

int exit_last_cond(int space, arg_t *arg, char *buf)
{
    if (space > 2) {
        write(2, "exit: Expression Syntax.\n", 25);
        return (0);
    }
    else if (space == 0) {
        arg->return_value = 0;
        return (1);
    }
    else {
        return (in_exit(buf, arg));
    }
}

int exit_cond(char **buf, arg_t *arg)
{
    int space = 0;
    int i;

    for (i = 0; (*buf)[i] != '\0' && (*buf)[i] != ';'; i++)
        (*buf)[i] == ' ' || (*buf)[i] == '\t' ? space++ : 0;
    if (space == i)
        return (42);
    for (i = 0; (*buf)[i] == ' ' || (*buf)[i] == '\t'; i++);
    (*buf) += i;
    space = 0;
    if (my_strcmp(*buf, "exit") == 0 || my_strncmp(*buf, "exit", ' ') == 0
        || my_strcmpn(*buf, "exit;", 5) == 0) {
        for (int i = 0; (*buf)[i] != '\0' && (*buf)[i] != ';'; i++)
            (*buf)[i] == ' ' && (*buf)[i + 1] != ' ' &&
                (*buf)[i + 1] != '\t' && (*buf)[i + 1] != '\0' &&
                (*buf)[i] != ';' ? space++ : 0;
        return (exit_last_cond(space, arg, *buf));
    }
    return (0);
}
