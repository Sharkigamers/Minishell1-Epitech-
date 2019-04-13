/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** strcmp and strncmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0')) {
        if (s1[i] != '\0' && s2[i] == '\0')
            return 1;
        if (s1[i] == '\0' && s2[i] != '\0')
            return -1;
        i += 1;
    }
    if (s1[i] == s2[i])
        return 0;
    if (s1[i] > s2[i])
        return 1;
    else
        return -1;
}

int my_strncmp(char const *s1, char const *s2, char const stop_str)
{
    int i = 0;

    while (s1[i] != stop_str && s2[i] != '\0' && s1[i] == s2[i]) {
        if (s1[i] != stop_str && s2[i] == '\0')
            return 1;
        if (s1[i] == stop_str && s2[i] != '\0')
            return -1;
        i += 1;
    }
    if (s1[i] == stop_str && s2[i] == '\0')
        return 0;
    if (s1[i] > s2[i])
        return 1;
    else
        return -1;
}

int my_strdbncmp(char const *s1, char const *s2, char stop_s1, char stop_s2)
{
    int i = 0;

    while (s1[i] != stop_s1 && s2[i] != stop_s2 &&
            s2[i] != '\0' && s1[i] == s2[i]) {
        if ((s1[i] != stop_s1 && s2[i] == stop_s2) ||
            (s1[i] != stop_s1 && s2[i] == '\0'))
            return 1;
        if ((s1[i] == stop_s1 && s2[i] != '\0') ||
            (s1[i] == stop_s1 && s2[i] != stop_s2))
            return -1;
        i += 1;
    }
    if ((s1[i] == stop_s1 && s2[i] == '\0') ||
        (s1[i] == stop_s1 && s2[i] == stop_s2))
        return 0;
    if (s1[i] > s2[i])
        return 1;
    else
        return -1;
}

int my_strcmpn(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0') || n > 0) {
        n -= 1;
        if (s1[i] != '\0' && s2[i] == '\0')
            return 1;
        if (s1[i] == '\0' && s2[i] != '\0')
            return -1;
        i += 1;
    }
    i -= 1;
    if (s1[i] == s2[i])
        return 0;
    if (s1[i] > s2[i])
        return 1;
    else
        return -1;
}
