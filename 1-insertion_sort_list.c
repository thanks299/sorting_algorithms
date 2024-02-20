#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using
 *                        the Insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *unsorted_node, *sorted_node;

	if (!list || !*list || !(*list)->next)
		return;

	unsorted_node = (*list)->next;
	sorted_node = *list;

	while (unsorted_node)
	{
		sorted_node = unsorted_node->prev;

		while (sorted_node && sorted_node->n > unsorted_node->n)
		{
			/* Remove unsorted_node from the list */
			if (unsorted_node->prev)
				unsorted_node->prev->next = unsorted_node->next;
			if (unsorted_node->next)
				unsorted_node->next->prev = unsorted_node->prev;

			/* Insert unsorted_node before sorted_node */
			unsorted_node->next = sorted_node;
			unsorted_node->prev = sorted_node->prev;

			sorted_node->prev = unsorted_node;
			if (unsorted_node->prev)
				unsorted_node->prev->next = unsorted_node;
			else
				*list = unsorted_node;

			print_list(*list);

			sorted_node = unsorted_node->prev;
		}

		unsorted_node = unsorted_node->next;
	}
}

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}
