#include <stdio.h>

#define MAX_ROWS 10

int main() {
    int numRows;

    printf("Enter the number of rows for Pascal's triangle (1 to %d): ", MAX_ROWS);
    scanf("%d", &numRows);

    int pascalTriangle[MAX_ROWS][MAX_ROWS];

    // Calculate and print Pascal's triangle
    for (int i = 0; i < numRows; i++) {
        // Calculate each element of the row
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                pascalTriangle[i][j] = 1; // First and last elements of each row are 1
            } else {
                pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
            }
        }

        // Print each row
        for (int space = 0; space < numRows - i - 1; space++) {
            printf("  "); // Print spaces before each row
        }

        for (int j = 0; j <= i; j++) {
            printf("%4d", pascalTriangle[i][j]);
        }

        printf("\n");
    }

    return 0;
}

