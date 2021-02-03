#include "sort.h"

/**
 *_swapint-Fuction that swaps integers
 *@num1:The first integer to be swaped
 *@num2:The second integer to be swaped
 *
 *Return: Void
 */

void _swapint(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order.
 *@array: Pointer to the elements
 *@size: size of the array
 *
 *Description: Prints the array after each swap
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool s = false;

	if (array == NULL || size < 2)
		return;

	while (s == false)
	{
		s = true;

		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				_swapint(array + i, array + i + 1);
				print_array(array, size);
				s = false;
			}
		}
		len--;
	}
}
