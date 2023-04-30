#include "lists.h"

/**
 * get_nodeint_at_index - this function returns the node,
 * at a certain index in a linked list
 * @head: the first node in the linked list
 * @index: index of the node to return
 *
 * Return: points to node being looked for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int z = 0;
	listint_t *temporary = head;

	while (temporary && z < index)
	{
		temporary = temporary->next;
		z++;
	}

	return (temporary ? temporary : NULL);
}
