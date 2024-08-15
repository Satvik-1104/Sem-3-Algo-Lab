#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of sorted array: ");
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
    int x = a[0];
    int y = a[n - 1];
    int min, max;
    if (x < y)
    {
        min = x;
        max = y;
    }
    else if (x > y)
    {
        min = y;
        max = x;
    }
    else
    {
        printf("All the elements in the array are equal.\n");
        min = max = x; 
    }
    printf("the minimum element is %d\n", min);
    printf("the mmaximum element is %d", max);
}