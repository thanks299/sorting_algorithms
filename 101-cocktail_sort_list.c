#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list
 * of integers in ascending order
 * using the Cocktail shaker sort algorithm
 * @list: Pointer to the first node of the list
 *
 * Return: None
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *start, *end, *current, *next;
int swapped;
/* Check if list is NULL or empty */
if (list == NULL || *list == NULL)
return;
start = *list;
end = NULL;
do
{
swapped = 0;
/* Move from start to end of the list */
current = start;
while (current->next != end)
{
if (current->n > current->next->n)
{
/* Swap nodes */
next = current->next;
current->next = next->next;
next->prev = current->prev;
next->next = current;
current->prev = next;
if (current->prev)
current->prev->next = current;
else
start = current;
if (next->next)
next->next->prev = next;
else
end = next;
swapped = 1;
print_list(*list);
printf("\n");
}
current = current->next;
}
/* Move from end to start of the list */
end = *list;
while (end->prev != start)
{
if (end->n < end->prev->n)
{
/* Swap nodes */
next = end->prev;
end->prev = next->prev;
next->next = end->next;
next->prev = end;
end->next = next;
if (end->next)
end->next->prev = end;
else
start = end;
if (next->prev)
next->prev->next = next;
else
end = next;
swapped = 1;
print_list(*list);
printf("\n");
}
end = end->prev;
}
} while (swapped);
}
