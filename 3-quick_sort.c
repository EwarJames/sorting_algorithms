#include "sort.h"

/**
 *_swapint - Swaps two integers
 *@num1: First integer to be swapped.
 *@num2: Second integer to be swapped.
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
 *lomuto_partition - Order subset array of inetgers accodring to
 *                   lomuto partition scheme.
 *@array: Array of integers
 *@size: Size of the array
 *@left: The starting index of the subset to order.
 *@right: the ending index of the subset to order.
 *
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, after, before;

	pivot = array + right;
	for (after = before = left; before < right; before++)
	{
		if (array[before] < *pivot)
		{
			if (after < before)
			{
				_swapint(array + before, array + after);
				print_array(array, size);
			}
			after++;
		}
	}
	if (array[after] > *pivot)
	{
		_swapint(array + after, pivot);
		print_array(array, size);
	}
	return (after);
}

/**
 *lomuto_sort - Implements quicksort algorithm by recursion
 *@array: Array of integers
 *@size: Size of the array
 *@left: The starting index of the subset to order.
 *@right: the ending index of the subset to order.
 *
 *Description: Uses the lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, p - 1);
		lomuto_sort(array, size, p + 1, right);
	}
}

/**
 *quick_sort - Sorts integers using quicksort implementation.
 *@array: Array of integers.
 *@size: size of the array.
 *
 *Return: void.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
