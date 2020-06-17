#include "sort.h"



void swap(int *xp, int *yp);
/**
 * shell_sort - shell sorting
 * @array: array
 * @size: size of array
 * Return: nothing in-place algorithm
 *
 */
void shell_sort(int *array, size_t size)
{
	int i, h = 1, gap, j;

	if (array == NULL || size <= 1)
		return;
	h = 1;
	while (h < (int)size / 3)
		h = 3 * h + 1;
	gap = h;

	while (gap >= 1)
	{
		for (i = gap; i < (int)size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap(&array[j - gap], &array[j]);
				j -= gap;
			}

		}
		gap /= 3;
		print_array(array, size);
	}

}


/**
 * swap - swapping numbers
 * @xp: numbers
 * @yp: numbers
 * Return: return
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
