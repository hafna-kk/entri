/*#include <stdio.h>

int main() {
  int num=13;
  float a=11.11;
  printf("num is %d",num);
  printf("\na is %f",a);
  return 0;}
*/
/*
#include<stdio.h>

int main(){
  int a,b,sum;
  printf("\nEnter 2 numbers: ");
  scanf("%d %d",&a,&b);
  sum=a+b;
  printf("\nSum = %d",sum);
  return 0;
}
  */
//find even or odd
/*
#include<stdio.h>
int main(){
  int num;
  printf("\n Enter a number: ");
  scanf("%d",&num);
  if (num % 2){
    printf("\n %d is odd",num);

  }
  else{
    printf("\n %d is even",num);
  }
  return 0;
}
  */
//find area of a circle
/*
#include<stdio.h>
#define pi 3.14

int main(){
  float r , area;
  printf("\nEnter the radius:");
  scanf("%f",&r);
  area=pi*(r*r);
  printf("\nArea of the circle:%.2f",area);
  return 0;
}
*/
/*
#include <stdio.h>

int main() {
    char c;
    printf("Enter a character: ");
    scanf(" %c", &c);
    printf("ASCII Value of %c = %d", c, c);
    return 0;
}
*/
//Create a simple Menu-Driven Calculator:
/*
Add, Subtract, Multiply, Divide

Use switch statement

Keep running until user selects “Exit”
*/
/*
#include<stdio.h>
int main(){
  float a,b;
  int op;
  while (1)
  {
   
  
  
        printf("\n--- Simple Calculator ---\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("\nEnter your choice:");
       scanf("%d",&op);
       if(op==5)
  {
    printf("Exiting the calculator... Goodbye!\n");
     break;
 }
  printf("\nEnter first number:");
  scanf("%f",&a);
  
   printf("\nEnter second number:");
  scanf("%f",&b);
  
  
  switch (op)
  {
  case 1:
    printf("\nSum=%.2f",a+b);
    break;
  case 2:
    printf("\nDifference=%.2f",a-b);
    break;
    case 3:
    printf("\nproduct=%.2f",a*b);
    break;
    case 4:
     if(b != 0)
                    printf("Result = %.2f\n", a / b);
                else
                    printf("Error: Division by zero!\n");
                break;
   
  default:
  printf("Invalid choice! Please try again.\n");

    break;
  }
  
}
return 0;
}
*/
//Check if a number is even or odd.
/*
#include<stdio.h>
int main(){
  int num;
  printf("\nEnter a number: ");
  scanf("%d",&num);
  if(num%2==0){
    printf("\n%d is even",num);

  }
  else{
     printf("\n%d is odd",num);
  }
      return 0;
}
*/
//Check if a number is positive, negative, or zero.
/*
#include<stdio.h>
int main(){
  int num;
  printf("\nEnter a number: ");
  scanf("%d",&num);
  if(num>0){
    printf("\n%d is positive",num);

  }
  else if(num<0){
     printf("\n%d is negetive",num);
  }
  else{
     printf("\n%d is zero",num);
  }
      return 0;
}
*/
//Find the greatest of three numbers.
/*
#include<stdio.h>
int main(){
  int num1,num2,num3;
  printf("\nEnter 3 numbers: ");
  scanf("%d %d %d",&num1,&num2,&num3);
  if(num1>num2 & num1>num3){
    printf("\n%d is largest",num1);

  }
  else if(num1<num2 & num2>num3){
     printf("\n%d is largest",num2);
  }
  else{
     printf("\n%d is largest",num3);
  }
  return 0;
}
  */
//Check if a year is a leap year.
/*
#include<stdio.h>
int main(){
  int year;
  printf("\nEnter a year: ");
  scanf("%d",&year);
  if(year%400==0 || (year%4==0 && year%100!=0)){
    printf("\n%d is a leap year",year);

  }
 
  else{
    printf("\n%d is not a leap year",year);

  }
      return 0;
}
      */
