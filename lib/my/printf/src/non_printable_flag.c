/*
** EPITECH PROJECT, 2018
** non_printable_flag
** File description:
** flag S
*/

#include <stdarg.h>
#include "my.h"

void annex_replacement(char *str, int i)
{
    if (str[i] < 8) {
        my_putstr("00");
        my_octal(str[i]);
    } else if (str[i] < 32) {
        my_putstr("0");
        my_octal(str[i]);
    } else
        my_octal(str[i]);
}

void replace_char_non_printable(char *str)
{
    int i = 0;
    char *save;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] == 127) {
            my_putchar('\\');
            annex_replacement(str, i);
        }
        else
            my_putchar(str[i]);
        i += 1;
    }
}
