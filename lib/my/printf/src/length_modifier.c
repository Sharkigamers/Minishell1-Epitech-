/*
** EPITECH PROJECT, 2018
** flag legth modifier
** File description:
** flags for length
*/

#include <stdarg.h>
#include "my.h"

void change_length_l(char *fmt, int *i, va_list ap)
{
    if (fmt[*i] == '%' && (fmt[(*i) + 1] == 'l' &&
                            (fmt[(*i) + 2] == 'd' || (fmt[(*i) + 2] == 'l' &&
                                                    fmt[(*i) + 3] == 'd')))) {
        switch (fmt[(*i) + 2]) {
        case 'd':
            my_put_long_nbr(va_arg(ap, long));
            (*i) += 2;
            break;
        }
        switch (fmt[(*i) + 3]) {
        case 'd':
            my_put_longlong_nbr(va_arg(ap, long long));
            (*i) += 3;
            break;
        }
    }
}

void change_length_hd(char *fmt, int *i, va_list ap)
{
    if (fmt[*i] == '%' && (fmt[(*i) + 1] == 'h' &&
                            (fmt[(*i) + 2] == 'd' || (fmt[(*i) + 2] == 'c')))) {
        switch (fmt[(*i) + 2]) {
        case 'd':
            my_put_short_nbr(va_arg(ap, int));
            (*i) += 2;
            break;
        }
        switch (fmt[(*i) + 2]) {
        case 'c':
            my_putchar(va_arg(ap, int));
            (*i) += 2;
            break;
        }
    }
}

void change_length_hh(char *fmt, int *i, va_list ap)
{
    if (fmt[*i] == '%' && (fmt[(*i) + 1] == 'h' &&
                            (fmt[(*i) + 2] == 'h' && (fmt[(*i) + 3] == 'c' ||
                                                    fmt[(*i) + 3] == 'd')))) {
        switch (fmt[(*i) + 3]) {
        case 'c':
            my_putchar(va_arg(ap, int));
            (*i) += 3;
            break;
        case 'd':
            my_put_char_nbr(va_arg(ap, int));
            (*i) += 3;
            break;
        }
    }
}
