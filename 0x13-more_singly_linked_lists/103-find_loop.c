#include "lists.h"

/**
 * find_listint_loop - this function finds the loop in linked list
 * @head: the linked list to be searched
 * Return: the address to node where loop starts,
 * or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slowly = head;
	listint_t *faster = head;

	if (!head)
		return (NULL);

	while (slowly && faster && faster->next)
	{
		faster = faster->next->next;
		slowly = slowly->next;
		if (faster == slowly)
		{
			slowly = head;
			while (slowly != faster)
			{
				slowly = slowly->next;
				faster = faster->next;
			}
			return (faster);
		}
	}

	return (NULL);
}
