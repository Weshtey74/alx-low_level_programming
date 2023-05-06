#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - this function prints a listint_t linked list
 * with a loop
 * @head: A pointer to the head of the listint_t to check.
 * Return: If list is not looped - 0.
 * Otherwise - no. of unique nodes in the list.
 */

size_t looped_listint_len(const listint_t *head)
{
	const listint_t *wolf, *pig;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	wolf = head->next;
	pig = (head->next)->next;

	while (pig)
	{
		if (wolf == pig)
		{
			wolf = head;
			while (wolf != pig)
			{
				nodes++;
				wolf = wolf->next;
				pig = pig->next;
			}

			wolf = wolf->next;
			while (wolf != pig)
			{
				nodes++;
				wolf = wolf->next;
			}

			return (nodes);
		}

		wolf = wolf->next;
		pig = (pig->next)->next;
	}
	return (0);
}

/**
 * print_listint_safe - this function prints a listint_t list safely.
 * @head: the pointer to head of list.
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	nodes = looped_listint_len(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}
