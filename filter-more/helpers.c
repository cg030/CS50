#include "helpers.h"
#include "math.h"

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
            int average_value = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

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
    // create a temp image to prevent the blur effect of a pixel affecting the calculation of its neighbors' blur effect.

    RGBTRIPLE temp_image[height][width];


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue_sum = 0;
            int green_sum = 0;
            int red_sum = 0;
            int count = 0;

            // use another nested loop to iterate over surrounding pixels
            for (int k = -1; k <= 1; k++)
            {
                for ( int l = -1; l <= 1; l++)
                {
                    int new_i = i + k;
                    int new_j = j + l;

                    // check if pixel is inside map using new_i and new_j
                    if ( 0 <= new_i && new_i < height && 0 <= new_j && new_j < width)
                    {
                        blue_sum += image[new_i][new_j].rgbtBlue;
                        green_sum += image[new_i][new_j].rgbtGreen;
                        red_sum += image[new_i][new_j].rgbtRed;
                        count++;

                    }
                }
            }

            // calculate average

            temp_image[i][j].rgbtBlue = round((float)blue_sum / count);
            temp_image[i][j].rgbtGreen = round((float)green_sum / count);
            temp_image[i][j].rgbtRed = round((float)red_sum / count);
        }
    }

    // copy temp_image into original image

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp_image[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // create kernels
    int Gx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1},
    };
    int Gy[3][3] =
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1},
    };

    // create a temp image to prevent calculation of the previous pixel to influence the calculation of the next calculation

    RGBTRIPLE temp_image[height][width];


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue_sum_Gx = 0;
            int blue_sum_Gy = 0;
            int green_sum_Gx = 0;
            int green_sum_Gy = 0;
            int red_sum_Gx = 0;
            int red_sum_Gy = 0;

            // use another nested loop to iterate over surrounding pixels
            for (int k = -1; k <= 1; k++)
            {
                for ( int l = -1; l <= 1; l++)
                {
                    int new_i = i + k;
                    int new_j = j + l;

                    // check if pixel is inside map using new_i and new_j
                    if ( 0 <= new_i && new_i < height && 0 <= new_j && new_j < width)
                    {
                        blue_sum_Gx += image[new_i][new_j].rgbtBlue * Gx[k + 1][l + 1];
                        blue_sum_Gy += image[new_i][new_j].rgbtBlue * Gy[k + 1][l + 1];
                        green_sum_Gx += image[new_i][new_j].rgbtGreen * Gx[k + 1][l + 1];
                        green_sum_Gy += image[new_i][new_j].rgbtGreen * Gy[k + 1][l + 1];
                        red_sum_Gx += image[new_i][new_j].rgbtRed * Gx[k + 1][l + 1];
                        red_sum_Gy += image[new_i][new_j].rgbtRed * Gy[k + 1][l + 1];
                    }
                }
            }

            // calculate total for each color channel
            temp_image[i][j].rgbtBlue = round(fmin(255, sqrt(pow(blue_sum_Gx, 2) + pow(blue_sum_Gy, 2))));
            temp_image[i][j].rgbtGreen = round(fmin(255, sqrt(pow(green_sum_Gx, 2) + pow(green_sum_Gy, 2))));
            temp_image[i][j].rgbtRed = round(fmin(255, sqrt(pow(red_sum_Gx, 2) + pow(red_sum_Gy, 2))));
        }
    }

    // copy temp_image into original image

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp_image[i][j];
        }
    }

    return;
}
