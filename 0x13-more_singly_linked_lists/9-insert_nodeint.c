#include "lists.h"

/**
 * insert_nodeint_at_index - this function inserts a new node,
 * at a given position
 * @head: points the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int u;
	listint_t *perfect;
	listint_t *temporary = *head;

	perfect = malloc(sizeof(listint_t));
	if (!perfect || !head)
		return (NULL);

	perfect->n = n;
	perfect->next = NULL;

	if (idx == 0)
	{
		perfect->next = *head;
		*head = perfect;
		return (perfect);
	}

	for (u = 0; temporary && u < idx; u++)
	{
		if (u == idx - 1)
		{
			perfect->next = temporary->next;
			temporary->next = perfect;
			return (perfect);
		}
		else
			temporary = temporary->next;
	}

	return (NULL);
}
