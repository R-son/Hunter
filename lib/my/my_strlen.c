/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** Counts number of characters in a string
*/

int my_strlen(char const *str)
{
    int a = 0;

    for (; str[a] != '\0'; a++);
    return (a);
}
