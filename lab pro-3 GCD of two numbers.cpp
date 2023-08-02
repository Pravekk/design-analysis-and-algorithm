#include <stdio.h>

int gcd(int a, int b) 
{
    int temp;
    while (b != 0) 
	{
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() 
{
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);

    if (num1 < 0 || num2 < 0)  
	{
        printf("Please enter positive integers.\n");
        return 1;
    }

    int result = gcd(num1, num2);
    printf("The GCD of %d and %d is: %d\n", num1, num2, result);

    return 0;
}

