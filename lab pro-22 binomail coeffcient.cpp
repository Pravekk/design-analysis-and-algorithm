#include <stdio.h>

#define MAX_N 20
unsigned long long binomialCoefficient(int n, int k) 
{
    unsigned long long dp[MAX_N][MAX_N];
    for (int i = 0; i <= n; i++) 
	{
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) 
	{
        for (int j = 1; j <= k; j++) 
		{
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}

int main() 
{
    int n, k;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (n < 0 || k < 0 || k > n) 
	{
        printf("Invalid input. Please enter non-negative values for n and k, and ensure k <= n.\n");
        return 1;
    }

    unsigned long long coefficient = binomialCoefficient(n, k);
    printf("Binomial Coefficient C(%d, %d) = %llu\n", n, k, coefficient);

    return 0;
}

