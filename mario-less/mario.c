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
        //For loop to print spaces
        for (int s = h - 1;s < n; s++)
        {
            // Print a brick
            printf(" ");
        }
        //For Loop to print bricks
        for ()
        //Move to next row
        printf("\n");
    }
}
// Input 8
// .......#
//