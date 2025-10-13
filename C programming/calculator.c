#include <stdio.h>


float add(float a, float b) // the function definition for addition 
{
    float sum;
    sum=a+b;   // copy of num1+ copy of num2
   
    return sum;

}

float sub(float a, float b) // the function definition for subtraction 
{
    float diff;
    diff=a-b;
    
    return diff;
    
}
float mul(float a, float b) // the function definition for multiplication 
 {
    float product;
    product=a*b;
    
    return product;
    
    
}
float divd( float a, float b) // the function definition for division
{
    float quotient;
    if( b==0 ){
        printf("\ndivided by 0 error");
        return 0;
    }
    else {
    quotient=a/b;
    return quotient;
    }
}

int main()
{
    float num1, num2, result;
    char op;
    
    printf("Simple Calculator\n");
    printf("*******************\n");
    
    printf("Enter first integer: ");
    scanf("%f",&num1);
    
    printf("\nEnter the operator(+,-,*,/) : ");
    
    scanf(" %c",&op);
    
    printf("\nEnter the second number:");
    
    scanf("%f",&num2);
  /* 
    if(op=='+')                         // conditional statement 
    {
           result=add(num1, num2);   // result=sum;
    }
    else if(op=='-')
    {
           result=sub(num1, num2);  // result sub
    }
    else if(op=='*')
    {
         result=mul(num1, num2);    //result =mul
    }
    
    else if(op=='/')
    {
          result= divd(num1, num2);  //result =div
    }

    else 
    {
        printf("\n R u an idiot ? Invalid operator");
        result=0;
    }
   */ 

switch (op){
        case '+':
        result=add(num1, num2); 
        break;
        case '-':
        result=sub(num1, num2);
        break;
        case '*':
        result=mul(num1, num2);
        break;
        case '/':
        result= divd(num1, num2);
        break;
 default:
  printf("\n R u an idiot ? Invalid operator");
        result=0;
        break;
   }
  
    printf("\nResult is = : %.2f",result);

    return 0;
}