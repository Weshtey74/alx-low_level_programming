#include "lists.h"

/**
 * add_nodeint - function that adds a new node at beginning of listint_t
 * @head: pointer to the first node in the list
 * @n: the data to insert in new node
 *
 * Return: address of new element, or NULL if failed
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *perfect;

	perfect = malloc(sizeof(listint_t));
	if (!perfect)
		return (NULL);

	perfect->n = n;
	perfect->next = *head;
	*head = perfect;

	return (perfect);
}
