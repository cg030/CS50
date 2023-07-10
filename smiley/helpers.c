#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // array are passed in C by reference so there is no nead to use a pointer
            if (image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtRed == 0x00)
            {
                image[i][j].rgbtRed = 255;
                image[i][j].rgbtGreen = 165;
                image[i][j].rgbtBlue = 0;
            }

            // alternative approach using pointers

            // RGBTRIPLE *pixel = &image[i][j]; // RGBTRIPLE pointer

            // if (pixel->rgbtBlue == 0x00 && pixel->rgbtGreen == 0x00 && pixel->rgbtRed == 0x00)
            // {
            //     pixel->rgbtRed = 255;
            //     pixel->rgbtGreen = 165;
            //     pixel->rgbtBlue = 0;
            // }
        }
    }
}
