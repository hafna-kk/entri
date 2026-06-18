/*Write a C program that merges two sorted arrays into a single sorted array
without using any sorting function.
Description: The program should prompt the user to enter the sizes and elements of
two arrays, each already sorted in ascending order. It must then merge them into a
third array by comparing elements from both arrays one by one and placing the
smaller element first, continuing until all elements are placed. The final merged sorted
array should be displayed on the screen.
Pre-requisites: Arrays, Loops, Multiple Array Handling.*/

#include <stdio.h>

int main()
{
    int a[100], b[100], c[200];
    int n1, n2, i = 0, j = 0, k = 0;

    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter elements of first array :\n");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter elements of second array :\n");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &b[i]);
    }

    i = 0;
    j = 0;
    k = 0;

    // Merge both arrays
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    // take remaining elements of first array
    while (i < n1)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    // take remaining elements of second array
    while (j < n2)
    {
        c[k] = b[j];
        j++;
        k++;
    }

    printf("Final Sorted Array:\n");
    for (i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}