#include "lists.h"

/**
 * find_listint_loop - find the linked list a loop
 * @head: the head of the linked list
 *
 * Return: the addres of the node or null
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (head == NULL || head->next == NULL)
		return (NULL);

	slow = head;
	fast = head;
	slow = slow->next;
	fast = fast->next->next;

	while(fast && fast->next)
	{

		if (fast == slow)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast != slow)
		return (NULL);

	slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