//Input marks of 5 subjects, calculate total and average, then print grade:
/*
>=90 → A
>=80 → B
>=70 → C
>=60 → D
Else → Fail
*/
/*
#include<stdio.h>
int main(){
  int s1,s2,s3,s4,s5;
  printf("\nEnter the 5 subjects marks: ");
  scanf("%d %d %d %d %d",&s1,&s2,&s3,&s4,&s5);
  int total = s1+s2+s3+s4+s5;
  float avg=total/5.0;
   printf("\nTotal = %d", total);
    printf("\nAverage = %.2f", avg);
  if(avg>=90){
    printf("\nYour grade is A ");
  }
  else if(avg>=80){
    printf("\nYour grade is B ");
  }
else if(avg>=70){
    printf("\nYour grade is C ");
  }
  else if(avg>=60){
    printf("\nYour grade is  D");
  }
  else{
    printf("\nFailed");
  }
  return 0;
}
  */
 //1. Print 1–10 using for, while, and do-while
  /*
 #include<stdio.h>

 int main(){
  for(int i=1;i<=10;i++){
    printf("\n%d",i);
  }
  return 0;
 }
 
 int main(){
  int i=1;
  while(i<=10){
   
  printf("\n%d",i);
   i++;
  }
  return 0;
 }
 

 int main(){
  int i=1;
  do{
   printf("\n%d",i);
   i++;
  }while(i<=10);
  return 0;
 }
  */
 //Sum of first N natural numbers
 /*
  #include<stdio.h>
 int main(){
  int n,sum=0;
  printf("\nEnter a number: ");
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    sum=sum+i;
   
  }
   printf("\nSum=%d",sum);
   return 0;
 }
   */

 //Print multiplication table of a given number.
/*   #include<stdio.h>
 int main(){
  int n;
  printf("\nEnter a number: ");
  scanf("%d",&n);
  for(int i=1;i<=10;i++){
  printf("\n%d*%d=%d",i,n,i*n);  
  }
 
   return 0;
 }
   */
  //Find factorial of a number.
  /*
  #include<stdio.h>
int main(){
  int n;
  printf("\nEnter a number: ");
  scanf("%d",&n);
  int fact=1;
  for(int i=1;i<=n;i++){
     fact=fact*i;

  }
  printf("\nFactorial of %d is %d",n,fact);
  return 0;
}
  */
//Count digits of a number.
/*
#include<stdio.h>
int main(){
  int n,count=0;
  printf("\nEnter a number: ");
  scanf("%d",&n);
  int z=n;
while(n!=0){
    count++;
    n=n/10;
  }
  printf("\nnumber of digits in %d is %d",z,count);
  return 0;
}
  */
//Reverse a number.
/*
#include<stdio.h>
int main(){
  int n,rev=0,rem;
  printf("\nEnter a number: ");
  scanf("%d",&n);
while(n!=0){
   rem=n%10;
  rev=rev*10+rem;
  n=n/10;
}
printf("\nreversed number  is %d",rev);
  return 0;
}

*/
//Print Fibonacci series.
/*
#include<stdio.h>
int main(){
  int n,first=0,second=1,next;
  printf("\nEnter a number: ");
  scanf("%d",&n);
   printf("\nfibnacci series is: ");
for(int i=1;i<=n;i++){
  printf("%d",first);
  next=first+second;
  first=second;
  second=next;
}
  return 0;
}
  */
 //Sum of digits of a number.
 /*
 #include<stdio.h>
int main(){
  int n,last,sum=0;
  printf("\nEnter a number: ");
  scanf("%d",&n);
while(n!=0){
  last=n%10;
  sum=sum+last;
  n=n/10;

}
printf("\nsum=%d",sum);
  return 0;
}
  */
 //Check palindrome number.
 /*
 #include<stdio.h>
int main(){
  int n,rev=0,rem;
  printf("\nEnter a number: ");
  scanf("%d",&n);
  int original=n;
while(n!=0){
   rem=n%10;
  rev=rev*10+rem;
  n=n/10;
}
if (original==rev){
  printf("\n number is palindrome");

}
else{
    printf("\n number not  is palindrome");
}

  return 0;
}
  */
 //Print  patterns .
 //right half pyramid
 /*
 #include<stdio.h>
 int main(){
  int n;
  printf("\nEnter a number: ");
  scanf("%d",&n);
 for(int i=1;i<=n;i++){
     for(int j=1;j<=i;j++){
       printf("* ");
     }
    printf("\n");
 }
  return 0;
 }
  */
 //left half pyramid
 /*
  #include<stdio.h>
 int main(){
  int n;
  printf("\nEnter a number: ");
  scanf("%d",&n);
 for(int i=1;i<=n;i++){
     for(int j=1;j<=n-i;j++){

       printf(" ");
     }
     for(int k=1;k<=i;k++){
       printf("*");
     }
     
    printf("\n");
 }
  return 0;
 }
  */
 //full pyramid
 /*
 #include<stdio.h>
 int main(){
  int n;
  printf("\nEnter the number ");
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
       for(int j=1;j<=n-i;j++){
        printf(" ");
       }
       for(int k=1;k<=i;k++){
        printf("* ");
       }
       printf("\n");
  }
  return 0;
 }
  */

  

#include <stdio.h>

int main()
{

    // Normal Variable
    int var = 10;

    // Pointer Variable ptr that stores address of var
    int *ptr = &var;

    // Directly accessing ptr will give us an address
    printf("%d", ptr);

    return 0;
}