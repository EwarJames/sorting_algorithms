#include "sort.h"

/**
 *_swapint - Swaps two integers
 *@num1: First integer to swap
 *@num2: Second integer to swap
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
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */

void shell_sort(int *array, size_t size)
{
	size_t n, i, j;

	if (array == NULL || size < 2)
		return;

	for (n = 1; n < (size / 3);)
		n = n * 3 + 1;

	for (; n >= 1; n /= 3)
	{
		for (i = n; i < size; i++)
		{
			j = i;
			while (j >= n && array[j - n] > array[j])
			{
				_swapint(array + j, array + (j - n));
				j -= n;
			}
		}
		print_array(array, size);
	}
}
