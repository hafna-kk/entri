/*Write a C program that takes a string input from the user and determines whether it is
a pangram or not.
Description: The program should prompt the user to enter a sentence or a string of
characters. It must then verify if every letter of the alphabet from A to Z appears at
least once within the provided text, regardless of whether the letters are uppercase or

lowercase. The final output should state if the string is a pangram.
Pre-requisites: Loops, Strings, Conditional Statements, ASCII, Operators*/

#include <stdio.h>

int main()
{
    char str[200];
    int alphabet[26] = {0};
    int i, count = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    // letters present in the string
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            alphabet[str[i] - 'A'] = 1;

        else if (str[i] >= 'a' && str[i] <= 'z')
            alphabet[str[i] - 'a'] = 1;
    }
    // Count how many alphabets are present
    for (i = 0; i < 26; i++)
    {
        if (alphabet[i] == 1)
            count++;
    }
    // Check if all 26 letters are present
    if (count == 26)
        printf("The string is a Pangram.\n");
    else
        printf("The string is NOT a Pangram.\n");

    return 0;
}