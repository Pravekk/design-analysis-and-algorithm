#include <stdio.h>

void printAllFactors(int n) 
{
    printf("Factors of %d: ", n);

    for (int i = 1; i <= n; i++) 
	{
        if (n % i == 0) 
		{
            printf("%d ", i);
        }
    }

    printf("\n");
}

int main() 
{
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n <= 0) 
	{
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    printAllFactors(n);

    return 0;
}

