#include <stdio.h>

/*Write a C program that takes a string of digits from the user and converts it into its equivalent
integer value.
Description:The program should prompt the user to enter a number as a string (for example,
"1234"). It must then process this string character by character and transform it into an actual
integer variable that can be used for mathematical operations. The program should be able to
handle positive numbers and display the final integer result on the screen.
Pre-requisites: Loops, Strings, Operators.*/

int main()
{
    char str[100];      // Store the number as a string
    int num = 0, i = 0; // num stores final integer value

    printf("Enter a number: ");
    scanf("%s", str);

    // Convert string to integer
    while (str[i] != '\0')
    {
        num = num * 10 + (str[i] - '0'); // Add current digit
        i++;
    }

    printf("Integer value = %d\n", num);

    return 0;
}