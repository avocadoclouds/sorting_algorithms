#include "sort.h"

/**
* shell_sort - this function is used to sort an array
*              using shell sorting algorithm
*
* @array: the array to be sorted
*
* @size: the size of the array
*
* Return: Nothing
*/

void shell_sort(int *array, size_t size)
{
	size_t gap, interval, i, j;
	int tmp;

	if (size < 2)
		return;
	gap = 1;
	while (gap < size / 3)
		gap = (gap * 3) + 1;
	for (interval = gap; interval > 0; interval /= 3)
	{
		for (i = interval; i < size; i += 1)
		{
			tmp = array[i];
			for (j = i; j >= interval && array[j - interval] > tmp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
