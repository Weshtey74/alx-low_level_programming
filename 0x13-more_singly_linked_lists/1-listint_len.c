#include "lists.h"

/**
 * listint_len - this function that the number of elements in a linked listint_t list
 * @h: the linked list 'listint_t' to traverse
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t numb = 0;

	while (h)
	{
		numb++;
		h = h->next;
	}

	return (numb);
}
