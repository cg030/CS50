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
    //Variable Gap
    int g;

    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

// For each row
    for (int i = 0; i < h; i++)
    {
        //For loop to print spaces
        for (s = (h - i); s >= 2; s--)
        {
            // Print a space
            printf(" ");
        }
        //For Loop to print bricks
        for (b = 0; b < (i+1); b++)
        {
            printf("#");
        }
        //For loop to print gap
        for (g=2; g < h; g++)
        {
            printf(" ")
        }
        //Move to next row
        printf("\n");
    }
}