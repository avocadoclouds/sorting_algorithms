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
	size_t i, j;
	int tmp, sm;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		sm = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[sm])
				sm = j;
			else
				sm = sm;
			tmp = array[sm];
		}
		array[sm] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}
}
