/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** reversing a string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int last = my_strlen(str) - 1;
    char save;

    while (i <= last) {
        save = str[i];
        str[i] = str[last];
        str[last] = save;
        i += 1;
        last -= 1;
    }
    return (str);
}
