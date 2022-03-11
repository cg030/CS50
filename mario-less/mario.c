#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Variable Height
    int h;
    //Variable Spaces
    int s;
    //Variable Bricks
    int b;
    
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

// For each row
    for (int i = 0; i < h; i++)
    {
        //For each column
        for (int j = 0; j < n; j++)
        {
            // Print a brick
            printf("#");
        }
        //Move to next row
        printf("\n");
    }
}
