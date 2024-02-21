#include "sort.h"
/**
 * insertion_sort_list - Sorts a list of integers
 * using insertion sort algorithm
 *
 * @list: list of integers to be sorted
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *next, *sorted, *sorted_prev;
if (list == NULL || *list == NULL)
return;
current = *list;
next = current->next;
/* The sorted list starts with the first node */
sorted = current;
sorted_prev = NULL;
while (next != NULL)
{
/*If the current node is smaller
* than the previous node in the sorted list,
* we need to insert it before that node*/
if (current->n < sorted_prev->n)
{
/* Remove the current node from the list */
if (current->prev != NULL)
current->prev->next = current->next;
if (current->next != NULL)
current->next->prev = current->prev;
if (sorted_prev->prev != NULL)
sorted_prev->prev->next = current;
if (sorted == current)
sorted = current->next;
current->prev = sorted_prev->prev;
current->next = sorted_prev;
if (sorted_prev->prev != NULL)
sorted_prev->prev = current;
else
*list = current;
sorted_prev = current;
}
else 
{
/* Otherwise, we just need to update the sorted_prev pointer */
sorted_prev = next;
}
/* Move to the next pair of nodes */
current = next;
next = current->next;
}
}
