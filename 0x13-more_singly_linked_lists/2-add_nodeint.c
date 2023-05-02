#include "lists.h"

/**
 * add_nodeint - adds a new node@ beginning
 * @head_v: it point to 1st node
 * @numer: data to 2b inserted
 *
 * Return: pointer 2new node, or NULL for failarity
 */
listint_t *add_nodeint(listint_t **head_v, const int numer)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->numer = numer;
	new_node->next = *head_v;
	*head_v = new_node;

	return (new_node);
}
