#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define BYTE as a type for 8-bit unsigned integer
typedef uint8_t BYTE;

// Define constants for block size and file name size
#define BLOCK_SIZE 512
#define FILE_NAME_SIZE 8

int main(int argc, char *argv[])
{
    // Check if the correct number of command-line arguments is provided
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Try to open the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Define a buffer to store a block of the forensic image and an integer to keep track of the image count
    BYTE buffer[BLOCK_SIZE];
    int imageCount = 0;

    // Define a file pointer for the current image file and a character array for the filename
    FILE *currentImage = NULL;
    char filename[FILE_NAME_SIZE];

    // Read 512-byte blocks from the file
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        // Check if the start of the block is a JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If a JPEG file is already open, close it
            if (currentImage != NULL)
            {
                fclose(currentImage);
            }

            // Generate a new filename
            sprintf(filename, "%03i.jpg", imageCount);

            // Open a new JPEG file
            currentImage = fopen(filename, "w");

            // Increase the image count
            imageCount++;
        }

        // If a JPEG file is open, write the block to it
        if (currentImage != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, currentImage);
        }
    }

    // Close the last JPEG file
    if (currentImage != NULL)
    {
        fclose(currentImage);
    }

    // Close the forensic image file
    fclose(file);

    // Exit with a return code of 0 (success)
    return 0;
}
