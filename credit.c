#include <cs50.h>
#include <math.h>
#include <stdio.h>

// Functions prototypes
long get_credit_card_nr(string prompt);
void check_card_nr(long card_nr);
int main(void)
{
    long answer = get_credit_card_nr("Number");
    check_card_nr(answer);
}

// Retrieve user input
long get_credit_card_nr(string prompt)
{
    long answer = get_long("%s: ", prompt);
    return answer;
}

// Check if number is valid luhn number
bool check_luhn_number(long card_nr, int count)
{
    long ten_multiple = 10;
    int sum = 0;
    long temp_card_nr = card_nr;
    int sum_of_others = 0;
    // Go through the card number
    for (int i = 0; i < count; i++)
    {
        // Calculate remainder and remove remainder from the calculation
        long remainder = temp_card_nr % ten_multiple;
        temp_card_nr -= remainder;
        
        // Get single numbers for remainder values
        int single_remainder = remainder / (ten_multiple / 10);
        
        // Split values based on position
        if (i % 2 == 0)
        {
            sum += single_remainder;
        } 
        else 
        {
            // Multiplied values calculated for the Luhn's number and split if they are bigger than 10
            int multiply_value = single_remainder * 2;
            if (multiply_value >= 10)
            {
                int multiply_remainder = multiply_value % 10;
                multiply_value = multiply_remainder + ((multiply_value - multiply_remainder) % 100) / 10;
            }
            sum_of_others = sum_of_others + multiply_value;
        }
        ten_multiple *= 10;
    }
    int final_sum = sum_of_others + sum;
    
    // Check if the last digit is 0 and then return value based on that
    if (final_sum % 10 == 0)
    {
        return true;
    }
    return false;
}

// Check card
void check_card_nr(long card_nr)
{   
    int count = 0;
    int pair_numbers = 0;
    long temp_card_nr = card_nr;
    bool is_luhns_nr = false;
    
    // Loop through card number in order to get the pair in front of the credit card number and how long is the card number
    while (temp_card_nr > 0)
    {
        temp_card_nr = temp_card_nr / 10;
        if (temp_card_nr > 10)
        {
            pair_numbers = temp_card_nr;
        }   
        count++;
    }
    
    string message = "";
    
    // Check validity of card number based on Luhn's algorithm
    is_luhns_nr = check_luhn_number(card_nr, count);
    
    // Based on values calculated message which card has this number when it's valid
    if ((pair_numbers == 51 || pair_numbers == 52 || pair_numbers == 53 || pair_numbers == 54 || pair_numbers == 55) && count == 16
        && is_luhns_nr)
    {
        message = "MASTERCARD";
    } 
    else if ((pair_numbers / 10 == 4) && (count == 16 || count == 13) && is_luhns_nr)
    {
        message = "VISA";
    } 
    else if ((pair_numbers == 34 || pair_numbers == 37) && count == 15  && is_luhns_nr)
    {
        message = "AMEX";
    } 
    else
    {
        message = "INVALID";
    }
    
    printf("%s\n", message);
}
