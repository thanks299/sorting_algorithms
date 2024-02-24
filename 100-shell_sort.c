#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *  using the Shell sort algorithm with the Knuth sequence.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	/* Check if array is valid and has at least 2 elements */
	if (!array || size < 2)
		return;

	/* Calculate initial gap using Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Perform the Shell sort algorithm */
	while (gap > 0)
	{
		/* For each element in the array, starting from the gap index */
		for (i = gap; i < size; i++)
		{
			/* Store the current element in a temporary variable */
			temp = array[i];

			/* Compare the current element with the previous elements */
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				/* If the previous element is greater, shift it to the right */
				array[j] = array[j - gap];
				j -= gap;
			}

			/* Insert the current element in its correct position */
			array[j] = temp;
		}

		/* Print the array after each pass */
		print_array(array, size);

		/* Reduce the gap for the next pass */
		gap /= 3;
	}
}
