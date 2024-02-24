#include "sort.h"

/**
 * swap_nodes - helper function that sw two nodes in a doubly-linked list
 * @a: first node
 * @b: second node
 */
void swap_nodes(listint_t *a, listint_t *b)
{
	/* If the first node has a previous node, its next pointer */
	if (a->prev)
		a->prev->next = b;

	/* If the second node has a next node, update its previous pointer */
	if (b->next)
		b->next->prev = a;

	/* Update the pointers of the first node */
	a->next = b->next;
	b->prev = a->prev;

	/* Update the pointers of the second node */
	a->prev = b;
	b->next = a;
}

/**
 * tail_reversal - helper function that sorts from the tail back
 * @head: head
 * @tail: tail
 * @list: initial head of the list
 * Return: list head
 */
listint_t *tail_reversal(listint_t *head, listint_t *tail, listint_t *list)
{
	/* Traverse the list from the tail back to the head */
	while (tail && tail->prev)
	{
		/* If the current node is greater than its previous node */
		if (tail->n < tail->prev->n)
		{
			/* Swap the current node with its previous node */
			swap_nodes(tail->prev, tail);

			/* If the current node is the new head of the list */
			if (tail->prev == NULL)
				list = tail;

			/* Print the list after each swap */
			print_list(list);
		}

		/* Move to the previous node */
		tail = tail->prev;

		/* If the previous node is the new head of the list */
		if (tail->prev == NULL)
			head = tail;
	}

	/* Return the new head of the list */
	return (head);
}

/**
 * cocktail_sort_list - sorts a doubly linked list using cocktail shaker sort
 * @list: doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *head, *length;
	int u = 0, v = 0, swapped = 1;

	/* Check if the list is empty or has only one node */
	if (!list || !*list)
		return;

	/* Get the length of the list */
	length = *list;
	for (u = 0; length; u++)
	{
		length = length->next;
	}

	/* Return if the list has less than 2 nodes */
	if (u < 2)
		return;

	/* Initialize the head and tail pointers */
	head = *list;
	tail = NULL;

	/* Perform the cocktail shaker sort algorithm */
	while (v < u)
	{
		/* Start from the head and swap nodes if necessary */
		swapped = 0;
		while (head && head->next)
		{
			/* If the current node is greater than its next node */
			if (head->n > head->next->n)
			{
				/* Swap the current node with its next node */
				swap_nodes(head, head->next);

				/* Update the head and tail pointers */
				swapped++;
				if (head->prev->prev == NULL)
					*list = head->prev;

				/* Print the list after each swap */
				print_list(*list);
			}

			/* Move to the next node */
			head = head->next;
		}

		/* If no nodes were swapped,
