#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int funRecursive(int *a, int s, int e, int **dp, int n) {
    if (dp[s][e] != -1) return dp[s][e];
    if (s == e || e - s == 1) return 0;
    int mini = INT_MAX;
    for (int k = s + 1; k < e; k++) {
        int left = funRecursive(a, s, k, dp, n);
        int right = funRecursive(a, k, e, dp, n);
        int combine = a[s] * a[k] * a[e];
        int ans = left + right + combine;
        if (mini > ans) mini = ans;
    }
    return dp[s][e] = mini;
}

int fun2Iterative(int *a, int n) {
    int **dp = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        dp[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    int min2 = INT_MAX;
    for (int s = n - 3; s >= 0; s--) {
        for (int e = s + 2; e < n; e++) {
            int min1 = INT_MAX;
            for (int k = s + 1; k < e; k++) {
                int left = dp[s][k];
                int right = dp[k][e];
                int combo = a[s] * a[k] * a[e];
                int res = left + right + combo;
                if (min1 > res) min1 = res;
            }
            dp[s][e] = min1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf ("\n");
    }

    int result = dp[0][n - 1];

    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int matrixMultiplication(int *arr, int N) {
    int **dp = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        dp[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    int result = fun2Iterative(arr, N);

    for (int i = 0; i < N; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    int N;
    scanf("%d", &N);
    int *a = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    printf("ans:%d\n", matrixMultiplication(a, N));

    free(a);

    return 0;
}
