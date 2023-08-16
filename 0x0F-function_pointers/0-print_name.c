#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - Calls a function with a provided string.
 * @name: The string to process.
 * @f: A function pointer that takes a char pointer as an argument.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
