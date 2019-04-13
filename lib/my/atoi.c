/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** convert char * to int
*/

int my_atoi(char const *str)
{
    int nb = 0;
    int neg = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            neg = 1;
            continue;
        }
        nb = (nb * 10) + (str[i] - '0');
    }
    return (neg == 1 ? -nb : nb);
}
