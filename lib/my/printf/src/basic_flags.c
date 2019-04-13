/*
** EPITECH PROJECT, 2018
** annex_printf
** File description:
** annex for printf
*/

#include <stdarg.h>
#include "my.h"

void detect_four_first_flags(char *fmt, int *i, va_list ap)
{
    if (fmt[*i] == '%' && (fmt[(*i) + 1] == 's' || fmt[(*i) + 1] == 'c' ||
                            fmt[(*i) + 1] == 'd' || fmt[(*i) + 1] == 'i')) {
        switch (fmt[(*i) + 1]) {
        case 's':
            my_putstr(va_arg(ap, char *));
            break;
        case 'c':
            my_putchar(va_arg(ap, int));
            break;
        case 'd':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'i':
            my_put_nbr(va_arg(ap, int));
            break;
        }
        (*i) += 1;
    }
}

void detect_four_second_flags(char *fmt, int *i, va_list ap)
{
    if (fmt[*i] == '%' && (fmt[(*i) + 1] == 'o' || fmt[(*i) + 1] == 'x' ||
                            fmt[(*i) + 1] == 'X' || fmt[(*i) + 1] == 'u')) {
        switch (fmt[(*i) + 1]) {
        case 'o':
            my_octal(va_arg(ap, unsigned int));
            break;
        case 'x':
            my_hexa(va_arg(ap, unsigned int));
            break;
        case 'X':
            my_sup_hexa(va_arg(ap, unsigned int));
            break;
        case 'u':
            unsigned_putnbr(va_arg(ap, unsigned int));
            break;
        }
        (*i) += 1;
    }
}

void detect_last_flags(char *fmt, int *i, va_list ap)
{
    if (fmt[*i] == '%' && (fmt[(*i) + 1] == 'S' || fmt[(*i) + 1] == 'p' ||
                            fmt[(*i) + 1] == 'm' || fmt[(*i) + 1] == 'b')) {
        switch (fmt[(*i) + 1]) {
        case 'S':
            replace_char_non_printable(va_arg(ap, char *));
            break;
        case 'p':
            my_putstr("0x");
            my_long_hexa(va_arg(ap, long));
            break;
        case 'm':
            my_putstr("Success");
            break;
        case 'b':
            my_binary(va_arg(ap, unsigned int));
            break;
        }
        (*i) += 1;
    }
}
