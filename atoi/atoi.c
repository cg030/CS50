#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // Base case: if the string is empty, return 0
    if (*input == '\0')
    {
        return 0;
    }
    else
    {
        return convert(input + 1)
    }
    }

}

// need to add 5 + 60 + 300

// convert("") = 0
//concert(5) = 5
// convert(65) = 60
// convert(365) = 300