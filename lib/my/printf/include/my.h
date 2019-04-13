/*
** EPITECH PROJECT, 2018
** my_prototypes
** File description:
** all proto
*/
#ifndef TEST_H_
#define TEST_H_

void my_printf(char *fmt, ...);

void detect_first_flags(char *fmt, int *i, va_list ap);
void detect_four_first_flags(char *fmt, int *i, va_list ap);
void detect_four_second_flags(char *fmt, int *i, va_list ap);
void detect_last_flags(char *fmt, int *i, va_list ap);
void cond_i(int i, int save_i, char *fmt);

void annex_replacement(char *str, int i);
void replace_char_non_printable(char *str);

unsigned int my_binary(unsigned int nb);
unsigned int my_octal(unsigned int nb);
unsigned int my_hexa(unsigned int nb);
unsigned int my_sup_hexa(unsigned int nb);
unsigned int unsigned_putnbr(unsigned int nb);
void replace_char_non_printable(char *str);
long my_long_hexa(long nb);

long my_put_long_nbr(long nb);
long long my_put_longlong_nbr(long long nb);
short my_put_short_nbr(short nb);
char my_put_char_nbr(char nb);

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);

void change_length_l(char *fmt, int *i, va_list ap);
void change_length_hd(char *fmt, int *i, va_list ap);
void change_length_hh(char *fmt, int *i, va_list ap);

#endif /* TEST_H_ */
