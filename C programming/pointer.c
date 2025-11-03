#include<stdio.h>
/*
int a =10;
int *ptr = &a; // int pointer
char b = 'B';
char *ptr1 = &b;
int arr[10]={10,20,30,40,50,60,70,80,90,100};
char arr2[5]={'A','B','C','D','E'};
int *ptr2 = arr; // int pointer to array
char *ptr3 = arr2;
int main(){
    printf("Value of a = %d\n", a);
    a=20;
    printf("Address of a = %p", &a);
    a=45;
    printf("\nAddress of variable a using pointer p and value stored inside pointer p = %p", ptr);
    printf("\nValue inside the address stored in p = %d", *ptr);
    printf("\nAddress of pointer p = %p\n", &ptr);
    printf("Size of integer a = %ld bytes\n", sizeof(a));
    printf("Size of pointer p = %ld bytes\n", sizeof(ptr));
    printf("Size of pointer p = %ld bytes\n", sizeof(ptr1));
   for(int i=0;i<10;i++){
        printf("Value of arr[%d] = %d and address is %p\n", i, *(ptr2+i), (ptr2+i));
    }
     for(int i=0;i<5;i++){
        printf("Value of arr2[%d] = %c and address is %p\n", i, *(ptr3+i), (ptr3+i));
    }
    return 0;
}
*/
#include<math.h>
int arr[5]={1,2,3,4,5};
int *Arrptr=arr;
int main(){

for(int i=0;i<5;i++){
printf("Value of arr[%d] = %d \n", i, *(Arrptr+i)+5);

}
return 0;
}