/*23.Write a C program that rotates the elements of an array by n positions in a
specified direction.
Description: The program should prompt the user to enter the array elements, the
number of positions (n) to rotate, and the direction (left or right). It must then shift the
elements accordingly — elements that fall off one end should reappear at the opposite
end. The rotation must work for any value of n, including values larger than the array
size. The final rotated array should be displayed on the screen.
Pre-requisites: Arrays, Loops, Modulus Operator.*/

#include <stdio.h>

int main()
{
    int arr[100], temp[100];
    int n, size, i, d;

    printf("Enter array size: ");
    scanf("%d", &size);
    printf("Enter array elements:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter number of positions to rotate: ");
    scanf("%d", &n);
    printf("Enter direction (1 = Left, 2 = Right): ");
    scanf("%d", &d);

    // for handle n > size
    n = n % size;

    // Left rotation
    if (d == 1)
    {
        for (i = 0; i < size; i++)
        {
            temp[i] = arr[(i + n) % size];
        }
    }
    // Right rotation
    else if (d == 2)
    {
        for (i = 0; i < size; i++)
        {
            temp[(i + n) % size] = arr[i];
        }
    }
    else
    {
        printf("Invalid direction\n");
        return 0;
    }

    printf("final array:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", temp[i]);
    }

    return 0;
}