#include <stdio.h>
#include <limits.h>

int t = INT_MAX;

void minInteger(int i)
{
    if (t > i)
    {
        t = i;
    }
}

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
        if (p > q)
        {
            minInteger(q);
            return p;
        }
        else
        {
            minInteger(p);
            return q;
        }
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
    printf("%d is the maximum integer in the given array.\n", max);
    int min = t;
    printf("%d is the minimum integer in the given array.", min);
    return 0;
}