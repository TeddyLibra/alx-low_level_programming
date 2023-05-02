#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - It counts the number of unique nodes in loop
 * @head_v: A pointer 2head
 * Return: 0 If not looped else unique nodes
 */
size_t looped_listint_len(const listint_t *head_v)
{
	const listint_t *tortoise, *hare;
	size_t nodes = 1;

	if (head_v == NULL || head_v->next == NULL)
		return (0);

	tortoise = head_v->next;
	hare = (head_v->next)->next;

	while (hare)
	{
		if (tortoise == hare)
		{
			tortoise = head_v;
			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
				hare = hare->next;
			}

			tortoise = tortoise->next;
			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
			}

			return (nodes);
		}

		tortoise = tortoise->next;
		hare = (hare->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head_v: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head_v)
{
	size_t nodes, index = 0;

	nodes = looped_listint_len(head_v);

	if (nodes == 0)
	{
		for (; head_v != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head_v, head_v->n);
			head_v = head_v->next;
		}
	}

	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}
