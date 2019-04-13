/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** put str
*/

int my_putchar(char);

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
}
