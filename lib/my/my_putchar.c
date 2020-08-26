/*
** EPITECH PROJECT, 2019
** My_putchar
** File description:
** Displays a character
*/

#include <unistd.h>
#include <stdarg.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
