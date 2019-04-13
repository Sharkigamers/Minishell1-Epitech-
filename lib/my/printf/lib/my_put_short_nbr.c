/*
** EPITECH PROJECT, 2018
** my_put_short_nb
** File description:
** putnbr
*/

void my_putchar(char);

short my_put_short_nbr(short nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb <= 9 && nb >= 0)
        my_putchar(nb + 48);
    if (nb >= 10) {
        my_put_short_nbr(nb / 10);
        my_put_short_nbr(nb % 10);
    }
    return (nb);
}
