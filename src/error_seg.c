/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** error_seg
*/

#include "my.h"

void seg_error(arg_t *arg, int status)
{
    if (!WIFEXITED(status)) {
        WTERMSIG(status) != 8 ? my_puterrorstr(strsignal(WTERMSIG(status))) : 0;
        if (WTERMSIG(status) == 8)
            write(2, "Floating exception", 18);
        WCOREDUMP(status) == 128 ? my_puterrorstr(" (core dumped)") : 0;
        my_printf("\n");
        arg->return_value = WTERMSIG(status) + 128;
    }
}
