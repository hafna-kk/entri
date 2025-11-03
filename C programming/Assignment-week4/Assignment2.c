/*
You are given an 8-bit register represented as an unsigned char. Write a function to:

Set the 3rd bit (bit index 2).

Clear the 6th bit (bit index 5).

Toggle the 1st bit (bit index 0). Return the modified register value.

Note: Use bitwise operators only. Avoid loops or conditionals.
*/
#include<stdio.h>
#include<stdlib.h>

void printbin(int n){
    int mask;
 for (int i=7;i>=0;i--){
   mask=1<<i;
    if(n&mask){
     printf("1");
    }
    else{
        printf("0");
    }}
    printf("\n");
}
unsigned char Bit(unsigned char n){
 n = n | (1 << 2);   // Set the 3rd bit (bit index 2)
    n = n & ~(1 << 5);  // Clear the 6th bit (bit index 5)
    n = n ^ (1 << 0);   // Toggle the 1st bit (bit index 0)
       return n;
}
int main(){
    unsigned char a;
    printf("\nEnter an integer(0 to 255): ");
    scanf("%hhu",&a);
    printf("\nBinary representation: ");
    printbin(a);
    printf("\nAfter the operations (binary):");
    a=Bit(a);
    printbin(a);
    printf("\nAfter the operations (decimal) : %d\n",a);
    
    return 0;
}

