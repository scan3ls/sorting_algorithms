#include "sort.h"

/**
 * bubble_sort - implementation of bubble sort
 *@array: array to sort
 *@size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	bool swapped;
	size_t i;
	int temp = 0;

	do {
		swapped = FALSE;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				swapped = TRUE;
				print_array(array, size);
			}
		}
	} while (swapped);
}
