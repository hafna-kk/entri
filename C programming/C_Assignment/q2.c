/*Write a C program that asks the user to enter a number and determines whether that
number is prime or not.
*/

#include<stdio.h>

int main(){

    int n;
    printf("\nEnter a number: ");
    scanf("%d",&n);
    if(n<2){
        printf("\n%d is not a prime number",n);
    }
    else{
        for(int i=2; i*i<=n ;i++){
            if( n % i==0 ){
                printf("\n%d is not a prime number",n);
                return 0;
            }
           
        }
        printf("\n%d is a prime number",n);
    }

    return 0;
}