#include<stdio.h>

void add(int a,int b){
    int sum;
    sum=a+b;
    printf("sum is :%d",sum);
}
void sub(int a,int b){
    int diff;
    diff=a-b;
    printf("\ndifference is :%d",diff);
}
void mul(int a,int b){
    int mul;
    mul=a*b;
    printf("\nmultiplied result is: %d",mul);
}
void div(int a,int b){
   int divided;
   divided=a/b;
   printf("\ndivided result is: %d",divided);
}
int main(){
    int num1 , num2;
    int result;
    printf("Enter your first number: ");
    scanf("%d",&num1);
    printf("Enter your second number: ");
    scanf("%d",&num2);
    add(num1 , num2);
    sub(num1 , num2);
    mul(num1 , num2);
    div(num1 , num2);
return 0;
}