#include "sort.h"

/**
 * swap_ints - An array to swap two integers.
 * @a: First order integer pointer to arguments
 * @b: Second order integer pointer to argument
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Array of integers to carry out Shell Sort algorithm.
 *
 * @array: The integer array that needs to be sorted.
 * @size: This is the array size.
 *
 * Description: Array is printed using the Knuth interval sequence.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
