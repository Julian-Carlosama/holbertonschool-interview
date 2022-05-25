#include "lists.h"
/**
  * is_palindrome - Checks if a singly linked list is a palindrome.
  *
  * @head: Is the double pointer to the first node in a linked list
  *
  * Return: 0 if it is not a palindrome, 1 if it is a palindrome
  */

int is_palindrome(listint_t **head){
	int length_all = palindro_lkd(*head);
	int middle = (length_all / 2), step = 0;
	listint_t *left = *head, *right = NULL;
	size_t k = 0, j = 1;

	if (!middle)
		return (1);

	for (; step < middle; ++step)
	{
		right = *head;

		k = (middle - step);
		/* Get the node of the right */
		for (; (j < k) && (right->next); ++j)
			right = right->next;

		if (left->n != right->n)
			return (0);

		left = left->next;
	}

	return (1);
}

/**
 * palindro_lkd - Look amount of nodes
 * @head: Copy of the Head node
 * Return: Length of the linked list
 */
int palindro_lkd(listint_t *head)
{
	int i = 0;

	for (; head != NULL; ++i, (head = head->next))
		;

	return (i);  
}
