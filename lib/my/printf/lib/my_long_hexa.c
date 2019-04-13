/*
** EPITECH PROJECT, 2018
** my_long_hexa
** File description:
** longhexa
*/

void my_putchar(char c);

long my_long_hexa(long nb)
{
    if (nb >= 16) {
        my_long_hexa(nb / 16);
        my_long_hexa(nb % 16);
    }
    else if (nb >= 10 && nb <= 16)
        my_putchar(nb + 87);
    else my_putchar(nb + 48);
    return (nb);
}
