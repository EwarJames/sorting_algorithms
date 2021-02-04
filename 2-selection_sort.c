#include "sort.h"

/**
 *_swapint - Swaps two integers
 *@num1: First integer to be swapped.
 *@num2: Second integer to be wapped.
 *
 *Return: void
 */
void _swapint(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 *selection_sort - sorts an array of integers in ascending order
 *@array: Pointer to the elements
 *@size: Size of the array
 *
 *Description: Print array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t k, m;

	if (array == NULL || size < 2)
		return;

	for (k = 0; k < size - 1; k++)
	{
		min = array + k;
		for (m = k + 1; m < size; m++)
			min = (array[m] < *min) ? (array + m) : min;
		if ((array + k) != min)
		{
			_swapint(array + k, min);
			print_array(array, size);
		}
	}
}
