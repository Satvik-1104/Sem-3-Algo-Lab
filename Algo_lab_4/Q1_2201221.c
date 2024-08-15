#include <stdio.h>

int peakElement(int n, int a[], int start, int end)
{
    if (start == end)
    {
        return a[start];
    }
    else
    {
        int mid = start + ((end - start) / 2);
        if (mid == 0)
        {
            if (a[mid + 1] <= a[mid])
            return a[mid];
        }
        else if (mid == (n - 1))
        {
            if (a[mid - 1] <= a[mid])
            return a[mid];
        }
        else
        {
            if ((a[mid] >= a[mid + 1]) && (a[mid] > a[mid - 1]))
            {
                return a[mid];
            }
        }
        int p1 = peakElement(n, a, start, mid);
        int p2 = peakElement(n, a, mid + 1, end);
        return (p1 > p2) ? p1 : p2;
    }
}

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The given array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int peak = peakElement(n, a, 0, n - 1);
    printf("%d is the max peak element.", peak);
}