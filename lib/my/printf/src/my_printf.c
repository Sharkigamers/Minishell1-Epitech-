/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** make the same than printf
*/

#include <stdarg.h>
#include "my.h"

void count_percent(char *fmt, int *i, int save_i)
{
    if (fmt[*i] == '%' && fmt[(*i) + 1] == '%') {
        my_putchar(fmt[*i]);
        (*i)++;
    }
    else if (*i == save_i && fmt[(*i) - 1] != '%')
        my_putchar(fmt[*i]);
}

void list_fct(char *fmt, int *i, int save_i, va_list ap)
{
    save_i = *i;
    detect_four_first_flags(fmt, i, ap);
    detect_four_second_flags(fmt, i, ap);
    detect_last_flags(fmt, i, ap);
    change_length_l(fmt, i, ap);
    change_length_hd(fmt, i, ap);
    change_length_hh(fmt, i, ap);
    detect_first_flags(fmt, i, ap);
    count_percent(fmt, i, save_i);
}

void my_printf(char *fmt, ...)
{
    va_list ap;
    int save_i;

    va_start(ap, fmt);
    for (int i = 0; fmt[i] != '\0'; i++) {
        if (fmt[i] == '%') {
            list_fct(fmt, &i, save_i, ap);
        }
        else
            my_putchar(fmt[i]);
    }
    va_end(ap);
}
