#include <cs50.h>
#include <stdio.h>

int numbers[] = {10,3,5,7,9,1,8};

int main(void)
{
    for (int j = 0; j < 6; j++)
    {
        for(int i = 0; i < 6; i++)
        {
            if (numbers[i] > numbers[i + 1 ])
            {
                //move i to the right
            }
        }
    }
}