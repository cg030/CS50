#include <cs50.h>
#include <stdio.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
// preferences =
// [
//   [0(i), 100(j), 200(j)],  // Candidate A
//   [300, 0, 400],  // Candidate B
//   [500, 600, 0],  // Candidate C
// ]

int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
// Here the ranks array only has three elements not of all voters. The array (of three candidates) is then passed to record_preferences function where the preferences are update
bool vote(int rank, string name, int ranks[])
{
    // TODO

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            // update rank
            // rank is an int so if rank == 1 then it should go in the ranks[] array in the 0 index
            ranks[i] = name;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // if candidate A comes before candidate B update the respective row in the preference 2d array

    // first a for loop that assigns candidates to variables. These variables I can then use in the following for loop so determine the preference 2d array

    char a;
    ch
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < candidates_count; j++)
        {
            if(strcmp(ranks[i], candidates[j] == 0))// Alice
            {
                ranks[i] = a;
            }
        }
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < candidates_count; j++)
        {
            if(strcmp(ranks[i], candidates[j] == 0))// Alice
            {
                preference[0][1]++; //add 1 to the respective index
            }
        // assign an index to a respective candidate/row i.e. Alice is row 0.
        // Instead of using the actual name "Alice" I have to assign a variable to each candidate so it doesn't matter what they are called. This is important since I don't know the names beforehand

        }
        // update preferences two-dimensional array
        // one row of the two-dimensional array represents one candidate
        // so we first have to figure out who the voter prefers over who and then update respective row
        // For the first ballot take each name from the voter ballot and assign it a row: row 1 is Alice, row 2 is Bob
        // after that I need a way to automatically assign the votes to the correct rows, somehow via the names of the candidates

        if(strcmp(ranks[i], candidates[i] == 0))// if Alice come before Bob))
        {
            preference[0][1]++; //add 1 to the respective index
        }


    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}