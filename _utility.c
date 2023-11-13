#include "shell.h"

/**
 * print_int - writes integer to the console
 * @number: the input number
 */

void print_int(unsigned int number)
{
	int sum = 0, x = 1;

	if ((int)number < 0)
	{
		number *= -1;
		_putchar('-');
		sum++;
	}
	while ((number / x) > 9)
		x *= 10;
	while (x >= 1)
	{
		_putchar('0' + ((number / x) % 10));
		x /= 10;
		sum++;
	}
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
