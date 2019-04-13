/*
** EPITECH PROJECT, 2018
** my_octet
** File description:
** put_octet like my_put_str but for octet
*/

void my_putchar(char c);

unsigned int my_octal(unsigned int nb)
{
    if (nb >= 8) {
        my_octal(nb / 8);
        my_octal(nb % 8);
    }
    else
        my_putchar(nb + 48);
    return (nb);
}
