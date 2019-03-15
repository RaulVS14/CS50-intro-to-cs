#include <cs50.h>
#include <stdio.h>

// defining prototypes of functions
int get_correct_int(string display_message);
void generate_pyramid(int input);

int main(void)
{
    // Ask user for input height and generate pyramid
    int answer = get_correct_int("Height: ");
    generate_pyramid(answer);
}

// function for get the correct input
int get_correct_int(string display_message)
{
    int answer;
    do
    {
        answer = get_int("%s", display_message);
    } 
    while (answer < 1 || answer > 8);
    return answer;
}

// function to generate pyramid
void generate_pyramid(int input)
{
    // Create line
    for (int i = 0; i < input; i++)
    {
        // Generate elements for the loop
        for (int j = 0; j < input; j++)
        {
            if (j >= input - (i + 1))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
