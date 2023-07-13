#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Improper usage; Only one command line argumment\n");
        return(1);
    }

    FILE *file = fopen(argv[1], "r");
    


    // Your program should accept exactly one command-line argument, the name of a forensic image from which to recover JPEGs.
    // If your program is not executed with exactly one command-line argument, it should remind the user of correct usage, and main should return 1.

    // If the forensic image cannot be opened for reading, your program should inform the user as much, and main should return 1.

}