#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner

    if(score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if(score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // have to use indexes of the array

    // loop to iterate over the string of the word moving one index at a time

    int total_points = 0;

    for(int i = 0, len = strlen(word); i < len; i++)
    {
        if( isupper(word[i]))
        {
            total_points += POINTS[word[i] - 'A']; //// ASCII Number -> to the respective index of the array POINTS[]; A -> 65 -> POINTS[0] --> 65 - 65 = 0
        }
        else if (islower(word[i]))
        {
            total_points += POINTS[word[i] - 'a'];
        }
        else
        {
            total_points += POINTS[word[i] - word[i]]; // 0 points
        }

        return total_points;
    }

}
