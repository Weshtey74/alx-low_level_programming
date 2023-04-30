#include "lists.h"

/**
 * free_listint - function that frees a listint_t
 * @head: the listint_t list should be freed
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
