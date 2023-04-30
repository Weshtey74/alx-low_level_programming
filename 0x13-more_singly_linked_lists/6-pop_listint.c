#include "lists.h"

/**
 * pop_listint - this function deletes head node of linked list,
 * returns the head node’s data (n)
 * @head: the first element in the linked list
 *
 * Return: the data inside the elements that was deleted,
 * or 0 if the list is empty
 */

int pop_listint(listint_t **head)
{
	listint_t *temporary;
	int numb;

	if (!head || !*head)
		return (0);

	numb = (*head)->n;
	temporary = (*head)->next;
	free(*head);
	*head = temporary;

	return (numb);
}
