/*18.Write a C program that takes an integer from the user and extracts (n) bits starting
from a specific bit position.
Description: The program should prompt the user to enter a number, a starting
position, and the number of bits to be retrieved. It must then isolate that specific
sequence of bits from the original value and display the resulting number on the
screen. The other bits in the number should not affect the final output.
Pre-requisites: Bitwise Operators.*/

#include <stdio.h>

int main()
{
    int num, pos, n, mask, result;

    printf("Enter number: ");
    scanf("%d", &num);

    printf("Enter starting position: ");
    scanf("%d", &pos);

    printf("Enter number of bits to extract: ");
    scanf("%d", &n);

    // Create mask for required bits
    mask = ((1 << n) - 1) << pos;

    // Extract required bits
    result = (num & mask) >> pos;

    printf("Extracted value = %d\n", result);

    return 0;
}