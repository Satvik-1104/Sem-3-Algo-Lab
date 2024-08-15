#include <stdio.h>

int binary_search(int n, int a[], int v)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = l + (1 * (r-l)) / 2;
        if (a[mid] == v)
        return mid;
        else if (a[mid] > v)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int alpha_search(int n, int a[], int v)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = l + (1* (r - l))/3;
        if (a[mid] == v)
        return mid;
        else if (a[mid] > v)
        r = mid - 1;
        else
        l = mid + 1;
    }
    return -1;
}

int beta_search(int n, int a[], int v)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = l + (3 * (r - l))/4;
        if (a[mid] == v)
        return mid;
        else if (a[mid] > v)
        r = mid - 1;
        else
        l = mid + 1;
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
    int f_bin_s = binary_search(n, a, v);
    if (f_bin_s == -1)
    {
        printf("Element not found (binary search).\n");
    }
    else
    {
        printf("The element is at index %d or position %d (binary search).\n", f_bin_s, f_bin_s + 1);
    }
    int f_alpha_s = alpha_search(n, a, v);
    if (f_alpha_s == -1)
    {
        printf("Element not found (alpha search).\n");
    }
    else
    {
        printf("The element is at index %d or position %d (alpha search).\n", f_alpha_s, f_alpha_s + 1);
    }
    int f_beta_s = beta_search(n, a, v);
    if (f_beta_s == -1)
    {
        printf("Element not found (beta search).\n");
    }
    else
    {
        printf("The element is at index %d or position %d (beta search).\n", f_beta_s, f_beta_s + 1);
    }   
}