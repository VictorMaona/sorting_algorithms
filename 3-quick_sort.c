#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Two integers in an array can be switched.
 * @a: Requires parameter first integer pointer.
 * @b: Requires parameter second integer pointer.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - divides the array into two smaller arrays.
 *
 * @array: The integer array.
 * @size: The array dimensions.
 * @left: The array partition initial index for sorting.
 * @right: The array partition final index for sorting.
 *
 * Return: Final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *driver, up, down;

	driver = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *driver)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *driver)
	{
		swap_ints(array + up, driver);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - To launch the Quicksort procedure.
 * @array: The integer array.
 * @size: The array size is
 * @left: The array partition initial index for sorting.
 * @right: The array partition final index for sorting.
 * Description: Implement Quicksort and output the array.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, belong - 1);
		lomuto_sort(array, size, belong + 1, right);
	}
}

/**
 * quick_sort -  Quicksort algorithm applied to an array of integers.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: to start the Quicksort operation.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
