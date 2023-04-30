#include "lists.h"

/**
 * delete_nodeint_at_index - this function deletes the node,
 * at index index of a linked list
 * @head: the first element in the list
 * @index: index of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temporary = *head;
	listint_t *cirr = NULL;
	unsigned int x = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temporary);
		return (1);
	}

	while (x < index - 1)
	{
		if (!temporary || !(temporary->next))
			return (-1);
		temporary = temporary->next;
		x++;
	}


	cirr = temporary->next;
	temporary->next = cirr->next;
	free(cirr);

	return (1);
}
