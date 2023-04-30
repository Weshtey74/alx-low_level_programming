#include "lists.h"

/**
 *free_listint2 - this function that frees a listint_t
 *@head: pointer is the 'listint_t' list to be freed
 */
void free_listint2(listint_t **head)
{
	listint_t *temporary;

	if (head == NULL)
		return;

	while (*head)
	{
		temporary = (*head)->next;
		free(*head);
		*head = temporary;
	}

	*head = NULL;
}
