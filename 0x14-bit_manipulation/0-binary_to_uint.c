#include "main.h"

/**
 * binary_to_uint - binary 2unsignedint 
 * @binary: the binary number in string
 *
 * Return: the result
 */
unsigned int binary_to_uint(const char *binary)
{
	int x;
	unsigned int dec_num = 0;

	if (!binary)
		return (0);

	for (x = 0; binary[x]; x++)
	{
		if (binary[x] < '0' || binary[x] > '1')
			return (0);
		dec_num = 2 * dec_val + (binary[x] - '0');
	}

	return (dec_num);
}
