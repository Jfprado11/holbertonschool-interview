#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 *check_cycle - checks the cycle of linked list
 *@list: the list to be checked
 *
 *Return: 0 if there is not a cycle, 1 if there a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *current = list;
	listint_t *temp = list;

	if (list == NULL)
	{
		return (0);
	}
	while (temp && current && current->next)
	{
		current = current->next->next;
		temp = temp->next;
		if (temp == current)
		{
			return (1);
		}
	}
	return (0);
}