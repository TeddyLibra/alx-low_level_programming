#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @head_v: pointer 2d listint_t 2b deallocated
 */
void free_listint2(listint_t **head_v)
{
	listint_t *temporary;

	if (head_v == NULL)
		return;

	while (*head_v)
	{
		temporary = (*head_v)->next;
		free(*head_v);
		*head_v = temporary;
	}

	*head_v = NULL;
}
