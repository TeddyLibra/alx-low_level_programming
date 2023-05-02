#include "lists.h"

/**
 * free_listint - it deallocates linked list
 * @head_v: listint_t list 2b deallocates  
 */
void free_listint(listint_t *head_v)
{
	listint_t *temporary_v;

	while (head_v)
	{
		temporay_v = head_v->next;
		free(head_v);
		head_v = temporary_v;
	}
}
