#include <cs50.h>
#include <math.h>
#include <stdio.h>

// Prototype of the 
float ask_and_confirm_float(string prompt);

int main(void)
{
    // get user input and verify
    float owed = ask_and_confirm_float("Change owed: ");
    // Calculate to cents
    int cents = round(owed * 100);
    
    int remainder;
    int amount_of_cents = 0;
    
    // Loop to calculate number of cents
    do
    {
        if (cents >= 25)
        {
            cents = cents - 25;
        }
        else if (cents >= 10)
        {
            cents = cents - 10;
        } 
        else if (cents >= 5)
        {
            cents = cents - 5;
        }
        else
        {
            cents = cents - 1;
        }
        amount_of_cents ++;
    } 
    while (cents > 0);
    printf("%i\n", amount_of_cents);
}

// Ask for float and then confirm it's positive
float ask_and_confirm_float(string prompt)
{
    float input;
    do
    {
        input = get_float("%s", prompt);
    }
    while (input <= 0);
    return input;
}
