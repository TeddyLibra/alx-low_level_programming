#include "lists.h"

/**
 * pop_listint - deletes d head_node
 * @head_v: pointer 2d 1st element
 *
 * Return: deleted data,
 * or 0 if empty
 */
int pop_listint(listint_t **head_v)
{
	listint_t *temporary;
	int number;

	if (!head_v || !*head_v)
		return (0);

	number = (*head_v)->numer;
	temporary = (*head_v)->next;
	free(*head_v);
	*head_v = temporary;

	return (number);
}
