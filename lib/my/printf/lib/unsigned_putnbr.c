/*
** EPITECH PROJECT, 2018
** unsigned_putnbr
** File description:
** make the same than put nbr but with unsigned int
*/

void my_putchar(char c);

unsigned int unsigned_putnbr(unsigned int nb)
{
    if (nb <= 9 && nb >= 0)
        my_putchar(nb + 48);
    if (nb >= 10) {
        unsigned_putnbr(nb / 10);
        unsigned_putnbr(nb % 10);
    }
    return (nb);
}
