#include "shell.h"

void print_int(unsigned int number)
{
	int sum = 0, x = 1;

	if ((int)number < 0)
	{
		number *= -1;
		putchar('-');
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
