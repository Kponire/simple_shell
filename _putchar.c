#include "shell.h"

/**
 * _putchar - function that prints to the console
 * @c: the character c
 * Return: 1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
