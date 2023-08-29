// Saves popular dog names in a trie
// https://www.dailypaws.com/dogs-puppies/dog-names/common-dog-names

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_ALPHABET 26
#define MAXCHAR 20

typedef struct node
{
    bool is_word;
    struct node *children[SIZE_OF_ALPHABET];
}
node;

// Function prototypes
bool check(char *word);
bool unload(void);
void unloader(node *current);

// Root of trie
node *root;

// Buffer to read dog names into
char name[MAXCHAR];

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./trie infile\n");
        return 1;
    }

    // File with names
    FILE *infile = fopen(argv[1], "r");
    if (!infile)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Allocate root of trie
    root = malloc(sizeof(node));

    if (root == NULL)
    {
        return 1;
    }

    root->is_word = false;
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        root->children[i] = NULL;
    }

    // Add words to the trie
    while (fscanf(infile, "%s", name) == 1)
    {
        node *cursor = root;

        for (int i = 0, n = strlen(name); i < n; i++)
        {
            int index = tolower(name[i]) - 'a';
            if (cursor->children[index] == NULL)
            {

                // Make node
                node *new = malloc(sizeof(node));
                new->is_word = false;
                for (int j = 0; j < SIZE_OF_ALPHABET; j++)
                {
                    new->children[j] = NULL;
                }
                cursor->children[index] = new;
            }

            // Go to node which we have just been made
            cursor = cursor->children[index];
        }
        // All nodes in the array are equal to NULL except the nodes in the array that comprise the word

        // if we are at the end of the word, mark it as being a word
        cursor->is_word = true;
    }

    if (check(get_string("Check word: ")))
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not Found.\n");
    }

    if (!unload())
    {
        printf("Problem freeing memory!\n");
        return 1;
    }

    fclose(infile);
}

// TODO: Complete the check function, return true if found, false if not found
bool check(char* word)
{
    // define a cursor
    node *cursor = root;

    for (int i = 0; i < strlen(word); i++)
    {
        // retrieve index of the letter in the given word
        int index = tolower(word[i]) - 'a';

        // go to next node; the root can be skipped
        cursor = cursor->children[index];

        // move along the nodes
        



        // check if is_word is true // this is wrong since I first have to be at the end of my word and then check if its a word or not
        if (cursor->is_word == true)
        {
            return true;
        }
        else if (cursor->is_word == false && cursor->children[index] != NULL)
        {
            // go to next node
            cursor = cursor->children[index];
        }
        else if (cursor->is_word == false && cursor->children[index] == NULL)
        {
            return false;
        }



    //     // check if is_word is true
    //     if (cursor->is_word == true)
    //     {
    //         return true;
    //     }

    //     // else go to next node if there is a child node meaning it's not NULL
    //     if (cursor->children[index] != NULL)
    //     {
    //         // go to next node
    //         cursor = cursor->children[index];
    //     }
    //     else if (cursor->children[index] == NULL) //if the index of a provided word is NULL then return false
    //    {
    //     return false;
       }
    }
}

// Unload trie from memory
bool unload(void)
{

    // The recursive function handles all of the freeing
    unloader(root);

    return true;
}

void unloader(node* current)
{

    // Iterate over all the children to see if they point to anything and go
    // there if they do point
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        if (current->children[i] != NULL)
        {
            unloader(current->children[i]);
        }
    }

    // After we check all the children point to null we can get rid of the node
    // and return to the previous iteration of this function.
    free(current);
}
