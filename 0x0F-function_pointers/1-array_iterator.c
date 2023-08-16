#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - Applies a function to each element of an array.
 * @array: The array of integers.
 * @size: The number of elements in the array.
 * @action: A function pointer to apply to each element.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
