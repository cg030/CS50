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

bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i; // each integer in the ranks array corresponds to the index of a candidate in the candidates array
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
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

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{

// Preferences array example to help visualise
// int preferences[3][3] = {
//     // A, B, P
//     {0, 2, 3},  // Alice: 2 voters prefer Alice over Bob, 3 voters prefer Alice over Peter
//     {3, 0, 3},  // Bob: 3 voters prefer Bob over Alice, 3 voters prefer Bob over Peter
//     {2, 2, 0}   // Peter: 2 voters prefer Peter over Alice, 2 voters prefer Peter over Bob
// here Alice is prefered over Peter by a 3-2 margin

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])  // swith the index i and j; in the matrix (0;1) is the preference of Alice over Bob but (1;0)
                                                        // is the preference of Bob over Alice
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] <= preferences[j][i])
            {
                pairs[pair_count].loser = i;
                pairs[pair_count].winner = j;
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
            int strength_i = preferences[pairs[i].winner][pairs[i].loser]; // remember that pairs[i].winner stores a number which corresponds to the index of the candidates array
            int strength_i_plus_1 = preferences[pairs[i+1].winner][pairs[i+1].loser];

            // bubble sort
            if (strength_i < strength_i_plus_1)
            {
                pair temp = pairs[i];
                pairs[i] = pairs[i+1];
                pairs[i+1] = temp;
                swapped = true;
            }
        }
    }while (swapped);
}

void lock_pairs(void)
{
// locked array is a 2D boolean array representing the graph. locked[i][j] being true means there's an edge from candidate i to candidate j

    for (int i = 0; i < pair_count; i++)
    {
        bool cycle = false;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][pairs[i].winner]) // checks if there is an edge from any candidate j to a current winner i.
                                            // Since i is the index in the outer loop the inner loop check all rows meaning all candidates of the winners column
            {
                cycle = true;
                break;
            }
        }
        if (!cycle)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
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