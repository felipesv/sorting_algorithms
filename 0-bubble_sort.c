#include "sort.h"
/**
 * bubble_sort  - order an aray and print each swap
 * @array: array to sort
 * @size: size of the array
 *
 * Return: is a void
 */

void bubble_sort(int *array, size_t size)
{
	size_t pos = 0, limit = size;
	int tmp = 0;

	if (array == NULL)
		return;

	while (limit > 0)
	{
		while (pos + 1 < limit)
		{
			if (array[pos] > array[pos + 1])
			{
				tmp = array[pos];
				array[pos] = array[pos + 1];
				array[pos + 1] = tmp;
				print_array(array, size);
			}

			pos++;
		}
		pos = 0;
		limit--;
	}
}
