#include "main.h"

/**
* binary_to_uint - Converts a binary string to an unsigned integer
* @b: A string containing a binary number
*
* Return: The converted unsigned integer, or 0 if an error occurs
*/
unsigned int binary_to_uint(const char *b)
{
int i;
unsigned int decimal_value = 0;

if (!b)
return (0);

for (i = 0; b[i]; i++)
{
if (b[i] != '0' && b[i] != '1')
return (0);

decimal_value = (decimal_value * 2) + (b[i] - '0');
}

return (decimal_value);
}
