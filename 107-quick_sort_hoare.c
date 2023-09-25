#include "sort.h"

void swap_ints(int *a, int *b);
void quick_sort_hoare(int *array, size_t size);
void hoare_sort(int *array, size_t size, int left, int right);
int hoare_partition(int *array, size_t size, int left, int right);

/**
 * swap_ints - In an array, swap two integers.
 * @a: The first swappable integer.
 * @b: The second swappable integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - A subset of an integer array should be arranged.
 * @array: Array of integers.
 * @size: Size of array.
 * @left: The subset starting index is used to sort.
 * @right: The array partitioning order last index.
 * Return: The last index of the partition.
 *
 * Description:  The partitions final component as the driver.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int driver, up, down;

	driver = array[right];
	for (up = left - 1, down = right + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < driver);
		do {
			down--;
		} while (array[down] > driver);

		if (up < down)
		{
			swap_ints(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * hoare_sort - Utilize recursion to carry out quicksort algorithm.
 * @array: Set of integers in an array.
 * @size: Size of array.
 * @left: The array partition order starting index.
 * @right: The array partitioning order last index.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, belong - 1);
		hoare_sort(array, size, belong, right);
	}
}

/**
 * quick_sort_hoare -Technique to ascendantly sort an array of numbers.
 * @array: Array of integers.
 * @size: Size of array.
 *
 * Description: printed using the Hoare partitioning method.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
