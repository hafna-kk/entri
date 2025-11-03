/*
Write a C program to print a pyramid of stars for a given number n.

If n = 5, the output should be:

    *
   ***
  *****
 *******
*********
*/

#include<stdio.h>
int main(){
    int n;
    printf("\nEnter the number of rows : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){

        for(int j=0;j<2*(n-i)-1;j++){
            printf(" ");
        }
        for(int k=0;k<2*i+1;k++){
 printf("* ");
        }
        printf("\n");
    }
    return 0;
}
   