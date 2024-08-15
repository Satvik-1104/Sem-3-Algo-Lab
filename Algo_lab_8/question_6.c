#include <stdio.h>

int findingLargest(int a[], int left, int right){
    if (left == right)
        return a[left];
    else if (right - 1 == left)
        return (a[left] > a[right]) ? a[left] : a[right];
    else {
        int mid = (left + ((right - left) / 2));
        if (a[mid] > a[mid + 1])
            return a[mid];
        else if (a[mid] < a[left])
            return findingLargest(a, left, mid);
        else
            return findingLargest(a, mid + 1, right);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the rotated sorted array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("The given array is\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    int max = findingLargest (a, 0, n - 1);
    printf("%d is the largest element.\n", max);
}