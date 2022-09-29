#include "lists.h"

/**
 * get_dnodeint_at_index - Locates a node in the list.
 * @head: The head 
 * @index: The index of the node to locate.
 *
 * Return:  NULL or address of the located node.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	for (; index != 0; index--)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
	}

	return (head);
}
