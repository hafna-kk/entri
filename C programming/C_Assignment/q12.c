/*12.Write a C program that takes a string from the user and checks whether it is a
palindrome.
Description: The program should prompt the user to enter a string. It must determine
if the string reads the same forward and backward. The program should then display a
message to the user stating whether the input is a palindrome or not.
Pre-requisites: Loops, Control Statements, Strings and Operators.*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int start, end, flag = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    start = 0;
    end = strlen(str) - 1;

    // Compare characters from both ends
    while (start < end)
    {
        if (str[start] != str[end])
        {
            flag = 0;
            break;
        }

        start++;
        end--;
    }
    if (flag)
        printf("Palindrome\n");
    else
        printf("Not a Palindrome\n");

    return 0;
}