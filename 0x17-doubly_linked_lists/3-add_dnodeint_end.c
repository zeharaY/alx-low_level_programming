#include "lists.h"

/**
 * add_dnodeint_end - Adds a node at the end
 * @head: A pointer to the head
 * @n: new node content.
 *
 * Return: NULL or address of the new node.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *last;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;

	return (new);
}
