#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int n; 
int graph[MAX_CITIES][MAX_CITIES]; 
int memo[MAX_CITIES][1 << MAX_CITIES]; 
int min(int a, int b) 
{
    return (a < b) ? a : b;
}
int tsp(int mask, int pos) 
{
    if (mask == (1 << n) - 1) 
	{
        return graph[pos][0];
    }

    if (memo[pos][mask] != -1) 
	{
        return memo[pos][mask];
    }

    int minCost = INT_MAX;

    for (int city = 0; city < n; city++) 
	{
        if (!(mask & (1 << city)) && graph[pos][city] != 0) 
		{
            int newMask = mask | (1 << city);
            int newCost = graph[pos][city] + tsp(newMask, city);
            minCost = min(minCost, newCost);
        }
    }

    return memo[pos][mask] = minCost;
}

int main() 
{
    printf("Enter the number of cities (1 to %d): ", MAX_CITIES);
    scanf("%d", &n);

    printf("Enter the distance matrix for %d cities:\n", n);
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
		{
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = 0; i < MAX_CITIES; i++) 
	{
        for (int j = 0; j < (1 << MAX_CITIES); j++) 
		{
            memo[i][j] = -1;
        }
    }

    int startingCity = 0; 
    int mask = 1 << startingCity;

    int optimalCost = tsp(mask, startingCity);

    printf("Optimal cost of the TSP: %d\n", optimalCost);

    return 0;
}

