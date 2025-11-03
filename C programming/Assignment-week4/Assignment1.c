/*
Write a function in C that takes an array of integers and its size, and returns the second largest element.

Constraints:

Do not sort the array.

Assume the array has at least two distinct elements.
*/
#include<stdio.h>

int main(){
    int n;
    printf("\nEnter the number of elements in array : ");
    scanf("%d",&n);
    
    int array[n];
    printf("\nEnter %d elements  :",n);

    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    int first,second;
        if(array[0]>array[1])
        {
        first=array[0];
        second=array[1];  
        }
        else{
            first=array[1];
            second=array[0];  
        }
        for(int i=2;i<n;i++){
        if(array[i]>first)
        {      
            second=first;
            first=array[i];
        }
        else if(array[i]>second && array[i]<first){
            second=array[i];
        }

        }
    printf("\nSecond largest element in the array is %d",second);
  return 0;
}

