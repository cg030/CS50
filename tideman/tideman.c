#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Max number of candidates
#define MAX 9

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

bool vote(int rank, string name, int ranks[])   // Stores the candidates index from the candidates array in the ranks array according to the rank input
                                                // e.g. "Alice" is stored in the 2nd index in the candidates array. She was voted as the 2nd preference so the index of Alice in the candidates array, lets say 4, is stored as the 2nd element in rank array
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// We now have an array ranks[3,2,1] ; we know that 3 corresponds to Alice, 2 for Bob and 1 for Charlie
// Update preferences given one voter's ranks; populates the 2d preferences array
void record_preferences(int ranks[])
{
    for(int i = 0 ; i < candidate_count; i++)
    {
        for(int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++; // adds 1 to the corresponding field in the preference matrix
            // (example ranks[i] = 3 (3 corresponds to the index in the candidates array)  ranks[j] = 2 adds 1 to preferences[3][2])
        }
    }
}

void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}


// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // bubble sort
    bool swapped;
    do
    {
        swapped = false;

        // calculate the stength of victory of each pair
        for (int i = 0; i < pair_count - 1; i++)
        {
            int strength_i = preferences[pairs[i].winner][pairs[i].loser]; // returns the number of times a candidate was voter over another candidate
            int strength_i_plus_1 = preferences[pairs[i + 1].winner][pairs[i + 1].loser];

            // bubble sort
            if (strength_i < strength_i_plus_1)
            {
                pair temp = pairs[i];
                pairs[i] = pairs[i + 1];
                pairs[i + 1] = temp;
                swapped = true;
            }
        }
    }while (swapped);
}

void lock_pairs(void)
{
    // Initialize an array to track which candidates are locked
    bool is_locked[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        is_locked[i] = false;
    }

    // Iterate through pairs and lock them unless a cycle is detected
    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        is_locked[pairs[i].winner] = true;

        // Check if the locked pair creates a cycle
        bool creates_cycle = false;
        for (int j = 0; j < candidate_count; j++)
        {
            if (is_locked[j] && locked[pairs[i].loser][j])
            {
                creates_cycle = true;
                break;
            }
        }

        // If a cycle is created, unlock the pair
        if (creates_cycle)
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
            is_locked[pairs[i].winner] = false;
        }
    }
}


// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        int winner = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (!locked[j][i]) // if j has not beaten i
            {
                winner++;
            }
        }
        if (winner == candidate_count) // If winner is equal to the candidate_count, it means that no other candidate has beaten candidate i
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
}