#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // prompt user

    string text = get_string("Text: ");

    // calculate Index

    float L = count_letters(text) / (float)count_words(text) * 100.0; // L is the average number of letters per 100 words in the text
    float S = count_sentences(text) / (float)count_words(text) * 100.0; // S is the average number of sentences per 100 words in the text
    float score = 0.0588 * L - 0.296 * S - 15.8;

    // print score

    int rounded_score = score + 0.5;

    printf("Letters: %i\n", count_letters(text));
    printf("Words: %i\n", count_words(text));
    printf("Sentences: %i\n", count_sentences(text));
    printf("L: %f\n", L);
    printf("S: %f\n", S);

    if(rounded_score < 16)
    {
        printf("Grade %i\n", rounded_score);
    }
    else
    {
        printf("Grade 16+");
    }

}

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) // count letters
        {
            letters++;
        }
    }
    return letters;
}


int count_words(string text)
{
    int words = 1;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == 32) // count words; 32 is space in ascii
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63) // count sentences
        {
            sentences++;
        }
    }
    return sentences;
}