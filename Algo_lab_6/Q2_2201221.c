#include <stdio.h>
#include <limits.h>

int matrixChainMultiplication(int p[], int i, int j, int *countSubproblems) {
    if (i == j) {
        return 0; 
    }

    int minCost = INT_MAX;
    (*countSubproblems)++;

    for (int k = i; k < j; k++) {
        int cost = matrixChainMultiplication(p, i, k, countSubproblems) +
                   matrixChainMultiplication(p, k + 1, j, countSubproblems) +
                   p[i - 1] * p[k] * p[j];

        if (cost < minCost) {
            minCost = cost;
        }
    }

    return minCost;
}

int main() {
    int n;
    printf("Enter the number of matrices (n): ");
    scanf("%d", &n);

    int p[n + 1];
    printf("Enter the matrix sizes (p[0] to p[n]): ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    int countSubproblems = 0;
    int minCost = matrixChainMultiplication(p, 1, n, &countSubproblems);

    printf("Minimum cost to multiply matrices: %d\n", minCost);
    printf("Total number of subproblems: %d\n", countSubproblems);

    return 0;
}
