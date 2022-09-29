#include "lists.h"

/**
 * free_dlistint - Frees the list.
 * @head: The head the list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
