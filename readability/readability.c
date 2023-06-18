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

ascii_letters = [65 - 90]

    for (i = 0, i < text[\0], i++)
    {
        if (text[i] == ) // count letters
        {
            letters++;
        }
        else if (space) // count sentences
        {
            words++;
        }
        else if (period, question or exclamation) // count words
        {
            sentences++;
        }
    }
}