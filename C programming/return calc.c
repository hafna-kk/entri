#include<stdio.h>
int addition(int a, int b){  //function definition of addition
   int add=a+b;  
   return add;

}
int substraction(int a, int b){
   int sub=a-b;
   return sub;

}
int multiplication(int a, int b){
   int mul=a*b;
   return mul;

}
int division(int a, int b){
   int divd=a/b;
   return divd;

}
int main(){
    int num1 ,num2;
    int result;
     printf("Enter your first number: ");
    scanf("%d",&num1);
    printf("Enter your second number: ");
    scanf("%d",&num2);
    result=addition(num1 , num2);
    printf("\nsum is :%d",result);
 result=substraction(num1 , num2);
 printf("\nsubstracted result is :%d",result);
   result= multiplication(num1 , num2);
   printf("\nmultiplied result is :%d",result);
  result=  division(num1 , num2);
  printf("\ndivided result is :%d",result);
  return 0;
}