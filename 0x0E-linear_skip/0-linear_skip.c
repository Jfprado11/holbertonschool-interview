#include "search.h"

/**
 * linear_skip - search in a skip list a value
 * @list: a pointer to the head of the list
 * @value: the value to search for
 * Return: a pointer to the node whose containt the value searching for
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *skip_node;

	if (list == NULL)
		return (NULL);

	node = list;
	while (node)
	{
		if (node->n > value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
			skip_node->index, node->index);
			while (skip_node->n <= node->n)
			{
				printf("Value checked at index [%lu] = [%d]\n",
				skip_node->index, skip_node->n);
				if (skip_node->n == value)
					return (skip_node);
				skip_node = skip_node->next;
			}
			break;
		}
		skip_node = node;
		node = node->express;
		if (node != NULL)
			printf("Value checked at index [%lu] = [%d]\n",
		node->index, node->n);
	}
	node = skip_node;
	while (node->next)
	{
		node = node->next;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	skip_node->index, node->index);
	while (skip_node && skip_node->n <= node->n)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		skip_node->index, skip_node->n);
		if (skip_node->n == value)
			return (skip_node);
		skip_node = skip_node->next;
	}
	return (NULL);
}
