/*
** EPITECH PROJECT, 2018
** my_sup_hexa
** File description:
** make the smae than the sup but for sup
*/

void my_putchar(char c);

unsigned int my_sup_hexa(unsigned int nb)
{
    if (nb >= 16) {
        my_sup_hexa(nb / 16);
        my_sup_hexa(nb % 16);
    }
    else if (nb >= 10 && nb <= 16)
        my_putchar(nb + 55);
    else my_putchar(nb + 48);
    return (nb);
}
