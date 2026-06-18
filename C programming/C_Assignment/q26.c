/*Write a C program that rearranges an array such that all negative numbers
appear before all positive numbers while preserving the relative order of both
groups.
Description: The program should prompt the user to enter the size of the array and its
elements (a mix of positive and negative integers). It must then rearrange the elements
so that all negative numbers come first, followed by all positive numbers, without
changing the order in which the negatives appear among themselves or the positives
among themselves. Zero can be treated as positive. The rearranged array should be
displayed on the screen.
Pre-requisites: Arrays, Loops, Temporary Storage, Order Preservation Logic.*/

#include <stdio.h>

int main()
{
    int arr[100], temp[100];
    int n, i, k = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // store all negative numbers
    for (i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            temp[k] = arr[i];
            k++;
        }
    }

    //  store all zero and positive numbers
    for (i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            temp[k] = arr[i];
            k++;
        }
    }

    // Print rearranged array
    printf("Rearranged array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", temp[i]);
    }

    return 0;
}