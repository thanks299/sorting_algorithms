#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: The array to be sorted
 * @array_size: Number of elements in @array
 */
void selection_sort(int *array, size_t array_size)
{
size_t i, j, min_index;
int temp;

if (array == NULL || array_size < 2)
return;

for (i = 0; i < array_size - 1; i++)
{
min_index = i;

for (j = i + 1; j < array_size; j++)
{
if (array[j] < array[min_index])
min_index = j;
}
if (min_index != i)
{
temp = array[i];
array[i] = array[min_index];
array[min_index] = temp;
/* Print the array after each swap */
print_array(array, array_size);
}
}
}
