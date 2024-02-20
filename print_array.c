#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 * @arr: The array to be printed
 * @arr_len: Number of elements in @arr
 */
void print_array(const int *arr, size_t arr_len)
{
	size_t i;

	i = 0;
	while (arr && i < arr_len)
	{
		if (i > 0)
			printf(", ");
		printf("%d", arr[i]);
		++i;
	}
	printf("\n");
}
