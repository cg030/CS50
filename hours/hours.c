// Calculator to compute the average or total number of hours spent studying for CS50

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    // receive input
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    // input of hours in the respective week are stored in an array
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    float total_hours = 0;

    // calculate total hours
    for (int i = 0; i  < weeks; i++)
    {
        total_hours += hours[i];
    }
    // output either total hours or average
    if (output == 'T')
    {
        return total_hours;
    }
    else
    {
        return total_hours / weeks;
    }
}