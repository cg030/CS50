#include <cs50.h>
#include <stdio.h>

int numbers[] = {10,3,5,7,9,1,8};

// Bubble Sort
int main(void)
{
        for(int i = 0; i < 6; i++)
        {
            if (numbers[i] > numbers[i + 1 ])
            {
                numbers[i] = numbers[i] - (numbers[i] - numbers[i+1]);
                numbers[i+1] = numbers[i+1] + (numbers[i] - numbers[i+1]);
            }
        }
        
    printf("The elements of the array are:\n");
    for(int i = 0; i < 6; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

}