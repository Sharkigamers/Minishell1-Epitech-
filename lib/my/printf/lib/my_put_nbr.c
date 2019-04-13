/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** put str
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb <= 9 && nb >= 0)
        my_putchar(nb + 48);
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return (nb);
}
