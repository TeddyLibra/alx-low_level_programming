#include "main.h"

/**
 * binary_to_uint - function to convert bin-unsi_int
 * @b: the binary number to be converted
 * Return: result that will be returned
 */
unsigned int binary_to_uint(const char *b)
{
	int loop_var;
	unsigned int rusult = 0;

	if (!b)
		return (0);

	for (loop_var = 0; b[loop_var]; loop_var++)
	{
		if (b[loop_var] < '0' || b[loop_var] > '1')
			return (0);
		rusult = 2 * rusult + (b[loop_var] - '0');
	}

	return (rusult);
}
