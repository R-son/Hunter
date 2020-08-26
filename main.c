/*
** EPITECH PROJECT, 2019
** main
** File description:
** launches My_Hunter program
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

int help(void)
{
    char *buffer;
    struct stat st;
    int fd = open("ressources/help.txt", O_RDONLY);

    stat("ressources/help.txt", &st);
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    read(fd, buffer, st.st_size);
    my_putstr(buffer);
    return (0);
}

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;

    if (my_strlen(s1) != my_strlen(s2))
      return (-1);
    for (; s1[a] != '\0' || s2[a] != '\0'; a++)
        if (s1[a] != s2[a])
            return (-1);
    return (1);
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 1) {
        return (help());
    } else if (ac != 1) {
        my_putstr("Invalid number of arguments or invalid argument\n");
        my_putstr("Type ./hunter -h for more informations\n");
        return (84);
    }
    title();
    return (0);
}
