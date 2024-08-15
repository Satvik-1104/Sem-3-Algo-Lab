#include <stdio.h>

int missingNumber(int n, int a[], int start, int end)
{
    if (start == end)
    {
        return a[start] + 1;
    }
    while (start < end)
    {
        int mid = start + ((end - start) / 2);
        if (a[mid] == a[start] + mid - start)
        {
            return missingNumber(n, a, mid + 1, end);
        }
        else
        {
            return missingNumber(n, a, start, mid - 1);
        }
    }
}

int main()
{
    int n;
    printf("enter the size of the array: ");
    scanf("%d", &n);
    printf("enter the elements of the array: ");
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The given elements of the array are\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int number = missingNumber(n, a, 0, n - 1);
    printf("The missing number is %d", number);
}