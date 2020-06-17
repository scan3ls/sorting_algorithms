#include "sort.h"
/**
 * selection_sort- sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: list
 * @size: size of the list
 */
void selection_sort(int *array, size_t size)
{
	size_t x,y, temp;

	for (x = 0; x < size - 1; x++)
	{
		size_t Min = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[Min])
			{
				Min = y;
			}
		}

		if (Min != x)
		{
			temp = array[x];
			array[x] = array[Min];
		        array[Min] = temp;
			print_array(array, size);
		}
	}
}
