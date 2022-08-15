#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - Add a new node at the beginning of a list.
 * @head: The first node of a list.
 * @n: Input to the new node.
 *
 * Return: Address for the new node.
 **/

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *tp;

	tp = malloc(sizeof(listint_t));
	if (tp == NULL)
		return (NULL);

	tp->n = n;
	tp->next = *head;
	*head = tp;
	return (*head);
}
