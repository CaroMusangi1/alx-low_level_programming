#include "function_pointers.h"

/**
 * int_index - Searches for an integer in an array using a comparison function.
 * @array: The array of integers.
 * @size: The number of elements in the array.
 * @cmp: A function pointer to a comparison function.
 * Return: The index of the first element for which the comparison function
 *         returns non-zero, or -1 if no element matches.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
