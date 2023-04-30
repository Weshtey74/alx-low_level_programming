#include "lists.h"

/**
*listint_len - this function returns number of elements linked in listint_t
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
