#include "lists.h"

/**
 * add_nodeint_end - function that adds new node at end of listint_t
 * @head: pointer to first element in the list
 * @n: data to insert in the new element
 *
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *lowkey;
	listint_t *temp = *head;

	new = malloc(sizeof(listint_t));
	if (!lowkey)
		return (NULL);

	lowkey->n = n;
	lowkey->next = NULL;

	if (*head == NULL)
	{
		*head = lowkey;
		return (lowkey);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = lowkey;

	return (lowkey);
}
