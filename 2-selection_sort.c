#include "sort.h"
/**
 * selection_sort - sort an array
 * @array: array to sort
 * @size: size of the array
 *
 * Return: is a void
 */
void selection_sort(int *array, size_t size)
{
	size_t cnt1 = 0, cnt2 = 0, pos = -1;
	int tmp = 0;

	if (array == NULL || size <= 1)
		return;

	for (cnt1 = 0; cnt1 < size - 1; cnt1++)
	{
		pos = cnt1;

		for (cnt2 = cnt1 + 1; cnt2 < size; cnt2++)
		{
			if (array[pos] > array[cnt2])
				pos = cnt2;
		}

		if (pos != cnt1)
		{
			tmp = array[cnt1];
			array[cnt1] = array[pos];
			array[pos] = tmp;
			print_array(array, size);
		}
	}
}
