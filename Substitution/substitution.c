#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string substitution(string plaintext, string key);



int main(int argc, string argv[])
{
    // Check if it has a command-line argument
    if (argc != 2)
    {
        printf("Missing command-line argumnet.\n");
        return 1;
    }
    // Check if the key has 26 letters
    else if ((strlen(argv [1])) != 26)
    {
        printf("String must contain 26 letters.\n");
        return 1;
    }
    else
    {
        // Checking for duplicates
        for (int i = 0; i < ((strlen(argv[1])) - 1); i++)
        {
            for (int j = i + 1; j < (strlen(argv[1])); j++)
            {
                if ((tolower(argv[1][i])) == (tolower(argv[1][j])))
                {
                    printf("No duplicates.\n");
                    return 1;
                }
                else if ((isalpha(argv[1][j])) == 0)
                {
                    printf("Only letters\n");
                    return 1;
                    break;
                }
            }
        }
        // Getting the plaintext
        string text = get_string("Plaintext: ");
        // Generating the Cypher string
        string n = substitution(text, argv[1]);
        // Printing the cypher
        printf("ciphertext: %s\n", n);
        return 0;
    }
}




string substitution(string plaintext, string key)
{
    // Defining the lists
    string base_Capital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string base_Lower = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < strlen(plaintext); i++)
    {
        // If it is lower case
        if ((isupper(plaintext[i])) == 0)
        {
            // Running the lower list
            int index_lower = 0;
            for (int j = 0; j < (strlen(base_Lower)); j++)
            {
                // If the letter in the plain text encouters the letter in the lower list
                if (plaintext[i] == base_Lower[j])
                {
                    // Making the key_char lower
                    plaintext[i] = tolower(key[index_lower]);
                    break;
                }
                else
                {
                    index_lower ++;
                }
            }
        }
        else if ((isupper(plaintext[i])) != 0)
        {
            // Running the upper list
            int index_upper = 0;
            for (int k = 0; k < (strlen(base_Capital)); k++)
            {
                // If the letter in the plain text encouters the letter in the upper list
                if (plaintext[i] == base_Capital[k])
                {
                    // Making the key_char upper
                    plaintext[i] = toupper(key[index_upper]);
                    break;
                }
                else
                {
                    index_upper ++;
                }
            }

        }
    }
    return plaintext;
}
