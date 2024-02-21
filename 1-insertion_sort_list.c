#include "sort.h"
#include <stdio.h>

/*****
 * insert_sort_list - sorts a list of integers
 * using insertion sort algorithm
 *
 * @list: list of integers to be sorted
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
listint_t *sorted, *unsorted;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
sorted = *list;
unsorted = sorted->next;
while (unsorted != NULL)
{
listint_t *prev = unsorted->prev;
listint_t *current = sorted;
/* Find the correct position to insert unsorted node */
while (current != unsorted && current->n < unsorted->n)
{
prev = current;
current = current->next;
}
/* Remove unsorted node from the list */
if (prev != NULL)
prev->next = unsorted->next;
else
*list = unsorted->next;
/* Insert unsorted node in the correct position */
if (current != NULL)
{
unsorted->next = current;
unsorted->prev = current->prev;
current->prev = unsorted;
if (unsorted->prev != NULL)
unsorted->prev->next = unsorted;       
else
*list = unsorted;
}
print_list(*list);
unsorted = unsorted->next;
}
}
