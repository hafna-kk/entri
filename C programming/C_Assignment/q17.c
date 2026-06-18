/*Write a C program that takes a number and toggles a specific number of bits (n)
starting from a given position.
Description: The program should prompt the user to enter an integer, a starting bit
position, and the number of bits to be modified. It must then change the state of those
(n) consecutive bits—switching 0s to 1s and 1s to 0s—while keeping all other bits in
the number exactly as they were. The final value of the number after the toggle
operation should be displayed on the screen.
Pre-requisites: Bitwise operators, Loops, Assignment operators.*/

#include <stdio.h>

int main()
{
    int num, pos, n, mask;

    printf("Enter number: ");
    scanf("%d", &num);

    printf("Enter starting position: ");
    scanf("%d", &pos);

    printf("Enter number of bits to toggle: ");
    scanf("%d", &n);

    // Create mask with n bits set to 1
    mask = ((1 << n) - 1) << pos;

    // Toggle selected bits
    num = num ^ mask;

    printf("Result after toggling = %d\n", num);

    return 0;
}