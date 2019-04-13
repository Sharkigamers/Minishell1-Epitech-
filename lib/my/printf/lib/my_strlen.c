/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** define the len of the str
*/

void my_putchar(char);

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return i;
}
