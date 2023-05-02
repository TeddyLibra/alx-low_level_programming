#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @head_p: pointer to the first node in the linked list
 *
 * Return: elements number in the freed list
 */
size_t free_listint_safe(listint_t **head_p)
{
	size_t len = 0;
	int diff;
	listint_t *temporary;

	if (!head_p || !*head_p)
		return (0);

	while (*head_p)
	{
		diff = *head_p - (*head_p)->next;
		if (diff > 0)
		{
			temporary = (*head_p)->next;
			free(*head_p);
			*head_p = temporary;
			len++;
		}
		else
		{
			free(*head_p);
			*head_p = NULL;
			len++;
			break;
		}
	}

	*head_p = NULL;
