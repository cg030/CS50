#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // calculate average of RGB values in each pixel

    // iterate of each pixel; a pixel is a struct RGBTRIPLE
    for (int i = 0; i < end of bitmap; i++)
    {
        for (int j = 0; j < end of bitmap; j++)
        {
            // passing by value just changes the copy so I have to alter the pixels using pointers?
            average_value = (image[i][j].rgbtBlue + image[i][j].rgctGreen + image[i][j].rgbtRed) / 3;

            image[i][j].rgbtBlue = average_value;
            image[i][j].rgctGreen = average_value;
            image[i][j].rgbtRed = average_value;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
