#include "sort.h"

/**
 * shell_sort - Sorts an array using the Shell sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * Return: None
 */
void shell_sort(int *array, size_t size)
{
size_t i, j, gap;
int temp;
/* Check if array is NULL or size is less than 2 */
if (array == NULL || size < 2)
return;
/* Calculate gap sequence */
for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
;
/* Perform sorting using gap sequence */
while (gap > 0)
{
/* Iterate over array starting from gap index */
for (i = gap; i < size; i++)
{
/* Store current element in temp variable */
temp = array[i];
j = i;
/* Perform insertion sort */
while (j >= gap && array[j - gap] > temp)
{
array[j] = array[j - gap];
j -= gap;
}
/* Store temp in its correct position */
array[j] = temp;
}
/* Print array after each iteration of gap sequence */
print_array(array, size);
gap = (gap - 1) / 3;
printf("\n");
}
}
