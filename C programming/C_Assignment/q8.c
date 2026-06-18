/*Write a C program that uses functions to convert a decimal number to any base
between 2 and 16.
Description: The program should prompt the user to enter a decimal number and a
target base. A separate function must be written that performs the repeated division
method, stores each remainder, and builds the result in the correct order. For bases
above 9, remainders 10–15 should be represented as letters A–F. The converted value
should be displayed from the main function.
Pre-requisites: Functions, Loops, Arrays, Character Handling.*/

#include <stdio.h>

//function to convert the number
void convert(int num, int base, char result[])
{
    int i = 0, rem;

    while (num > 0)
    {
        rem = num % base;

        if (rem < 10)
            result[i] = rem + '0';
        else
            result[i] = rem - 10 + 'A';

        num = num / base;
        i++;
    }

    result[i] = '\0';

    // Reverse the string
    int start = 0, end = i - 1;
    char temp;

    while (start < end)
    {
        temp = result[start];
        result[start] = result[end];
        result[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    int num, base;
    char result[50];
    printf("Enter decimal number: ");
    scanf("%d", &num);
    printf("Enter base (2-16): ");
    scanf("%d", &base);

    if (base < 2 || base > 16)
    {
        printf("Invalid base!\n");
        return 0;
    }

    convert(num, base, result);
    printf("Converted number = %s\n", result);

    return 0;
}