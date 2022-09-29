#include "lists.h"

/**
 * sum_dlistint - Sums all the data of list.
 * @head: The head
 *
 * Return: sum
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
