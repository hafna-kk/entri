/*Write a C program that takes a string from the user and reverses its characters using
an iterative approach.
Description: The program should prompt the user to enter a sequence of characters. It
must then swap or move the characters within the string using a loop until the entire
string is reversed. The final resulting string should be displayed on the screen.
Pre-requisites: Loops, Strings. Operators.*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int start, end;
    char temp;

    printf("Enter a string: ");
    scanf("%s", str);

    start = 0;                 // First character
    end = strlen(str) - 1;     // Last character

    // Swap characters from both ends
    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}