#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user

    string text = get_string("Start Writing: ");

    printf("%c\n", text[0]);

}

//Calculate Coleman-Liau Index
cli(string text)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;

    // create an array of numbers of the respective ascii letters
    int ascii_letters[];

    for(i = 0; i < 26; i++) // upper case letters
    {
        ascii_letters[i] = 65 + i
    }
    for(i = 0; i < 26; i++) // lower case letters
    {
        ascii_letters[i] = 97 + i;
    }


    int ascii_text[];
    // create an array that stores the ascii equivalent of the characters in the string
    for (i = 0, i < strlen[text], i++)
    {
        ascii_text[i] = (int)text[i];
    }


    for(i = 0; i < SIZE, i++)
    {
        for(j = 0; j < SIZE, j++) // nested loop
        {
            if(ascii_text[i] == ascii_letters[j]) // count letters
            {
                letters++;
            }
            else if (ascii_text[i] == 32) // count words; 32 is space in ascii
            {
                words++;
            }
            else if (ascii_text[i] == 33 || 46 || 63) // count sentences
            {
                sentences++;
            }
        }
    }

    // calculate Index

    L = // L is the average number of letters per 100 words in the text
    score = index = 0.0588 * L - 0.296 * S - 15.8

}