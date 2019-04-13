/*
** EPITECH PROJECT, 2018
** my_put_char_nbr
** File description:
** putnb
*/

void my_putchar(char c);

char my_put_char_nbr(char nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb <= 9 && nb >= 0)
        my_putchar(nb + 48);
    if (nb >= 10) {
        my_put_char_nbr(nb / 10);
        my_put_char_nbr(nb % 10);
    }
    return (nb);
}
