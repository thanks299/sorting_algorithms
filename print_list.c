#include "sort.h"
/**
 * insertion_sort_list - Sorts a list of integers using insertion sort algorithm
 *
 * @list: list of integers to be sorted
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next;

	if (list == NULL || *list == NULL)
		return;

	current = *list;
	next = current->next;

	while (next != NULL)
	{
		if (current->n > next->n)
	}
 }
