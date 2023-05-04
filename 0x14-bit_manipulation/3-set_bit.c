#include "main.h"

/**
 * set_bit - a function definition that used to sets a bit at a given index to 1
 * @n: a pointer variable that point to the number that will be changed
 * @index: a variable index of bit to make to 1
 * Return: it return one(1) if it is cusccessful and negative one(-1) if it fails
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}

