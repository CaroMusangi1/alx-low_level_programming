#include <stdio.h>

/**
 * main - Demonstrates the use of a while loop
 * Return: 0
 */
int main(void)
{
    int i;

    printf("Infinite loop incoming :(\n");

    i = 0;

    while (i < 10)
    {
        putchar(i);
        i++;
    }

    printf("Infinite loop avoided! \\o/\n");

    return (0);
}
