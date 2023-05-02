#include "lists.h"

/**
 * print_listint - it prints all the elements
 * @h: type listint_t to print
 *
 * Return: it ruturn number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t number = 0;

	while (h)
	{
		printf("%d\n", h->n);
		number++;
		h = h->next;
	}

	return (number);
}
