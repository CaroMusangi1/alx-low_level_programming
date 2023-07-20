#include "main.h"
#include <stdio.h>

/**
 * main - Prints numbers from 1 to 100 with certain conditions.
 * For multiples of three, prints "Fizz" instead of the number.
 * For multiples of five, prints "Buzz" instead of the number.
 * For multiples of both three and five, prints "FizzBuzz".
 * Return: Always 0 (Success).
 */
int main(void)
{
    int i;

    for (i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 5 != 0)
        {
            printf("Fizz");
        }
        else if (i % 5 == 0 && i % 3 != 0)
        {
            printf("Buzz");
        }
        else if (i % 3 == 0 && i % 5 == 0)
        {
            printf("FizzBuzz");
        }
        else
        {
            printf("%d", i);
        }

        if (i != 100)
        {
            printf(" ");
        }
    }

    printf("\n");
    return (0);
}
