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

    // for loop comparing the integers in the array
    // similar to bubble sort but without switching places
    // simply use a condition if number is larger than every other number return that number

    for (int i; i < n -1 ; i++)
    {
        for (int j; j < n; j++)
        {
            if (j <)
        }
    }
    return 0;
}
