/* Write a C program that takes a positive integer from the user and calculates its
factorial.
*/

#include<stdio.h>

int main(){

    int n; //Variable to store user entered number
    long long int fact=1;  // long long int is used to handle larger factorial values

    printf("Enter a number:\n"); //Take user input
    scanf("%d",&n); 

    // Check for negative input
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    }
    else if (n==0){
       printf("Factorial of zero is 1.\n");  //Factorial of zero is always 1.  
    }
    else{
        for(int i=1;i<=n;i++){
            fact*=i;  //multiply all positive integers from 1 up to n
        }
        printf("Factorial of %d is %lld", n , fact); 
    }

    return 0;
}