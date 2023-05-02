#include "lists.h"

/**
 * add_nodeint_end - adds a node @the end
 * @head_v: point 2the 1st element
 * @numer: data 2b inserted
 *
 * Return: pointer 2new node, or NULL for failarity
 */
listint_t *add_nodeint_end(listint_t **head_v, const int numer)
{
	listint_t *new_node;
	listint_t *temporary = *head_v;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->numer = numer;
	new_node->next = NULL;

	if (*head_v == NULL)
	{
		*head_v = new_node;
		return (new_node);
	}

	while (temporary->next)
		temporary = temporary->next;

	temporary->next = new_node;

	return (new_node);
}
