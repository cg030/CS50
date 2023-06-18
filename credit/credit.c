#include <cs50.h>
#include <stdio.h>


bool luhn(long number);

int card_type(long number);

bool number_length(long number);


int main(void)
{
    // get input from user

    long number = get_long("Number: ");

    // print out card type

    if (luhn(number) == 1 && card_type(number) == 1 && number_length(number) == 1)
    {
        printf("MASTERCARD\n");
    }
    else if (luhn(number) == 1 && card_type(number) == 2 && number_length(number) == 1)
    {
        printf("VISA\n");
    }
    else if (luhn(number) == 1 && card_type(number) == 3 && number_length(number) == 1)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
    // printf("%i\n", luhn(number));
    // printf("%i\n", card_type(number));
    // printf("%i\n", number_length));
}

// Calculate Luhn's Algorithm with a function

bool luhn(long number)
{
    int count = 0;
    int sum = 0;

    while (number > 0)
    {
        int digit = number % 10; // extract last digit

        if (count % 2 != 0) // conditional for calculation according to digit order
        {
            int product = digit * 2;

            sum = sum + product / 10 + product % 10; // if the product is a two-digit number this splits it into two digits; integer division on product by 10. Integer division in C rounds towards zero.
        }

        else
        {
            sum = sum + digit;
        }

        count++;
        number = number / 10; // remove last digit
    }

    //If the sum’s last digit is 0 (if the sum modulo 10 is congruent to 0), the number is valid

    return (sum % 10 == 0);
}

bool number_length(long number)
{
    int length = 0;

    while (number != 0)
    {
        number = number / 10;
        length++;
    }
    if (length == 13 || length == 15 || length == 16)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

int card_type(long number)
{
    // Extract first two digits
    while (number >= 100)
    {
        number /= 10;
    }
    if (number >= 51 && number <= 55)
    {
        return 1; // Mastercard
    }
    else if (number /10 == 4)
    {
        return 2; // Visa
    }
    else if (number == 34 || number == 37)
    {
        return 3; // American Express
    }
    else
    {
        return 4; // Invalid
    }
}