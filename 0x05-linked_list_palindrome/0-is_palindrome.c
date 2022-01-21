#include "lists.h"

/**
 * is_palindrome - check if a linked list is a palidrome or not
 * @head: the head of the palindrome
 * Return: 1 if is palidrone or 0 if not
 */

int is_palindrome(listint_t **head)
{
	listint_t *aux = *head;
	int first_node = 0, second_node = 0, len, status = 0;
	int array_of_num[BUFSIZ];

	while (aux)
	{
		array_of_num[first_node] = aux->n;
		aux = aux->next;
		first_node += 1;
	}
	if (first_node == 0 || first_node == 1)
		return (1);
	first_node -= 1;
	len = first_node;
	while (second_node < len)
	{
		if (array_of_num[second_node++] == array_of_num[first_node--])
			status = 1;
		else
			return (0);
	}
	return (status);
}
