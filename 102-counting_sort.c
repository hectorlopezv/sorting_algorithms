#include "sort.h"
/**
 * get_max_array - get maximum value of array
 * @array: array
 * @size: size of
 * Return: return max value
 */
int get_max_array(int *array, size_t size)
{
	int i, max_number;

	max_number = array[0];

	for (i = 0; i < (int)size; i++)
	{
		if (max_number < array[i])
		{
			max_number = array[i];
		}
	}

	return (max_number);
}
/**
 * counting_sort - counting sort
 * @array: array of keys
 * @size: size of the counting array is K
 * Return: nothing non-place algorithm
 */
void counting_sort(int *array, size_t size)
{
	int max_, i, idx;
	int *counting_array, *new_array;

	if (array == NULL || size < 2)
		return;
	max_ = get_max_array(array, size);
	max_ = max_ + 1;
	/* counting array*/
	counting_array =  malloc(max_ * sizeof(int));
	/*intitialize values with 0*/
	for (i = 0; i < max_; i++)
		counting_array[i] = 0;
	/* new array*/
	new_array =  malloc((int)size * sizeof(int));
	/*intitialize values with 0*/
	for (i = 0; i < (int)size; i++)
		new_array[i] = 0;
	/*counting of numbers for keys*/
	for (i = 0; i < (int)size; i++)
		counting_array[array[i]] = counting_array[array[i]] + 1;

	/*cumulative sum of counting of numbers for keys*/
	for (i = 1; i < (int)max_; i++)
		counting_array[i] = counting_array[i - 1] + counting_array[i];
	print_array(counting_array, max_);
	for (i = size - 1;  i >= 0; i--)
	{
		idx = counting_array[array[i]];
		counting_array[array[i]] = counting_array[array[i]] - 1;
		new_array[idx - 1] = array[i];
	}
	/*exchange values*/
	for (i = 0; i < (int)size; i++)
		array[i] = new_array[i];
	/* free Values*/
	free(new_array);
	free(counting_array);
}
