#include "lists.h"

/**
 * insert_node - a function to insert a node in a sorted linked list
 * @head: the head of the list
 * @number: the number to be inserte4d
 * Return: the addres of the new pointer
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp = NULL;
	listint_t *node = NULL;

	if (*head == NULL) {
		return (NULL);
	}

	node = malloc(sizeof(listint_t));
	if (node == NULL)
		return (NULL);
	node->n = number;

	tmp = *(head);
	if (tmp->n >= number)
	{
		node->next = tmp;
		*(head) = node;
		return (node);
	}
	while (tmp->next != NULL) {
		if (tmp->next->n >= number)
		{
			node->next = tmp->next;
			tmp->next = node;
			return (node);
		}
		tmp = tmp->next;
	}
	tmp->next = node;
	node->next = NULL;
	return (node);
}