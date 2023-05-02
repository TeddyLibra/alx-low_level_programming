#include "lists.h"

/**
 * listint_len - it returns number of elements
 * @head_va: type listint_t to traverse
 *
 * Return: it rerutn number of nodes
 */
size_t listint_len(const listint_t *head_var)
{
	size_t numer = 0;

	while (head_var)
	{
		numer++;
		head_var = head_var->next;
	}

	return (numer);
}
