//Write a Program to find the Sum of two numbers entered by the user.
/*
#include<stdio.h>
int sum(int x,int y){
    int result;
    result=x+y;
    printf("\nsum =%d",result);
}

int main(){
    int a;
    int b;
    printf("enter the first number: ");
    scanf("%d",&a);
    printf("\nenter the second number: ");
    scanf("%d",&b);
    sum(a,b);
    
    return 0;
}




#include<stdio.h>
int main(){
    int a,b,sum ;
    printf("enter 2 integers: ");
    scanf("%d %d", &a, &b);
    sum=a+b;
    printf("\nresult = %d",sum);
    return 0;
}
    */

//Write a Program to find the size of int, float, double, and char.
/*
#include<stdio.h>
int main(){
    printf("size of int: %d",sizeof(int));
     printf("\nsize of float: %d",sizeof(float));
      printf("\nsize of double: %d",sizeof(double));
       printf("\nsize of char: %d",sizeof(char));
    return 0;
}
    */

    //Write a Program to Swap the values of two variables.
/*
#include<stdio.h>

int main(){
    int x,y,z;
    
    printf("enter the value for x: ");
    scanf("%d",&x);
    printf("enter the value for y: ");
    scanf("%d",&y);
    z=x;
    x=y;
    y=z;
    printf("after swapping x= %d , y=%d ", x ,y);
    return 0;
}*/

// Write a Program to calculate Compound Interest.
/*
#include<stdio.h>
#include<math.h>


int main(){
    float principal_amount ;
    float rate ;
    float time ;
    float amount;
    float compound_interest;
    printf("enter the principal amount:");
    scanf("%f",&principal_amount);
    printf("enter the rate: ");
    scanf("%f",&rate);
    printf("enter the time: ");
    scanf("%f",&time);
    amount= principal_amount* pow((1+rate/100),time);
    printf("amount is : %f",amount);
    compound_interest=amount-principal_amount;
    printf("\ncompound interest is : %f",compound_interest);
    return 0;

}*/

//Write a Program to check if the given number is Even or Odd.
/*
#include<stdio.h>
int main(){
    int A;
    printf("enter a number: ");
    scanf("%d",&A);
    if ( A % 2==0){
        printf("%d is even",A);
    }
    else{
        printf("%d is odd",A);
    }
    return 0;
}
    */

//Write a Program to find the largest number among three numbers.
/*
#include<stdio.h>

int main(){
    int A,B,C;
    printf("Enter the first number: ");
    scanf("%d",&A);
    printf("\nEnter the second number: ");
    scanf("%d",&B);
    printf("\nEnter the third number: ");
    scanf("%d",&C);
    if(A>=B && A>=C){
        printf("\n%d is the largest number",A);

    }
    else if(B>=A && B>=C){
        printf("\n%d is the largest number",B);
    }
    else{
        printf("\n%d is the largest number",C);
        
    }
    return 0;
}
   
*/

//Write a Program to make a simple calculator.
/*
#include <stdio.h>

int add(int a,int b) { return a+b; }
int minus(int a,int b) { return a-b; }
int mult(int a,int b) { return a*b; }
float divd(int a,int b) { return (float)a / b; }

int main() {
    int num1, num2;
    char op;
    float result;

    printf("Simple Calculator\n");
    printf("*******************\n");

    printf("Enter operand 1: ");
    scanf("%d", &num1);

    printf("Enter the operator '+,-,*,/': ");
    scanf(" %c", &op);  // space before %c

    printf("Enter operand 2: ");
    scanf("%d", &num2);

    if (op == '+') {
        result = add(num1, num2);
        printf("Result is: %.2f\n", result);
    } else if (op == '-') {
        result = minus(num1, num2);
        printf("Result is: %.2f\n", result);
    } else if (op == '*') {
        result = mult(num1, num2);
        printf("Result is: %.2f\n", result);
    } else if (op == '/') {
        if(num2 != 0) {
            result = divd(num1, num2);
            printf("Result is: %.2f\n", result);
        } else {
            printf("Error: Division by zero!\n");
            return 1;
        }
    } else {
        printf("Invalid operator!\n");
        return 1;
    }

    return 0;
}
*/

//Write a Program to find the factorial of a given number.
/*
#include<stdio.h>
int main(){
    int A;
    int fact=1,i;
    printf("Enter a number : ");
    scanf("%d",&A);
    for(i=1;i<=A;i++)
    {
    fact=fact*i;
   
}
 printf("\nFactorial of %d is: %d",A,fact);
return 0;
}  */

//Write a Program to Convert Binary to Decimal.
/*
#include<stdio.h>

int main(){
    int binary,decimal =0,base=1,reminder; //decimal is the finding variable. Start from zero(addition)
    printf("Enter a binary number: ");
    scanf("%d",&binary);
    int temp=binary;
while(binary>0){
    reminder=binary % 10;
    decimal=decimal+base*reminder; //for finding last digit is 0 or 1.
    binary=binary/10;
    base=base*2;
    
    }
printf("\nbinary: %d => Corresponding decimal is: %d",temp,decimal);
return 0;


}
*/

// Write a Program to print the Fibonacci series 
/*
#include<stdio.h>

int main(){
    int first=0,second=1,next;
    int n,i;
    printf("Enter value of n : ");
    scanf("%d",&n);
    printf("\nFibinacci series  is : ");
    for(i=1;i<=n;i++){
     printf("%d",first);  
    next=first+second;
    first=second;
    second=next;
     }
      return 0;
}
      */

//Write a Program to Calculate the Sum of Natural Numbers using recursion.
/*
#include<stdio.h>

int sum(int n){
    if (n==0){
        return 0;

    }
    else{
        return n+sum(n-1);
    }
}

int main(){
    int num;
    printf("Enter the number: ");
scanf("%d",&num);
    printf("\nSum of %d natural number is %d",num,sum(num));
    return 0;

    
}*/

//Write a Program to find the maximum and minimum of an Array.
/*
#include<stdio.h>
int main(){
    int n;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
   
    int i, arr[n];
    printf("\nEnter the elements");
    for(i=0;i<n;i++){  
       scanf("%d",&(arr[i]));    
    }
    printf("\n arr[n]=");
    for(i=0;i<n;i++){  
       printf("%d ",arr[i]);    
    }
int max=arr[0];
for(i=1;i<n;i++){
if(arr[i]>max){
    max=arr[i];
}
}
printf("\nMaximum number in array is %d ",max);
int min=arr[0];
for(i=1;i<n;i++){
    if(arr[i]<min){
    min=arr[i];
}
}
printf("\nMinimum number in array is %d ",min);
return 0;
}
*/

