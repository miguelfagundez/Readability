#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void count_letters(string text);
void count_words(string text);
void count_sentences(string text);
void count_all_values(string text);

// Global variables
int numberOfLetters;
int numberOfWords;
int numberOfSentences;

int main(void)
{
    // Local variables
    float index = 0;
    float l = 0;
    float s = 0;

    // Taking data from user
    string text = get_string("Insert you text here: \n");
    printf("Original Text = %s\n", text);

    // Global variables
    numberOfLetters = 0;
    numberOfWords = 0;
    numberOfSentences = 0;

    // Functions to calculate every value separately
    //count_letters(text);
    //count_words(text);
    //count_sentences(text);

    // Function to calculate all values (Optimization)
    count_all_values(text);

    // Making the Coleman-Liau calculation
    l = (100 * numberOfLetters) / (float)numberOfWords;
    s = (100 * numberOfSentences) / (float)numberOfWords;
    index = (0.0588 * l) - (0.296 * s) - 15.8;

    // Output
    //printf("Number Of Letters = %i\n",numberOfLetters);
    //printf("Number Of Words = %i\n",numberOfWords);
    //printf("Number Of Sentences = %i\n",numberOfSentences);
    //printf("Average L = %f\n", l);
    //printf("Average S = %f\n", s);
    //printf("Index = %f\n", round(index));

    // Final output
    index = round(index);
    if (index < 1.0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        if (index >= 16.0)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", (int)index);
        }
    }
}

// This functions convert a string in lower case
string to_lower(string text)
{
    int n = strlen(text);

    for (int i = 0; i <= n; i++)
    {
        text[i] = tolower(text[i]);
    }

    return text;
}

// This function calculate all values at the same time
void count_all_values(string text)
{
    int n = strlen(text);
    string newText = to_lower(text);

    for (int i = 0; i <= n; i++)
    {
        // Asking for a letter
        if (newText[i] >= 'a' && newText[i] <= 'z')
        {
            numberOfLetters++;
        }
        // Asking for a word
        if ((int) newText[i] == 32)
        {
            numberOfWords++;
        }
        //Asking for a sentence
        if ((int) newText[i] == 33 || (int) newText[i] == 46 || (int) newText[i] == 63)
        {
            numberOfSentences++;
        }
    }
    // I need to count the last word. The final caracter is a dot or null
    numberOfWords++;
}

// This function counts number of letters in a text
void count_letters(string text)
{
    int n = strlen(text);
    string newText = to_lower(text);

    for (int i = 0; i <= n; i++)
    {
        if (newText[i] >= 'a' && newText[i] <= 'z')
        {
            numberOfLetters++;
            printf("%i %c ", numberOfLetters, newText[i]);
        }
    }

}

// This function counts numbers of words in a text
void count_words(string text)
{
    int n = strlen(text);
    string newText = to_lower(text);

    for (int i = 0; i <= n; i++)
    {
        if ((int) newText[i] == 32)
        {
            numberOfWords++;
        }
    }
    numberOfWords++;

}

// This function counts numbers of sentences in a text
void count_sentences(string text)
{
    int n = strlen(text);
    string newText = to_lower(text);

    for (int i = 0; i <= n; i++)
    {
        // 33 = !
        // 46 = .
        // 63 = ?
        if ((int) newText[i] == 33 || (int) newText[i] == 46 || (int) newText[i] == 63)
        {
            numberOfSentences++;
        }
    }

}