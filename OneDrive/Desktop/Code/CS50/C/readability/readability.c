#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float grade_level(string text);

int main(void)
{
    //Ask the user for input of text
    string text = get_string("Text: ");
    //Print grade level
    if ((float)grade_level(text) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if ((float)grade_level(text) >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)grade_level(text));
    }
}
//Create variable for grade level
float grade_level(string text)
{
//Calculate letters, words and sentences and determine grade level

    float letters = 0;
    float words = 1;
    float sentences = 0;
    float Coleman_Index = 0;

    for (int n = 0; n < strlen(text); n++)
    {
        if ((text[n] >= 'A' && text[n] <= 'Z') || (text[n] >= 'a' && text[n] <=
                'z'))
        {
            letters++;
        }
        else if (text[n] == 32)
        {
            words++;
        }
        else if ((text[n] == '!') || (text[n] == '?') || (text[n] == '.'))
        {
            sentences++;
        }
//Calculate Coleman Liau Index
        float L = (letters / words * 100);
        float S = (sentences / words * 100);
        Coleman_Index = (0.0588 * L - 0.296 * S - 15.8);
    }
//Return variable for grade level rounded to a whole number
    return round(Coleman_Index);
}