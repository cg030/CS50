#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get size input

    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // loop to print pyramid

    for (int i = 1; i <= height; i++)
    {
        //for loop to first print spaces
        for (int k = 1; k <= height - i; k++)
        {
            printf(" ");
        }

        // for loop print the number of hashes equivalent to the row; +1 row, +1 hash
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");

        // identical for loop as above
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}