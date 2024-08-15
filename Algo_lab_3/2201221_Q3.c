#include<stdio.h>
#include<limits.h>

int max (int a, int b, int c)
{
    int max_value = a;
    if (b > max_value) max_value = b;
    if (c > max_value) max_value = c;
    return max_value;
}

int Multiply (int a[],int start,int end)
{
    if(start == end)
        return a[start];
    int mid = (start + end) / 2;
    int x = Multiply (a, start, mid);
    int y = Multiply (a, mid + 1, end);
    int x1 = 1;
    int y1 = INT_MIN;
    for(int i = mid; i >= start; i--)
    {
        x1 = x1 * a[i];
        y1 = max(x1, y1, INT_MIN);
    }
    int x2 = 1;
    int y2 = INT_MIN;
    for(int i = mid + 1; i <= end; i++)
    {
        x2 = x2 * a[i];
        y2 = max(x2, y2, INT_MIN);
    }
    return max(x, y, y1*y2);
}

void main()
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
    int x = Multiply (a, 0, n - 1);
    printf("The maximum product is: %d",x);
}