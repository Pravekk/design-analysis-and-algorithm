#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function to find subsets with the given sum using backtracking
void subsetSumBacktrack(int set[], int size, int targetSum, int currentSum, int startIdx, bool selected[]) {
    if (currentSum == targetSum) {
        printf("Subset with the sum %d: ", targetSum);
        for (int i = 0; i < size; i++) {
            if (selected[i]) {
                printf("%d ", set[i]);
            }
        }
        printf("\n");
        return;
    }

    if (currentSum > targetSum || startIdx == size) {
        return;
    }

    // Include the current element in the subset
    selected[startIdx] = true;
    subsetSumBacktrack(set, size, targetSum, currentSum + set[startIdx], startIdx + 1, selected);

    // Exclude the current element from the subset
    selected[startIdx] = false;
    subsetSumBacktrack(set, size, targetSum, currentSum, startIdx + 1, selected);
}

int main() {
    int size, targetSum;
    int set[MAX_SIZE];
    bool selected[MAX_SIZE] = {false};

    printf("Enter the size of the set: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size! Please enter a positive number less than or equal to %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("Subsets with the sum %d:\n", targetSum);
    subsetSumBacktrack(set, size, targetSum, 0, 0, selected);

    return 0;
}

