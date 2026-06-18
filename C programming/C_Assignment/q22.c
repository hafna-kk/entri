/*22.Write a C program that uses an array to find the second largest and second
smallest element in a list of numbers.
Description: The program should prompt the user to enter the size of the array and its
elements. It must then scan through the array and determine both the second largest
and second smallest values without sorting the array. The program should handle
duplicate values correctly — if all elements are the same, it should display an
appropriate message. Both results should be displayed on the screen.
Pre-requisites: Arrays, Loops, Conditional Statements.*/

#include <stdio.h>

int main()
{
    int arr[100];
    int n, i;

    int largest, secondLarge;
    int smallest, secondSmall;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Initialize with first element
    largest = smallest = arr[0];

    // Find largest and smallest first
    for (i = 1; i < n; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];

        if (arr[i] < smallest)
            smallest = arr[i];
    }

    // Initialize second values
    secondLarge = smallest;
    secondSmall = largest;

    // Find second largest and second smallest
    for (i = 0; i < n; i++)
    {
        // second largest
        if (arr[i] > secondLarge && arr[i] < largest)
        {
            secondLarge = arr[i];
        }

        // second smallest
        if (arr[i] < secondSmall && arr[i] > smallest)
        {
            secondSmall = arr[i];
        }
    }

    // Check for duplicates case
    if (largest == smallest)
    {
        printf("All elements are equal. No second largest or second smallest.\n");
    }
    else
    {
        printf("Second Largest = %d\n", secondLarge);
        printf("Second Smallest = %d\n", secondSmall);
    }

    return 0;
}