#include "main.h"

/**
 * print_binary - a function that prints the bin equivalent of a dec
 * @n: num 2b displayed in binary
 */
void print_binary(unsigned long int n)
{
	int x, it_loop_count = 0;
	unsigned long int result;

	for (x = 63; x >= 0; x--)
	{
		result = n >> x;

		if (result & 1)
		{
			_putchar('1');
			it_loop_count++;
		}
		else if (it_loop_count)
			_putchar('0');
	}
	if (!it_loop_count)
		_putchar('0');
}
