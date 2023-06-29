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
    // bool helper_array[n];

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0 ; j < n; j++)
    //     {
    //         if (array[i] >= array[j])
    //         {
    //             helper_array[i] = true;
    //         }
    //         else
    //         {
    //             helper_array[i] = true;
    //         }
    //     }
    //     bool whole_array = true;

    //     for (int k = 0; k < n; k++)
    //     {
    //         if (helper_array[k] == false)
    //         {
    //             whole_array = false;
    //             break;
    //         }
    //     }

    //     if(whole_array == true)
    //     {
    //         return array[i];
    //     }
    // }
    // return 0;

    int max_value = array[0];

    for(i < 0; i < n; i++)
    {
        if(array[i] >= max_value)
        {
            max_value = array[i];
        }
        else
        {
            break;
        }
    }

}