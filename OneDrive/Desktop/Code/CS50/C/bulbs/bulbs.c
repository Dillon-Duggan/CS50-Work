#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // Ask for input from user
    string message = get_string("Please enter a message: ");

    //Convert string to ASCII and then binary
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        int decimal = message[i];
        int binary[] = {0, 0, 0, 0, 0, 0, 0, 0};
        int j = 0;

        while (decimal > 0)
        {
            binary[j] = decimal % 2;
            decimal = decimal / 2;
            j++;
        }

        //Print binary (in reverse to show correct orientation of bulbs)
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(binary[k]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}