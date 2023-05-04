#include "main.h"

/**
 * print_binary - display binary\'s equivalent dec
 * @n: the number will be displayed
 */
void print_binary(unsigned long int n)
{
	int x, rep = 0;
	unsigned long int converted_re;

	for (x = 63; x >= 0; x--)
	{
		converted_re = n >> x;

		if (converted_re & 1)
		{
			_putchar('1');
			rep++;
		}
		else if (rep)
			_putchar('0');
	}
	if (!rep)
		_putchar('0');
}
