/* Write a C program that takes an integer from the user and determines whether
the number is even or odd. */

#include<stdio.h>

int main(){

    int n;  //Store the user input number

    printf("Enter a number:"); //Take user input
    scanf("%d",&n); 

    // Check if the number is divisible by 2
    if ( n%2 == 0 ){
        printf("\n%d is Even",n); // If remainder is 0, the number is even
    }
    else{
        printf("\n%d is Odd",n); // If remainder is non 0, the number is odd
    }
    return 0;
}