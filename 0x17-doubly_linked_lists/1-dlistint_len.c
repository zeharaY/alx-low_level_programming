#include "lists.h"

/**
 * dlistint_len - Counts number of elements in a doubly linked list.
 * @h: head
 *
 * Return: number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes++;
		h = h->next;
	}

	return (nodes);
}
