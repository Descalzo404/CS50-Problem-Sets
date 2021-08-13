#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int Coleman_Liau_index(string string);

int main(void)
{
    string s = get_string("Text:");
    if (Coleman_Liau_index(s) >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (Coleman_Liau_index(s) < 1)
    {
        printf("Before Grade 1\n");
    }
    else 
    {
        printf("Grade %i\n", Coleman_Liau_index(s));
    }
}

// Calculates the grade
int Coleman_Liau_index(string s)
{
    // Declaring the counting values
    int letters = 0;
    int words = 0;
    int sentences = 0;
    int checkword = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // If it is a letter in the same word
        if ((isalpha(s[i]) != 0) && checkword == 1)
        {
            checkword = 1;
            letters ++;
        }
        // If it is a letter in a new word
        else if ((isalpha(s[i]) != 0) && (checkword == 0))
        {
            letters ++;
            checkword = 1;
            words ++;
        }
        // If it is an end of a sentence
        else if ((isdigit(s[i]) == 0) && (s[i] == '.' || s[i] == '!' || s[i] == '?'))
        {
            sentences ++;
            checkword = 0;
        }
        // If it is a space
        else if (isspace(s[i]) != 0)
        {
            checkword = 0;
        }
    }
    // The numbers of letters in 100 words
    float letters_for_100 = (100 * (float) letters) / (float) words;
    // The number of sentences in 100 words
    float sentences_for_100 = (100 * (float) sentences) / (float) words;
    // Calculating the index
    float index = 0.0588 * letters_for_100 - 0.296 * sentences_for_100 - 15.8;
    return round(index);
}