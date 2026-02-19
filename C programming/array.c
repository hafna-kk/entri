#include<stdio.h>
/*

int main(){

// Initialize an array
int arr[]={2,3,3,453,567,9};

// Find the size of the array
int n=sizeof(arr)/sizeof(arr[0]);

// Intialize the variable which will denote the  maximum element
int maxval=arr[0];

//Find the maximum value in the array and store it in maxval

for(int i=0;i<n;i++){
   if(maxval<arr[i]){
    maxval=arr[i];
    }
 }
// print the elements of the array
  printf("Array Elements: ");
 for(int i=0;i<n;i++){
 printf("%d ",arr[i]);
 }
  printf("\nmaximum value:%d ",maxval);
return 0;
  }
*/

//C Program to Calculate Sum of Array Elements.
/*
int getsum(int arr[] ,int n){
int sum=0;
  for(int i=0;i<n;i++){
     sum +=arr[i];
    
  }
   return sum;
}

int main(){
int arr[]={3,4,5};
int n=sizeof(arr)/sizeof(arr[0]);
int result=getsum(arr , n);
printf("sum=%d",result);
return 0;
}
*/
//Reverse Array in C

/*
void rev(int arr[] ,int n){
  int temp[n];
 
for (int i=0;i<n;i++){
temp[i]=arr[n-1-i];
}
for (int i=0;i<n;i++){
arr[i]=temp[i];
}
}
int main(){
int arr[]={4,3,2,1};
int n=sizeof(arr)/sizeof(arr[0]);
rev(arr,n);
for (int i=0;i<n;i++){
printf("%d",arr[i]);
}
return 0;
}

*/

//Print all elements of an array
/*
int main(){

  int arr[]={2,3,4,5,22,6,47};
  int n=sizeof(arr)/sizeof(arr[0]);
  printf("Array elements :");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  return 0;
}
*/

//Find sum and average of an array

/*
int main(){

  int arr[]={2,3,4,5,6};
  int n=sizeof(arr)/sizeof(arr[0]);
  int sum=0;
 
  for(int i=0;i<n;i++){
    sum+=arr[i];
    
  }
  printf("Sum = %d",sum);
 
   float average=(float)sum/n;
    printf("\nAverage = %0.1f",average);
  return 0;
}

*/
//Find max and min of an array

/*
int main(){
  int arr[5];
  
  int n=sizeof(arr)/sizeof(arr[0]);
   printf("enter array elements: ");
  for(int i=0;i<n;i++){
  scanf("%d",&arr[i]);
}
int max=arr[0];
  int min=arr[0];
  for(int i=1;i<n;i++){
  if(arr[i]>=max){
  max=arr[i];
  }
  if(arr[i]<=min){
  min=arr[i];
  }
  
}
 
printf(" max = %d",max);
printf(" min = %d",min);
  return 0;
}
  */

//Reverse array (without extra array)
/*
int main(){

    int arr[5];
    int n=sizeof(arr)/sizeof(arr[0]);
    int temp,start=0,end=n-1;
    printf("enter array elements: ");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    printf("Array elements before reversing: ");
    for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
    }
    while(start<end){
      int temp=arr[start];
      arr[start]=arr[end];
      arr[end]=temp;
      start++;
      end--;

    }
   printf("Array elements after reversing: ");
    for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
    }
    return 0;
}
    */

//Find second largest element in array.
/*
#include <limits.h>
int main(){

 int arr[]={2,3,4,5,6};
 int n=sizeof(arr)/sizeof(arr[0]);
 printf("array elements:");
 for(int i=0;i<n;i++){
  printf("%d",arr[i]);
 }
 int max=arr[0];
 int sec=INT_MIN;
 for(int i=1;i<n;i++){
  if(arr[i]>max)
  max=arr[i];
 }
   for(int i=1;i<n;i++){
  if(arr[i]>sec && arr[i]!=max)
  sec=arr[i];
 }
 printf("\nSecond largest Element:%d",sec);
 return 0;
}
 */

 