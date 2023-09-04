// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//
unsigned int word_count = 0;

// add a global boolean
bool dictionary_loaded = false;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{

    // the hash function directly tells us which is the right bucket

    int bucket = hash(word);

    node *temp_node = table[bucket];
    if (strcmp(word, temp_node->word) == 0)
    {
        return true
    }
    temp_node = temp_node->next;
    else
    {

    }

    // search hash table for the first letter
    for (int i = 0; i < N; i++)
    {

        if (table[i] != NULL && word[i] == table[i]->word[i])
        {
            node *temp_node = table[i];

            if (strcmp(word,temp_node->word) == 0)
            {
                return true;
            }
            // go to the next node in the linked list
            temp_node = temp_node->next;
        }
    }
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        unload();
        return false;
    }

    // read the dictionary
    int index = 0;
    char c;
    char temp_word[LENGTH + 1];

    // gl

    while (fread(&c, sizeof(char), 1, file))
    {
        // Allow only alphabetical characters and apostrophes
        if (isalpha(c) || (c == '\'' && index > 0))
        {
            // Append character to word
            temp_word[index] = c;
            index++;

            // Ignore alphabetical strings too long to be words
            if (index > LENGTH)
            {
                // Consume remainder of alphabetical string
                while (fread(&c, sizeof(char), 1, file) && isalpha(c));

                // Prepare for new word
                index = 0;
            }
        }

        // Ignore words with numbers (like MS Word can)
        else if (isdigit(c))
        {
            // Consume remainder of alphanumeric string
            while (fread(&c, sizeof(char), 1, file) && isalnum(c));

            // Prepare for new word
            index = 0;
        }

        // We must have found a whole word
        else if (index > 0)
        {
            // Terminate current word
            temp_word[index] = '\0';

            // Prepare for next word
            index = 0;

            // store word in a data structure; we already have nodes
            // allocate memeory
            node *new_node = malloc(sizeof(node));

            if(!new_node)
            {
                unload();
                return false;
            }

            strcpy(new_node->word, temp_word);
            new_node->next = NULL;

            // use hash function
            unsigned int h = hash(temp_word);

            // insert the new node into the hash table
            new_node->next = table[h];
            table[h] = new_node;

            // increment word count
            word_count++;
        }
    }
    fclose(file); // close the file after using it
    dictionary_loaded = true;
    return true;  // return true at the end if everything goes well
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (dictionary_loaded == true)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}