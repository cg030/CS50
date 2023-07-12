#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // passing by value just changes the copy so I have to alter the pixels using pointers?

    // iterate of each pixel; a pixel is a struct RGBTRIPLE

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate average of RGB values in each pixel
            int average_value = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;

            image[i][j].rgbtBlue = average_value;
            image[i][j].rgbtGreen = average_value;
            image[i][j].rgbtRed = average_value;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // pixels on the left side of the image should end up on the right, and vice versa
    // pixel in image[i][j] --> image[0][width-j]

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)  // Only need to iterate over half the width
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1]; // the right most pixel is at width - 1 so for j = 0, width - j would be incorrect
            image[i][width - j - 1] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // image[0][0] doesn't have pixels to the left so trying to access these would create a segmentation fault
            if (i == 0 && j == 0) // top left corner
            {
                image[i][j].rgbtBlue = (image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j].rgbtBlue) / 4 ;
                image[i][j].rgbtGreen = (image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j].rgbtGreen) / 4 ;
                image[i][j].rgbtRed = (image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i][j].rgbtRed) / 4 ;

            }
            else if (i == 0 && 0 < j < width - 1) // upper edge
            {
                image[i][j].rgbtBlue = (image[i][j - 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i][j].rgbtBlue) / 6;
                image[i][j].rgbtGreen = (image[i][j - 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i][j].rgbtGreen) / 6;
                image[i][j].rgbtRed = (image[i][j - 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i][j].rgbtRed) / 6;
            }
            else if (0 < i < height - 1 && j == 0) // left edge
            {
                image[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 6;
                image[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 6;
                image[i][j].rgbtRed = (image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed) / 6;
            }
            else if (i == 0 && j == width - 1) // top right corner
            {
                image[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 4;
                image[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 4;
                image[i][j].rgbtRed = (image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed) / 4;

            }
            else if (0 < i < height && j == width - 1) // right edge
            {
                image[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 6;
                image[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 6;
                image[i][j].rgbtRed = (image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed) / 6;

            }
            else if (i == height && j == 0) // bottom left corner
            {
                image[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 4;

            }
            else if (i == height && 0 < j < width - 1) // bottom edge
            {

            }
            else if (i == height && j == width - 1) // bottom right corner
            {

            }
            else if (0 < i < height - 1 && 0 < j < width - 1) //  pixels with other pixels completely surrounding
            {
                image[i][j].rgbtBlue = (image[i - 1][j - 1].rgbtBlue + image[i - 1][j ].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 9;
                image[i][j].rgbtGreen = (image[i - 1][j - 1].rgbtGreen + image[i - 1][j ].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 9;
                image[i][j].rgbtRed = (image[i - 1][j - 1].rgbtRed + image[i - 1][j ].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 9;
            }

        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
