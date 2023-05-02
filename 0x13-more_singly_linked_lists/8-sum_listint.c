#include "lists.h"

/**
 * sum_listint - total result of item inside a listint_t list
 * @head_v: 1st node
 *
 * Return: final total result
 */
int sum_listint(listint_t *head_v)
{
	int total = 0;
	listint_t *temporary = head_v;

	while (temp_v)
	{
		total += temporary->numer;
		temporary = temporary->next;
	}

	return (total);
}
