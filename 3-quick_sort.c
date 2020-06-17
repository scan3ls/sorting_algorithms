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
 */
void quicksort(int *a, int low, int hi, size_t size)
{
	int p;

	if (low < hi)
	{
		p = partition(a, low, hi, size);
		if (low != p + 1 && hi != p - 1)
		{
			quicksort(a, low, p - 1, size);
			quicksort(a, p + 1, hi, size);
		}
		else
			quicksort(a, low, hi, size);
	}
}

/**
 * partition - implementing the Lomuto partition scheme
 * Return:
 */
int partition(int *a, int low, int hi, size_t size)
{
	int pivot, temp, i, j;
	bool swap = FALSE;

	pivot = a[hi];
	i = low;
	for (j = low; j < hi; j+=1)
	{
		if(a[j] < pivot)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i+=1;
			swap = TRUE;
		}
	}
	if(swap)
	{
		print_array(a, size);
		swap = FALSE;
	}
	if(i == hi && low == hi)
		return (i);
	temp = a[i];
	a[i] = a[hi];
	a[hi] = temp;
	swap = TRUE;
	printf("%d, %d\n", a[i], a[hi]);
	if (swap)
		print_array(a, size);
	return (i);
}
