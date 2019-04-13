/*
** EPITECH PROJECT, 2018
** my_hexa
** File description:
** Make the same thing than my_put_nbr for hexa
*/

void my_putchar(char c);

unsigned int my_hexa(unsigned int nb)
{
    if (nb >= 16) {
        my_hexa(nb / 16);
        my_hexa(nb % 16);
    }
    else if (nb >= 10 && nb <= 16)
        my_putchar(nb + 87);
    else my_putchar(nb + 48);
    return (nb);
}
