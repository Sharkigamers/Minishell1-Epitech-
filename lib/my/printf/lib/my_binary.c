/*
** EPITECH PROJECT, 2018
** my_binary
** File description:
** make the same than my_putnbr but with binary
*/

void my_putchar(char c);

unsigned int my_binary(unsigned int nb)
{
    if (nb < 2 && nb >= 0)
        my_putchar(nb + 48);
    if (nb >= 2) {
        my_binary(nb / 2);
        my_binary(nb % 2);
    }
    return (nb);
}
