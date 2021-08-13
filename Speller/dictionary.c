
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "dictionary.h"

#define SIZE 65536

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// DEclaring number of words in the dictionary
long num_words = 0;
// declare hashtable
node *hashtable[SIZE];

// hash funtion from cs50 stack exchange
unsigned int hash(const char *word)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
        hash = (hash << 2) ^ word[i];
    return hash % SIZE;
}

// Check function
bool check(const char *word)
{
    // convert to lower case
    int len_word = strlen(word);
    char checkword[len_word + 1];
    for (int i = 0; i < len_word; i++)
    {
        checkword[i] = tolower(word[i]);
    }
    
    checkword[len_word] = '\0';

    int index = hash(checkword);
    
    node *cursor = hashtable[index];
    
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, checkword) != 0)
        {
            cursor = cursor->next;
        }
        else
        {
            return true;
        }
    }
    return false;
}

// Load function
bool load(const char *dictionary)
{
    FILE *dictionaryFile = fopen(dictionary, "r");

    if (dictionary == NULL)
    {
        printf("Could not open the dictionary file");
        return false;
    }
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i] = NULL;
    }

    char load_word[LENGTH + 1];

    while (fscanf(dictionaryFile, "%s", load_word) != EOF)
    {
        node *newnode = malloc(sizeof(node));

        strncpy(newnode->word, load_word, sizeof(load_word));


        int index = hash(load_word);


        if (hashtable[index] == NULL)
        {
            hashtable[index] = newnode;
        }

        else
        {
            newnode->next = hashtable[index];
            hashtable[index] = newnode;
        }
        num_words ++;
    }
    fclose(dictionaryFile);
    return true;
}

// Size function
unsigned int size(void)
{
    return num_words;
}


// Unload function
bool unload(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (hashtable[i] != NULL)
        {
            node *pointer = hashtable[i];
            
            while (pointer != NULL)
            {
                node *temp = pointer;
                pointer = pointer->next;
                free(temp);
            }
        }
    }
    return true;
}