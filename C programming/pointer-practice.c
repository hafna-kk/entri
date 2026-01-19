#include<stdio.h>

//Declare a pointer to int and print its value
/*
int main(void){

    int a=25;
    int *ptr=&a;
    printf("value of ptr is %d",*ptr);
    return 0;
}
*/

//Write a function that changes a variable value to 50 using a pointer.
/*
void change(int *ptr){
   
    *ptr=50;
}
int main(){
    int x=3;
    change(&x);
    printf("x=%d",x);
    return 0;
}
    */

//Swap two numbers using pointer
/*
void swap(int *ptr1 , int *ptr2){
    int temp;
    temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
    
}
int main(){
    int num1,num2;
    printf("enter num1:");
    scanf("%d",&num1);
    printf("enter num2:");
    scanf("%d",&num2);
    swap(&num1,&num2);
    printf("num1=%d,num2=%d",num1,num2);
    return 0;
}
*/
//Increment array elements using pointer .int arr[5] = {1, 2, 3, 4, 5};

/*
int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *Arrptr = arr;

    printf("Before increment:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, *(Arrptr + i));
    }

    // Increment using pointer
    for (int i = 0; i < 5; i++)
    {
        (*(Arrptr + i))++;
    }

    printf("After increment:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, *(Arrptr + i));
    }

    return 0;
}
*/

//Find array length using pointer

int main(){
    int arr[3]={4,6,7};
    int *Arrptr=arr;
    int length=sizeof(arr)/sizeof(*Arrptr);
    printf("length of array=%d",length);
    return 0;
}