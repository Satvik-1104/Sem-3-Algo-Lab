#include <stdio.h>

void merge(int n, int a[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[n];
    while ((i <= mid) && (j <= ub))
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    if (j > ub)
    {
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for (int p = lb; p <= ub; p++)
    {
        a[p] = b[p];
    }
}

void merge_sort(int n, int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int part1 = lb + ((ub - lb) / 4);
        int part2 = lb + ((ub - lb) / 2);
        int part3 = lb + ((ub - lb) * 3 / 4);
        merge_sort(n, a, lb, part1);
        merge_sort(n, a, part1 + 1, part2);
        merge_sort(n, a, part2 + 1, part3);
        merge_sort(n, a, part3 + 1, ub);
        merge(n, a, lb, part1, part2);
        merge(n, a, part2 + 1, part3, ub);
    }
}

int main()
{
    int n;
    printf("enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("the given array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    merge_sort(n, a, 0, n-1);
    printf("sorted array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}