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

    // stop condition

    if(input[strlen(input)] <= 0)
    {
        return 0;
    }
    
    // In the recursive version of convert, start with the last char and convert it into an integer value.
    // Then shorten the string, removing the last char, and then recursively call convert using the shortened string as input,
    // where the next char will be processed.

    // last char of string

    char last_character = input[strlen(input)];

    // convert char to integer

    int chartoint = atoi(last_character);

    // shorten string, removing the last char

    input[] = input[strlen(input) - 1];

    // recursively call convert using the shortened string as input, where the next char will be processed.

    convert(last_character)

    return chartoint;


    // int n = strlen(input);
    // int output;

    // // need a stop condition
    // if(n <= 0)
    // {
    //     return 0;
    // }

    // // recursive function
    // convert(n - 1);

    // // for loop implementing atoi()

    // for(int i = 0; i < n; i++)
    // {
    //     output = atoi(input[i]);
    // }

    // return output;

}