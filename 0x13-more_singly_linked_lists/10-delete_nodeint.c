#include "lists.h"

/**
 * delete_nodeint_at_index - to delete node
 * @head_v: point to 2d 1st element
 * @index_delete: node 2b deleted
 *
 * Return: if success 1 else -1
 */
int delete_nodeint_at_index(listint_t **head_v, unsigned int index_delete)
{
	listint_t *temporary = *head_v;
	listint_t *this_var = NULL;
	unsigned int x = 0;

	if (*head_v == NULL)
		return (-1);

	if (index_delete == 0)
	{
		*head_v = (*head_v)->next;
		free(temporary);
		return (1);
	}

	while (x < index_delete - 1)
	{
		if (!temporary || !(temporary->next))
			return (-1);
		temporary = temporary->next;
		x++;
	}


	this_var = temporary->next;
	temporary->next = this_var->next;
	free(this_var);

	return (1);
}
