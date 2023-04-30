#include "lists.h"

/**
 * sum_listint - this function calculates the sum,
 * of all the data(n) in a listint_t list
 * @head: first node in the linked list
 *
 * Return: resulting sum
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temporary = head;

	while (temporary)
	{
		sum += temporary->n;
		temporary = temporary->next;
	}

	return (sum);
}
