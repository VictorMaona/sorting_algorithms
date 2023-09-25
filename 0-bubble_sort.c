#include "sort.h"

/**
 * swap_ints - Swaps two int in array with arguments a and b.
 *
 * @a: It accepts the first input argument to swap.
 * @b: It accepts the first input argument to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Algorithm is run using function on array of integers.
 * @size: This represents the array size.
 * @array: to be sorted integers.
 * Description:  Allows to visualize the sorting process.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
