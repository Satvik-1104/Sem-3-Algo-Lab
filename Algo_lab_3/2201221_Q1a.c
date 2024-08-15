#include <stdio.h>

int maxInteger(int n, int a[], int start, int end)
{
    if (start == end)
    {
        return a[start];
    }
    while (start < end)
    {
        int mid = start + ((end - start) / 2);
        int p = maxInteger(n, a, start, mid);
        int q = maxInteger(n, a, mid + 1, end);
        int max = (p > q) ? p : q;
        return max;
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The given array is\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int max = maxInteger(n, a, 0, n - 1);
    printf("%d is the maximum integer in the given array.", max);
}