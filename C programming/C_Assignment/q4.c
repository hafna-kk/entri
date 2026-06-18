/*Write a C program to generate the Fibonacci series up to a given number of terms.*/

#include<stdio.h>

int main(){

    int n; //Variable to store user entered number
    int a=0 , b=1,next;
     

    printf("Enter a number:\n"); //Take user input
    scanf("%d",&n); 

    // Check for negative input
    if (n < 0) {
        printf("Fibnacci series is not defined for negative numbers.\n");
    }
    else{
        printf("Fibonacci series up to %d terms:\n", n);
        for(int i=1;i<=n;i++){
            printf("%d ", a); //print current term
            next = a + b ; // print next term
            a=b;      //store second term into a
            b=next;    //store next term into b
        }
       
    }

    return 0;
}