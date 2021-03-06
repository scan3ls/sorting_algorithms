#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: list
 * @size: size of list
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, (int)size - 1, size);
}

/**
 * quicksort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @a: array
 * @low: low
 * @hi: high
 * @size: size of array
 */
void quicksort(int *a, int low, int hi, size_t size)
{
	int p;

	if (low < hi)
	{
		p = partition(a, low, hi, size);
		quicksort(a, low, p - 1, size);
		quicksort(a, p + 1, hi, size);
	}
}

/**
 * partition - implementing the Lomuto partition scheme
 * @a: array
 * @low: low
 * @hi: high
 * @size: size of array
 * Return: index at which swap happens
 */
int partition(int *a, int low, int hi, size_t size)
{
	int pivot, temp, i, j;

	pivot = a[hi];
	i = low;
	for (j = low; j < hi; j += 1)
	{
		if (a[j] < pivot)
		{
			if (a[i] != a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				print_array(a, size);
			}
			i += 1;
		}
	}
	if (a[i] == a[hi])
		return (i);
	temp = a[i];
	a[i] = a[hi];
	a[hi] = temp;
	print_array(a, size);
	return (i);
}
