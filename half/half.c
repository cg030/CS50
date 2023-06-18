#include <cs50.h>
#include <stdio.h>

double half(double bill, double tax, double tip);

int main(void)
{
    double bill_amount = get_double("Bill before tax and tip: ");
    double tax_percent = get_double("Sale Tax Percent: ");
    double tip_percent = get_double("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

double half(double bill, double tax, double tip)
{
    // Convert tax_percent and tip_percent into decimals
    tax = tax / 100.0;
    tip = tip / 100.0;

    // Calculate the tax amount
    double tax_amount = bill * tax;

    // Calculate the total bill with tax
    double total_with_tax = bill + tax_amount;

    // Calculate the tip amount based on total_with_tax
    double tip_amount = total_with_tax * tip;

    // Calculate the final total bill with tax and tip
    double final_total = total_with_tax + tip_amount;

    // Return half the total amount
    return final_total / 2;
}
