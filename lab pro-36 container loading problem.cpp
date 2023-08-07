#include <stdio.h>

#define MAX_CONTAINERS 100
#define MAX_ITEMS 100
int containerLoading(int containers[], int numContainers, int items[], int numItems) 
{
    int containerWeights[MAX_CONTAINERS] = {0};
    int containerCount = 0;
    for (int i = 0; i < numItems - 1; i++) 
	{
        for (int j = 0; j < numItems - i - 1; j++) 
		{
            if (items[j] < items[j + 1]) 
			{
                int temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < numItems; i++) 
	{
        int currentItem = items[i];
        int packed = 0;

        for (int j = 0; j < containerCount; j++) 
		{
            if (containerWeights[j] + currentItem <= containers[j]) 
			{
                containerWeights[j] += currentItem;
                packed = 1;
                break;
            }
        }

        if (!packed) 
		{
            containerWeights[containerCount] = currentItem;
            containerCount++;
        }
    }

    return containerCount;
}

int main() 
{
    int containers[MAX_CONTAINERS];
    int items[MAX_ITEMS];
    int numContainers, numItems;

    printf("Enter the number of containers: ");
    scanf("%d", &numContainers);

    printf("Enter the capacities of the containers:\n");
    for (int i = 0; i < numContainers; i++) 
	{
        scanf("%d", &containers[i]);
    }

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    printf("Enter the sizes of the items:\n");
    for (int i = 0; i < numItems; i++) 
	{
        scanf("%d", &items[i]);
    }

    int containerCount = containerLoading(containers, numContainers, items, numItems);
    printf("Minimum number of containers required: %d\n", containerCount);

    return 0;
}

