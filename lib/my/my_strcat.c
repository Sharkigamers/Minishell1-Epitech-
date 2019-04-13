/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** strcat
*/

char *my_strcat(char const *dest, char const *src, char *save)
{
    int i = 0;

    for (; dest[i] != '\0'; i++)
        save[i] = dest[i];
    for (int count = 0; src[count] != '\0'; count++, i++)
        save[i] = src[count];
    save[i] = '\0';
    return (save);
}

char *my_realstrcat(char *dest, char const *src)
{
    int i = 0;
    int count = 0;

    for (; dest[i] != '\0'; i++);
    while (src[count] != '\0') {
        dest[i] = src[count];
        count += 1;
        i += 1;
    }
    dest[i] = '\0';
    return (dest);
}
