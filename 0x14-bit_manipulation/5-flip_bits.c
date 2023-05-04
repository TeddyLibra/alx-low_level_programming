#include "main.h"

/**
 * flip_bits - a function that returns the number of bits you
 * would need to flip to get from one number to another
 * @n: 1st num
 * @m: 2nd num
 * Return: numbe 2b changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, iter_counter = 0;
	unsigned long int result;
	unsigned long int total = n ^ m;

	for (x = 63; x >= 0; x--)
	{
		result = total >> x;
		if (result & 1)
			iter_counter++;
	}

	return (iter_counter);
}
