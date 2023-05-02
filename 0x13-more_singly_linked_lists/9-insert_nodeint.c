#include "lists.h"

/**
 * insert_nodeint_at_index - 2insert node at specified place
 * @head_v: pointer of 1st node
 * @idex_of_new: index where the new node is added
 * @numer: inserted node
 *
 * Return: pointer 2new_node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head_v, unsigned int idex_of_new, int numer)
{
	unsigned int x;
	listint_t *new_node;
	listint_t *temporary = *head_v;

	new_node = malloc(sizeof(listint_t));
	if (!new_node || !head_v)
		return (NULL);

	new_node->numer = numer;
	new_node->next = NULL;

	if (index_of_new == 0)
	{
		new_node->next = *head_v;
		*head = new;
		return (new_node);
	}

	for (x = 0; temporary && x < index_of_new; x++)
	{
		if (x == index_of_new - 1)
		{
			new_node->next = temporary->next;
			temporary->next = new_node;
			return (new_node);
		}
		else
			temporary = temporay->next;
	}

	return (NULL);
}

