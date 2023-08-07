#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int path[MAX_VERTICES];
bool visited[MAX_VERTICES];
int numVertices;
bool isSafe(int v, int pos) {
    if (!graph[path[pos - 1]][v]) 
	{
        return false;
    }

    if (visited[v]) 
	{
        return false; 
    }

    return true;
}
bool hamiltonianCircuitUtil(int pos) 
{
    if (pos == numVertices) 
	{
        if (graph[path[pos - 1]][path[0]]) 
		{
            return true; 
        }
        return false;
    }

    for (int v = 1; v < numVertices; v++) 
	{
        if (isSafe(v, pos)) 
		{
            path[pos] = v;
            visited[v] = true;

            if (hamiltonianCircuitUtil(pos + 1)) 
			{
                return true;
            }

            path[pos] = -1;
            visited[v] = false;
        }
    }

    return false;
}
void findHamiltonianCircuit() 
{
    path[0] = 0; 
    visited[0] = true;

    if (hamiltonianCircuitUtil(1)) 
	{
        printf("Hamiltonian Circuit: ");
        for (int i = 0; i < numVertices; i++) 
		{
            printf("%d ", path[i]);
        }
        printf("%d\n", path[0]); 
    } else 
	{
        printf("No Hamiltonian Circuit exists for the given graph.\n");
    }
}

int main() 
{
    printf("Enter the number of vertices (maximum %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);

    if (numVertices <= 0 || numVertices > MAX_VERTICES) 
	{
        printf("Invalid input. Please enter a positive integer less than or equal to %d.\n", MAX_VERTICES);
        return 1;
    }

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < numVertices; i++) 
	{
        for (int j = 0; j < numVertices; j++) 
		{
            scanf("%d", &graph[i][j]);
        }
    }

    findHamiltonianCircuit();

    return 0;
}

