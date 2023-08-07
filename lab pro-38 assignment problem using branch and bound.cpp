#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 10

int n;
int costMatrix[MAX_N][MAX_N];
bool assigned[MAX_N];

int minCost = INT_MAX;
int currentCost = 0;
int findMinInRow(int row) 
{
    int minVal = INT_MAX;
    for (int j = 0; j < n; j++) 
	{
        if (!assigned[j] && costMatrix[row][j] < minVal) 
		{
            minVal = costMatrix[row][j];
        }
    }
    return minVal;
}
void reduceCostMatrix(int row, int col) 
{
    int minRow = findMinInRow(row);
    for (int j = 0; j < n; j++) 
	{
        costMatrix[row][j] -= minRow;
    }

    int minCol = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!assigned[i] && costMatrix[i][col] < minCol) 
		{
            minCol = costMatrix[i][col];
        }
    }
    for (int i = 0; i < n; i++) {
        costMatrix[i][col] -= minCol;
    }
}
void branchAndBound(int level) 
{
    if (level == n) 
	{
        if (currentCost < minCost) 
		{
            minCost = currentCost;
        }
        return;
    }

    for (int i = 0; i < n; i++) 
	{
        if (!assigned[i]) 
		{
            assigned[i] = true;
            currentCost += costMatrix[level][i];

            if (currentCost + (n - level - 1) * findMinInRow(level) < minCost) 
			{
                reduceCostMatrix(level, i);
                branchAndBound(level + 1);
                reduceCostMatrix(level, i);
            }

            assigned[i] = false;
            currentCost -= costMatrix[level][i];
        }
    }
}

int main() 
{
    printf("Enter the number of workers and tasks (max %d): ", MAX_N);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_N) 
	{
        printf("Invalid input. Please enter a positive integer less than or equal to %d.\n", MAX_N);
        return 1;
    }

    printf("Enter the cost matrix (row by row):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
		{
            scanf("%d", &costMatrix[i][j]);
        }
    }

    branchAndBound(0);

    printf("Minimum cost for assignment: %d\n", minCost);

    return 0;
}

