#include "lists.h"

/**
 * get_nodeint_at_index - depending specified index node will be returned
 * @head_v: 1st node
 * @index: node index 2b return
 *
 * Return: pointer 2searched item, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head_v, unsigned int index_node)
{
	unsigned int x = 0;
	listint_t *temporary = head_v;

	while (temporary && x < index_node)
	{
		temporary = temporary->next;
		x++;
	}

	return (temporary ? temporary : NULL);
}
