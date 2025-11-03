#include<stdio.h>
#include<stdlib.h>
/*
int main(){
    int *p;
    int n;
    printf("\nEnter the number of integer to be stored: ");
    scanf("%d",&n);
    p=(int *)malloc(n* sizeof(int));
    if (p==NULL){
        printf("\n Memory allocation failed");
        return ;
    }
    for(int i=0;i<n;i++){
        printf("\nEnter the %dth integer: ",i+1);
        scanf("%d",p+i);
    }
     printf("\nintegers stored are :" );
     for(int i=0;i<n;i++){
       printf("\n%d",*(p+i));
       
    }
    free(p);
    return 0;

}
int main(){
    int *p;
    p=(int *)malloc(0);
    if(p==NULL){
        printf("memory allocation failed1");
        return ;
    }
*p=50;
printf("value stored using malloc with zero size:%d\n ",*p);
free(p);
return 0;

}*/
/*
#include<stdio.h>

void printbin(int n){
    int mask;
    for(int i=31;i>=0;i--){
        mask=1<<i;
        if(n&mask)
        printf("1");
        else
        printf("0");
    }
}
void setbit(int n,int pos){
    int mask=1<<pos;
    n=n|mask;
    printbin(n);
}
void clearbit(int n,int pos){
    int mask=~(1 << pos);
    n=n & mask;
    printbin(n);
}
int main(){
    int a,b;
    printf("\nEnter an integer : ");
    scanf("%d",&a);
    printbin(a);
    printf("\nEnter a position to set : ");
    scanf("%d",&b);
    setbit(a,b);
    printf("\nEnter a position to clear : ");
    scanf("%d",&b);
    clearbit(a,b);
    return 0;
}
    */

    //Take a number as input from the user and set the 5th bit to 1.
/*
#include<stdio.h>

void printbin(int n){
    int mask;
    for(int i=31;i>=0;i--){
        mask=1<<i;
        if(n&mask)
        printf("1");
        else
        printf("0");
    }
}
void fifthsetbit(int n){
    int mask=1<<5;
  n=n|mask;
  printbin(n);
}
int main(){
    int a;
    printf("\nEnter an integer : ");
    scanf("%d",&a);
    printbin(a);
    printf("\n set fifth bit ");
    fifthsetbit(a);
}
*/
    //Write a code to print the total number of set bit and 0 bit in a number

  #include <stdio.h>

void printbin(int n) {
    int mask;
    for (int i = 31; i >= 0; i--) {
        mask = 1 << i;
        if (n & mask)
            printf("1");
        else
            printf("0");
    }
}

void countBits(int n) {
    int setBits = 0, zeroBits = 0;
    int mask;

    for (int i = 31; i >= 0; i--) {
        mask = 1 << i;
        if (n & mask)
            setBits++;     // bit is 1
        else
            zeroBits++;    // bit is 0
    }

    printf("\nTotal set bits (1s): %d", setBits);
    printf("\nTotal zero bits (0s): %d", zeroBits);
}

int main() {
    int a;
    printf("Enter an integer: ");
    scanf("%d", &a);

    printf("Binary representation: ");
    printbin(a);

    countBits(a);

    return 0;
}
