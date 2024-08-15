#include <stdio.h>

int ternary_search(int n, int a[], int v)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m1 = l + (1 * (r - l)) / 3;
        int m2 = l + (2 * (r - l)) / 3;
        if (a[m1] == v)
        return m1;
        else if (a[m2] == v)
        return m2;
        else if (a[m1] < v && a[m2] > v)
        {
            l = m1 + 1;
            r = m2 - 1;
        }
        else if(a[m1] < v && a[m2] < v)
        {
            l = m2 + 1;
        }
        else if(a[m1] > v && a[m2] > v)
        {
            r = m1 - 1;
        }
    }
    return -1;
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
    int v;
    printf("Enter the value to be searched for: ");
    scanf("%d", &v);
    printf("The given array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int f = ternary_search(n, a, v);
    if (f == -1)
    {
        printf("Element not found (binary search).\n");
    }
    else
    {
        printf("The element is at index %d or position %d (binary search).\n", f, f + 1);
    }
}