#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @c: the variable that would be printed
 * Return: return 1 for success and -1 for error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
