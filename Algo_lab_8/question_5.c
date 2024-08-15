#include <stdio.h>

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int array[], int left, int right)
{
    
}

int medianOfMedians (int array[], int left, int right, int x)
{
    if (left == right)
    {
        return array[left];
    }

    int pivotIndex = partition(array, left, right);

    int numElements = pivotIndex - left - 1;

    if (x == numElements)
        return array[pivotIndex];
    
    else if (x < numElements)
        return medianOfMedians(array, left, pivotIndex - 1, x);

    else
        return medianOfMedians(array, pivotIndex + 1, right, x - numElements);
}

int main()
{
    int n;
    printf("Enter the number elements: ");
    scanf("%d", &n);
    int array[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("The given array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    int x = (n - 1) / 2;
    int median = medianOfMedians (array, 0, n - 1, x);

    printf("The median is: %d\n", median);

    return 0;
}