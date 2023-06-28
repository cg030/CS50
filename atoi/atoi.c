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
    int i = 1;
    int length = strlen(input);

    for(int j = 1; j < length; j++)
    {
        i *= 10;
    }
    return convert(input + 1) + i * (*input - '0');
}

// *input takes the first character of the string input
// (*input - '0') subtract by '0' converts the character into an integer
