/*Write a C program that takes a string from the user and replaces every sequence of
multiple consecutive spaces with a single space.
Description: The program should prompt the user to enter a sentence that may
contain several spaces between words. It must then process the string to ensure that
any instance where two or more blank spaces appear together is reduced to just one
blank space. The final cleaned string should be displayed on the screen.
Pre-requisites: Loops, Strings, Conditional Statements, ASCII, Operators*/

#include <stdio.h>

int main()
{
    char str[200];
    int i, j = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    // Remove extra spaces
    for (i = 0; str[i] != '\0'; i++)
    {
        // Skip a space, if the next character is also a space
        if (!(str[i] == ' ' && str[i + 1] == ' '))
        {
            str[j] = str[i];
            j++;
        }
    }

    str[j] = '\0'; // End the string

    printf("New string: %s", str);

    return 0;
}