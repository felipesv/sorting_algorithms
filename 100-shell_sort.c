#include "sort.h"
/**
 * shell_sort - sort an array
 * @array: array to sort
 * @size: array size
 *
 * Return: is a void
 */
void shell_sort(int *array, size_t size)
{
	int cnt1, cnt2, tmp, gap = 1, ln = (int)size;

	while (gap <= ln / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (cnt1 = gap; cnt1 < ln; cnt1++)
		{
			tmp = array[cnt1];

			for (cnt2 = cnt1; cnt2 > gap - 1 && array[cnt2 - gap] >= tmp; cnt2 -= gap)
				array[cnt2] = array[cnt2 - gap];

			array[cnt2] = tmp;
		}

		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
