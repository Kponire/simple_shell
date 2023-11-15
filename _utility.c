#include "shell.h"

/**
 * print_int - writes integer to the console
 * @number: the input number
 */

void print_int(unsigned int number)
{
	int x = 1;

	if ((int)number < 0)
	{
		number *= -1;
		_putchar('-');
	}
	while ((number / x) > 9)
		x *= 10;
	while (x >= 1)
	{
		_putchar('0' + ((number / x) % 10));
		x /= 10;
	}
	_putchar('\n');
}

/**
 * _signal - filters out ctrl c
 * @cmd: command
 */

void _signal(int cmd)
{
	if (cmd == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}

/**
 * _strlen - calculates the length of a string
 * @s: the string
 * Return: length of the string
 */

int _strlen(char *s)
{
	int i;

		for (i = 0; s[i] != '\0'; i++)
		{
			continue;
		}
	return (i);
}
