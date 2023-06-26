#include <cs50.h>
#include <stdio.h>

int numbers[] = {2,3,5,7,9,1,8};

// Bubble Sort
int main(void)
{
    for(int j = 0; j < 6; j++)
    {
        for(int i = 0; i <  6 - j; i++)
        {
            if (numbers[i] > numbers[i + 1 ])
            {
                int temp; // introduce a temporary variable
                temp = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = temp;
            }
        }
    }

    printf("The elements of the array are:\n");
    for(int i = 0; i < 6; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

}