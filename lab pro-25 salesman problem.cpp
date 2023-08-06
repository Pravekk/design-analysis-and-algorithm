#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int n;
int graph[MAX_CITIES][MAX_CITIES];
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

    return minCost;
}

int main() 
{
    printf("Enter the number of cities (1 to %d): ", MAX_CITIES);
    scanf("%d", &n);

    printf("Enter the distance matrix for %d cities (0 for self-loop, -1 if no direct edge):\n", n);
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
		{
            scanf("%d", &graph[i][j]);
        }
    }

    int startingCity = 0; 
    int mask = 1 << startingCity;

    int minCost = tsp(mask, startingCity);

    printf("Minimum cost of the TSP: %d\n", minCost);

    return 0;
}

