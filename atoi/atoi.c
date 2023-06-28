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
    int callcount = 0;
    
    callcount++;

    // Base case: if the string is empty, return 0
    if (*input == '\0')
    {
        return 0;
    }
    else
    {
        // Calculate the factor
        int i = 1;
        int length = strlen(input);
        if(callcount > 2)
        {
            for(int j = 0; j < length; j++)
            {
                i *= 10;
            }
        }
        return convert(input + 1) + i * (*input - '0');
    }
}