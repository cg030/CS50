#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{

    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    for (int i = number - 1; i > 1; i--) // i is the number we divide the input number by
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

