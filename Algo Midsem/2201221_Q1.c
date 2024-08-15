#include <stdio.h>

void findK(int n, int A[n][n], int k) {
    int row = 0;
    int column = n-1;
    while (row < n && column >=0) {
        if (A[row][column] == k) {
            printf("%d found at row %d and column %d\n", k, row + 1, column + 1);
            return;
        }
        else if (A[row][column] > k) {
            column--;
        }
        else {
            row++;
        }
    }
    printf("%d is not present in A\n", k);
}

int main() {
    int m,n;
    printf("Enter no.of rows:");
    scanf("%d",&m);
    printf("Enter no.of columns:");
    scanf("%d",&n);
    printf("Enter the elements :");
    int a[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    int k;
    printf("enter the element you want to search: ");
    scanf("%d",&k);
    findK(m, a, k);
    return 0;
}

