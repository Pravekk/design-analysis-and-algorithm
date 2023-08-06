#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define MAX_EDGES 45

typedef struct 
{
    int startVertex;
    int endVertex;
    int weight;
} Edge;

int parent[MAX_VERTICES];
void initializeParent(int n) 
{
    for (int i = 0; i < n; i++) 
	{
        parent[i] = i;
    }
}
int findParent(int vertex) 
{
    if (parent[vertex] != vertex) 
	{
        parent[vertex] = findParent(parent[vertex]);
    }
    return parent[vertex];
}
void unionSets(int x, int y) 
{
    int parentX = findParent(x);
    int parentY = findParent(y);
    parent[parentX] = parentY;
}
int compareEdges(const void* a, const void* b) 
{
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}
void kruskalMST(int n, int m, Edge edges[MAX_EDGES]) 
{
    initializeParent(n);
    int numEdges = 0;
    int totalWeight = 0;
    Edge MST[MAX_EDGES];
    qsort(edges, m, sizeof(Edge), compareEdges);

    for (int i = 0; i < m && numEdges < n - 1; i++) 
	{
        int startVertex = edges[i].startVertex;
        int endVertex = edges[i].endVertex;
        if (findParent(startVertex) != findParent(endVertex)) 
		{
            MST[numEdges++] = edges[i];
            totalWeight += edges[i].weight;
            unionSets(startVertex, endVertex);
        }
    }

    if (numEdges != n - 1) 
	{
        printf("Graph is not connected, no MST exists.\n");
    } else {
        printf("Minimum Spanning Tree:\n");
        for (int i = 0; i < n - 1; i++) 
		{
            printf("(%d, %d) -> %d\n", MST[i].startVertex, MST[i].endVertex, MST[i].weight);
        }
        printf("Total weight of MST: %d\n", totalWeight);
    }
}

int main() 
{
    int n, m;
    Edge edges[MAX_EDGES];

    printf("Enter the number of vertices (1 to %d): ", MAX_VERTICES);
    scanf("%d", &n);

    if (n < 1 || n > MAX_VERTICES) 
	{
        printf("Invalid number of vertices. Please enter a number between 1 and %d.\n", MAX_VERTICES);
        return 1;
    }

    printf("Enter the number of edges (0 to %d): ", MAX_EDGES);
    scanf("%d", &m);

    if (m < 0 || m > MAX_EDGES) 
	{
        printf("Invalid number of edges. Please enter a number between 0 and %d.\n", MAX_EDGES);
        return 1;
    }

    printf("Enter the edges and their weights (startVertex endVertex weight):\n");
    for (int i = 0; i < m; i++) 
	{
        scanf("%d %d %d", &edges[i].startVertex, &edges[i].endVertex, &edges[i].weight);
    }

    kruskalMST(n, m, edges);

    return 0;
}

