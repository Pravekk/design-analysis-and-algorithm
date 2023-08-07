#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 20

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;
int colors[MAX_VERTICES];
bool isSafe(int vertex, int color, int colorAssignment[]) 
{
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && colorAssignment[i] == color) 
		{
            return false;
        }
    }
    return true;
}
bool graphColoringBacktrack(int vertex, int numColors, int colorAssignment[]) 
{
    if (vertex == numVertices) 
	{
        printf("Vertex coloring: ");
        for (int i = 0; i < numVertices; i++) 
		{
            printf("%d ", colorAssignment[i]);
        }
        printf("\n");
        return true;
    }

    for (int color = 1; color <= numColors; color++) 
	{
        if (isSafe(vertex, color, colorAssignment)) 
		{
            colorAssignment[vertex] = color;

            if (graphColoringBacktrack(vertex + 1, numColors, colorAssignment)) 
			{
                return true;
            }

            colorAssignment[vertex] = 0; 
        }
    }
    return false;
}

int main() 
{
    int numEdges, vertex1, vertex2, numColors;
    int colorAssignment[MAX_VERTICES] = {0};

    printf("Enter the number of vertices (maximum %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (vertex1 vertex2):\n");
    for (int i = 0; i < numEdges; i++) 
	{
        scanf("%d %d", &vertex1, &vertex2);
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1;
    }

    printf("Enter the number of colors: ");
    scanf("%d", &numColors);

    if (graphColoringBacktrack(0, numColors, colorAssignment)) 
	{
        printf("Graph can be colored using %d colors.\n", numColors);
    } else 
	{
        printf("Graph cannot be colored using %d colors.\n", numColors);
    }

    return 0;
}

