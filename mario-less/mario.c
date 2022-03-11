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
        for (int s = (h - i); s < n; s--)
        {
            // Print a space
            printf(" ");
        }
        //For Loop to print bricks
        for (int b = 0; )
        //Move to next row
        printf("\n");
    }
}
// Input 8
// .......#
//