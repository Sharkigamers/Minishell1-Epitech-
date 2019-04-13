/*
** EPITECH PROJECT, 2018
** my_put_longlong_nbr
** File description:
** same than put nbr but with longlong
*/

void my_putchar(char);

long long my_put_longlong_nbr(long long nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb <= 9 && nb >= 0)
        my_putchar(nb + 48);
    if (nb >= 10) {
        my_put_longlong_nbr(nb / 10);
        my_put_longlong_nbr(nb % 10);
    }
    return (nb);
}
