#include <stdio.h>

void printMinMaxSequence(int arr[], int size) 
{
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) 
	{
        if (arr[i] < min) 
		{
            min = arr[i];
        }
        if (arr[i] > max) 
		{
            max = arr[i];
        }
        printf("Min: %d, Max: %d\n", min, max);
    }
}

int main() 
{
    int size;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &size);

    if (size <= 0) 
	{
        printf("Invalid size! Please enter a positive number greater than zero.\n");
        return 1;
    }

    int arr[size];
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < size; i++) 
	{
        scanf("%d", &arr[i]);
    }

    printf("Minimum and Maximum sequence for each number:\n");
    printMinMaxSequence(arr, size);

    return 0;
}

