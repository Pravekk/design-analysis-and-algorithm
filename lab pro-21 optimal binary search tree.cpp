#include <stdio.h>
#include <limits.h>

#define MAX_KEYS 10
int sumOfFrequencies(int freq[], int i, int j) 
{
    int sum = 0;
    for (int k = i; k <= j; k++) 
	{
        sum += freq[k];
    }
    return sum;
}
int optimalBST(int keys[], int freq[], int n) 
{
    int cost[MAX_KEYS][MAX_KEYS]; 
    for (int i = 0; i < n; i++) 
	{
        cost[i][i] = freq[i]; 
    }

    for (int L = 2; L <= n; L++) 
	{
        for (int i = 0; i <= n - L + 1; i++) 
		{
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) 
			{
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sumOfFrequencies(freq, i, j);
                if (c < cost[i][j]) 
				{
                    cost[i][j] = c;
                }
            }
        }
    }

    return cost[0][n - 1];
}

int main() 
{
    int n, keys[MAX_KEYS], freq[MAX_KEYS];

    printf("Enter the number of keys (1 to %d): ", MAX_KEYS);
    scanf("%d", &n);

    printf("Enter the keys (in sorted order): ");
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &keys[i]);
    }

    printf("Enter the frequencies of keys: ");
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &freq[i]);
    }

    int optimalCost = optimalBST(keys, freq, n);
    printf("Optimal cost of binary search tree: %d\n", optimalCost);

    return 0;
}

