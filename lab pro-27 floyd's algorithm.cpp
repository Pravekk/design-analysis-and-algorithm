#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int n;
void floydWarshall() 
{
    int dist[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
		{
            dist[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < n; k++) 
	{
        for (int i = 0; i < n; i++) 
		{
            for (int j = 0; j < n; j++) 
			{
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) 
				{
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("Shortest paths between all pairs of vertices:\n");
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
		{
            if (dist[i][j] == INT_MAX) 
			{
                printf("INF\t");
            } else 
			{
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() 
{
    printf("Enter the number of vertices (1 to %d): ", MAX_VERTICES);
    scanf("%d", &n);

    printf("Enter the adjacency matrix for the graph (use 'INF' for no edge):\n");
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
		{
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1) 
			{
                graph[i][j] = INT_MAX; 
            }
        }
    }

    floydWarshall();

    return 0;
}

