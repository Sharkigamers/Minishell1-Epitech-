/*
** EPITECH PROJECT, 2019
** putstrerror
** File description:
** put str in error output
*/

#include <unistd.h>

void my_puterrorchar(char c)
{
    write(2, &c, 1);
}

void my_puterrorstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_puterrorchar(str[i]);
}
