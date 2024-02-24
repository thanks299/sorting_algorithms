#include "sort.h"

/**
 * swap_nodes - Helper function to swap two nodes in a doubly-linked list
 * @a: First node
 * @b: Second node
 *
 * Description: This function swaps the positions of two nodes in a
 *              doubly-linked list.
 */
void swap_nodes(listint_t *a, listint_t *b)
{
    if (a->prev)
        a->prev->next = b;
    if (b->next)
        b->next->prev = a;
    a->next = b->next;
    b->prev = a->prev;
    a->prev = b;
    b->next = a;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using cocktail shaker sort
 * @list: Pointer to the head of the list
 *
 * Description: This function sorts a doubly linked list using the cocktail
 *              shaker sort algorithm.
 */
void cocktail_sort_list(listint_t **list)
{
    if (!list || !*list || !(*list)->next)
        return;
    
    listint_t *current;
    listint_t *start = NULL;
    listint_t *end = NULL;

    do {
        swapped = 0;
        current = *list;

        while (current->next != end) {
            if (current->n > current->next->n) {
                swap_nodes(current, current->next);
                if (!start)
                    start = current;
                swapped = 1;
                print_list(*list);
            } else {
                current = current->next;
            }
        }

        end = current;

        if (!swapped)
            break;

        swapped = 0;
        current = end;

        while (current->prev != start) {
            if (current->n < current->prev->n) {
                swap_nodes(current->prev, current);
                swapped = 1;
                print_list(*list);
            } else {
                current = current->prev;
            }
        }

        start = current;
    } while (swapped);
}
