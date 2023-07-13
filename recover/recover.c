#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Your program should accept exactly one command-line argument, the name of a forensic image from which to recover JPEGs.
    // If your program is not executed with exactly one command-line argument, it should remind the user of correct usage, and main should return 1.
    if (argc != 2)
    {
        printf("Improper usage; Only one command line argumment\n");
        return(1);
    }

    // Open input file
    // If the forensic image cannot be opened for reading, your program should inform the user as much, and main should return 1.
    char *infile = argv[1];
    FILE *file = fopen(infile, "r");

    if (file == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }


    // Open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not create %s.\n", outfile);
        return 5;
    }



}