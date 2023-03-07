#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get height of grid
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    //Print left grid
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            printf(" ");
        }
        for (int g = n + i + 1; g > n; g--)
        {
            printf("#");
        }
        //Print right grid
        printf("  ");

        for (int g = n + i + 1; g > n; g--)
        {
            printf("#");
        }
        printf("\n");
    }
}
