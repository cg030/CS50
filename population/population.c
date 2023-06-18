#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    // do while loop to get correct starting size from user
    int n;
    do
    {
        n = get_int("Starting size: ");
    }
    while(n < 9);

    // TODO: Prompt for end size
    // do while loop that uses the start size as a condition
    int m;
    do
    {
        m = get_int("End size: ");
    }
    while(m < n);

    // TODO: Calculate number of years until we reach threshold
    // for loop that adds n/3 and subtracts n/4 every year until n = m
    int i;

    for(i = 0; n<m; i++)
    {
        n = n + (n/3) - (n/4);
    }

    // TODO: Print number of years

    printf("Years: %i\n" , i);
}
