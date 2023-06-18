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

space_ascii = 32;

int ascii_text[];

    for (i = 0, i < strlen[text], i++)
    {
        ascii_text[i] = (int)text[i];
    }


        if ((int)text[i] == ) // count letters
        {
            letters++;
        }
        else if () // count sentences
        {
            words++;
        }
        else if (period, question or exclamation) // count words
        {
            sentences++;
        }
    }
}