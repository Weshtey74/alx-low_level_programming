
#include "lists.h"

/**
 * free_listint_safe - this function frees a linked list
 * @h: the pointer to 1st node in the linked list
 * Return: the number of elements in freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	int dif;
	listint_t *tempo;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		dif = *h - (*h)->next;
		if (dif > 0)
		{
			tempo = (*h)->next;
			free(*h);
			*h = tempo;
			len++;
		}
		else
		{
			free(*h);
			*h = NULL;
			len++;
			break;
		}
	}

	*h = NULL;

	return (len);
}
