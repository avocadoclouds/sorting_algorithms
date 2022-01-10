#include "sort.h"

/**
* selection_sort - this function is used to sort
*                  array using selection algorithm
*
* @array: the array to be sorted
*
* @size: size of the array to be sorted
*
* Return: Nothing
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (array[min] != array[i])
		{
			tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
