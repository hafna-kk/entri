/*21.Write a C program to remove duplicate elements from a given array.
Description: The program should prompt the user to enter the size of the array and its
elements. It must then identify and remove any duplicate values, ensuring that each
element appears only once in the resulting array. The program should finally display
the updated array containing only unique elements.
Pre-requisites: Arrays, Loops, Conditional Statements*/

#include <stdio.h>

int main()
{
    int arr[100], unique[100];
    int n, i, j, k = 0;
    int isDuplicate;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Check each element
    for (i = 0; i < n; i++)
    {
        isDuplicate = 0;

        // Compare with already stored unique elements
        for (j = 0; j < k; j++)
        {
            if (arr[i] == unique[j])
            {
                isDuplicate = 1;
                break;
            }
        }

        // Store only if not duplicate
        if (!isDuplicate)
        {
            unique[k] = arr[i];
            k++;
        }
    }

    printf("Updated array: ");
    for (i = 0; i < k; i++)
    {
        printf("%d ", unique[i]);
    }

    return 0;
}