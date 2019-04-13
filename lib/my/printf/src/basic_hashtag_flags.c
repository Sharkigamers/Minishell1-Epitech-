/*
** EPITECH PROJECT, 2018
** basic_hashtag_flags
** File description:
** make the same but with #
*/

#include <stdarg.h>
#include "my.h"

void detect_first_flags(char *fmt, int *i, va_list ap)
{
    if (fmt[*i] == '%' && (fmt[(*i) + 1] == '#' &&
                        (fmt[(*i) + 2] == 'o' || fmt[(*i) + 2] == 'x' ||
                        fmt[(*i) + 2] == 'X'))) {
        switch (fmt[(*i) + 2]) {
        case 'o':
            my_putchar('0');
            my_octal(va_arg(ap, unsigned int));
            break;
        case 'x':
            my_putstr("0x");
            my_hexa(va_arg(ap, unsigned int));
            break;
        case 'X':
            my_putstr("0X");
            my_sup_hexa(va_arg(ap, unsigned int));
            break;
        }
        (*i) += 2;
    }
}
