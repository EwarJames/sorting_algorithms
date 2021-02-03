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
