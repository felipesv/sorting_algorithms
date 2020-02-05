#include "sort.h"
/**
 * quick_sort - sort an array
 * @array: array to sort
 * @size: size of the array
 *
 * Return: is a void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort2(array, (int)size, 0, (int)size - 1);
}
/**
 * quick_sort2 - sort an array recursion
 * @array: array to sort
 * @size: size of the array
 * @pos1: pos to start
 * @pos2: pos to end
 *
 * Return: is a void
 */
void quick_sort2(int *array, int size, int pos1, int pos2)
{
	int cnt1 = pos1, cnt2 = pos1 - 1;
	int pivot = 0, tmp = 0;

	if (pos2 <= pos1)
		return;

	pivot = array[pos2];

	for (cnt1 = pos1; cnt1 <= pos2; cnt1++)
	{
		if (array[cnt1] <= pivot)
		{
			cnt2++;

			tmp = array[cnt1];
			array[cnt1] = array[cnt2];
			array[cnt2] = tmp;

			if (cnt2 != cnt1)
				print_array(array, size);
		}

	}

	/*ordenar la izquierda*/
	quick_sort2(array, size, 0, cnt2 - 1);
	/*ordenar la derecha*/
	quick_sort2(array, size, cnt2 + 1, pos2);
}
