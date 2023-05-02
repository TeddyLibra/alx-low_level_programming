#include "lists.h"

/**
 * reverse_listint - it reverse items
 * @head_v: it pointes 2d 1st node
 *
 * Return: pointer to the reversed list
 */
listint_t *reverse_listint(listint_t **head_v)
{
	listint_t *previous_node = NULL;
	listint_t *next_node = NULL;

	while (*head_v)
	{
		next_node = (*head_v)->next;
		(*head_v)->next = previous_node;
		previous = *head_v;
		*head_v = next_node;
	}

	*head_v = prev_node;

	return (*head_v);
}
