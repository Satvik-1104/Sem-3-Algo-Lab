#include <stdio.h>

int checkFreq(int n, int a[], int start, int end)
{
    if (start == end)
    {
        return a[start];
    }
    
        int mid = start + ((end - start) / 2);
        int leftMajority = checkFreq(n, a, start, mid);
        int rightMajority = checkFreq(n, a, mid + 1, end);
        if (leftMajority == rightMajority)
        {
            return leftMajority;
        }
        int leftCount = 0, rightCount = 0;
        for (int i = start; i <= end; i++)
        {
            if (a[i] == leftMajority)
            {
                leftCount++;
            }
            else if (a[i] == rightMajority)
            {
                rightCount++;
            }
        }
        if (leftCount > (end - start + 1) / 2)
        {
            return leftMajority;
        }
        else if (rightCount > (end - start + 1) / 2)
        {
            return rightMajority;
        }
        return -1;
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
    int majorityElement = checkFreq(n, a, 0, n - 1);
    if (majorityElement != -1)
    {
        printf("%d is the majority element.\n", majorityElement);
    }
    else
    {
        printf("No majority element found.\n");
    }
    return 0;
}