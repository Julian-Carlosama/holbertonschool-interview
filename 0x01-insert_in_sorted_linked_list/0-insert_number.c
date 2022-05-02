#include "lists.h"


/**
 * insert_node - Put the node in a position sorted
 * @head: Head of list
 * @number: Number of the new node
 *
 * Return: New node
 */
listint_t *insert_node(listint_t **head, int number){
	listint_t *newNode = malloc(sizeof(listint_t));

    /* Checks if this node is the head */
	if (!newNode)
		return (NULL);

	newNode->n = number;
	newNode->next = NULL;

	/* Check if the first is NULL and If the First is Bigger the New */
	if (!(*head) || (*head)->n >= newNode->n)
	{
		newNode->next = *head;
		*head = newNode;
		return (newNode);
	}
	else
	{
		listint_t *curr = *head;
		/* Get the position of the next bigger */
		while (curr->next != NULL && curr->next->n < newNode->n)
			curr = curr->next;

		newNode->next = curr->next;
		curr->next = newNode;

		return (newNode);
	}

	return (NULL);
}