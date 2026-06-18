/*Write a C program that uses a function to count the frequency of each digit (0–9)
in a given integer.
Description: The program should prompt the user to enter an integer. A separate
function must be written that takes the number, extracts each digit using a loop, and
updates a frequency array accordingly. The function should not return a single value
but instead update the array directly. The main function should then print how many
times each digit appears in the number.
Pre-requisites: Functions, Arrays, Loops, Pass by Reference (Pointers).*/

#include<stdio.h>

//function to count the frequency of each digit
void frequency(int n,int freq[]){

    int digit;

    while(n>0){

        digit = n%10; //finding last digit

        freq[digit]++; //increasing frequency

        n=n/10; //removing last digit

    }
}

int main(){

    int n;
    int freq[10]={0}; // array to store frequency of digits 0-9

    //Taking user input
    printf("\n Enter a integer:");
    scanf("%d",&n);

    //function call
    frequency(n,freq);
    
    // printing frequency of each digit
    printf("\nFrequency of digits:\n");

    for(int i=0;i<=9;i++){
        printf("\n Digit %d = %d times",i ,freq[i]);
    }
    return 0;
}