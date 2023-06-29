// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    int helper_array[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0 ; j < n; j++)
        {
            if (array[i] > array[j])
            {
                helper_array[i] = 1;
            }
            else
            {
                helper_array[i] = 0;
            }
        }

        for (int k = 0; k < n; k++)
        {
            if (helper_array[k] == 1)
            {
                return array[k];
            }
        }
    }
    return 0;
}

            // have to check if element i is larger than all other elemtnes before next round of outer loop since it the next round will overwrite the previous round
