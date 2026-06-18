/*11.Write a C program that takes an integer from the user and converts it into a
string of characters.
Description:The program should prompt the user to enter a whole number. It must
then process this integer and store each of its digits as characters within a character
array (string). The resulting string should represent the number exactly as it was
entered, including a negative sign if the number is less than zero. Finally, the program
should display the resulting string on the screen.
Pre-requisites: Strings, Loops, Operators.*/

#include <stdio.h>

int main()
{
    int num, temp, i = 0, sign = 0;
    char str[20];

    printf("Enter an integer: ");
    scanf("%d", &num);

    // Check negative number
    if (num < 0)
    {
        sign = 1;
        num = -num;
    }

    temp = num;

    // Convert each digit to character
    do
    {
        str[i] = (temp % 10) + '0';
        temp = temp / 10;
        i++;
    } while (temp > 0);

    // Add minus sign
    if (sign)
    {
        str[i] = '-';
        i++;
    }

    str[i] = '\0'; // End of string

    // Reverse the string
    int start = 0, end = i - 1;
    char ch;

    while (start < end)
    {
        ch = str[start];
        str[start] = str[end];
        str[end] = ch;
        start++;
        end--;
    }
    printf("String = %s\n", str);

    return 0;
}