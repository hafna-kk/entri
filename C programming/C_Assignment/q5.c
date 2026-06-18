/*
Write a C program that uses a function to check whether a given number is a
Perfect Number.
Description: The program should prompt the user to enter a positive integer. A
separate function must be written that computes the sum of all proper divisors of the
number (excluding the number itself) and returns whether the sum equals the original
number. The main function should display whether the number is perfect or not.
(Example: 6 = 1+2+3, 28 = 1+2+4+7+14)
Pre-requisites: Functions, Loops, Return Values.
*/

#include<stdio.h>

// function to check whether the number is perfect or not
void Perfect_or_not(int x)
{
    int sum = 0;  // variable to store sum of divisors

    for(int i = 1; i <= x/2; i++)
    {
        if(x % i == 0)    // checking whether i is divisor of x 
        {
            sum = sum + i; // adding divisor to sum
        }
    }

     // checking whether sum is equal to original number
    if(sum == x)   
    {
        printf("\nThe given number is perfect");
    }
    else
    {
        printf("\nThe given number is not a perfect number");
    }
}

int main()
{
    int n; //variable for storing User input 

    //Taking input from user
    printf("Enter a number: ");
    scanf("%d", &n);

    Perfect_or_not(n); //function call

    return 0;
}