#include <stdio.h>  // Include the standard input/output library

void print_times_table(int n);

int main()
{
    int n = 10;  // Example: Printing times table up to 10
    print_times_table(n);

    return 0;
}

void print_times_table(int n)
{
    int i, j, k;

    if (n >= 0 && n <= 15)
    {
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= n; j++)
            {
                k = j * i;

                if (j == 0)
                {
                    printf("%d", k);
                }
                else
                {
                    printf(", ");

                    if (k < 10)
                    {
                        printf("   %d", k);
                    }
                    else if (k >= 10 && k < 100)
                    {
                        printf("  %d", k);
                    }
                    else if (k >= 100)
                    {
                        printf(" %d", k);
                    }
                }
            }
            printf("\n");
        }
    }
}

