#include <cs50.h>
#include <stdio.h>
#include <string.h>

int ascii_array(string text);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // prompt user

    string text = get_string("Text: ");

    // calculate Index

    float L = count_letters(text) / count_words(text) * 100.0; // L is the average number of letters per 100 words in the text
    float S = count_sentences(text) / count_words(text) * 100.0; // S is the average number of sentences per 100 words in the text
    float score = 0.0588 * L - 0.296 * S - 15.8;

    // print score

    int rounded_score = score + 0.5;

    printf("Grade %i\n", rounded_score);

}

int ascii_array(string text)
{
    // create an array of numbers of the respective ascii letters

    int ascii_letters[52]; // 26 upper case + 26 lowercase

    for (int i = 0; i < 26; i++) // upper case letters
    {
        ascii_letters[i] = 65 + i;
    }
    for (int i = 0; i < 26; i++) // lower case letters
    {
        ascii_letters[i] = 97 + i;
    }

    int text_length = strlen(text);
    int ascii_text[text_length];

    // create an array that stores the ascii equivalent of the characters in the string
    for (int i = 0; i < text_length; i++)
    {
        ascii_text[i] = (int)text[i];
    }
    return ascii_text;
}

int count_letters(string text)
{
    int letters = 0;



    for (int i = 0; i < text_length; i++)
    {
        for (int j = 0; j < 52; j++) // nested loop
        {
            if (ascii_text[i] == ascii_letters[j]) // count letters
            {
                letters++;
            }
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 2;

    if (ascii_text[i] == 32) // count words; 32 is space in ascii
        {
            words++;
        }
        return words;
}


//Calculate Coleman-Liau Index
int count_sentences(string text)
{
    int sentences = 0;

    if (ascii_text[i] == 33 || ascii_text[i] == 46 || ascii_text[i] == 63) // count sentences
        {
            sentences++;
        }
        return sentences;
}