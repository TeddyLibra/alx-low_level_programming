#include "main.h"

/**
 * get_bit - the function that returns value of a bit
 * @n: the value that going to be searched
 * @index: the index
 * Return: result that will be returned
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int the_bit;

	if (index > 63)
		return (-1);

	the_bit = (n >> index) & 1;

	return (the_bit);
}
