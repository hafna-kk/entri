/*Write a C program that uses a recursive function to find the GCD of two
numbers using the Euclidean algorithm.
Description: The program should prompt the user to enter two positive integers. A
recursive function must be written that repeatedly applies the Euclidean method
replacing the larger number with the remainder of dividing the two until the
remainder is zero. The GCD should be returned to the main function and displayed on
the screen.
Pre-requisites: Functions, Recursion, Modulus Operator.*/

#include<stdio.h>

// recursive function to find gcd
int gcd(int x,int y){

if(y == 0)
{
    return x;
}
else
{
    return gcd(y, x % y); //recursive call
}
}

int main(){

    int a,b,result;
    // taking input from user
    printf("\nEnter two positive intergers:");
    scanf("%d%d",&a,&b);

    //function call
    result=gcd(a,b);
    printf("\nGCD of %d and %d is %d:",a,b,result);
    return 0;
}