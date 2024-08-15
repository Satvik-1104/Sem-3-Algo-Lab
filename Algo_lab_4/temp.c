#include <stdio.h>

int findPeakElement(int arr[], int left, int right) {
    if (left == right) {
        return left;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] > arr[mid + 1]) {
        // The peak must be in the left half
        return findPeakElement(arr, left, mid);
    } else {
        // The peak must be in the right half
        return findPeakElement(arr, mid + 1, right);
    }
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int peakIndex = findPeakElement(arr, 0, n - 1);
    int peakElement = arr[peakIndex];

    printf("Peak Element: %d at index %d\n", peakElement, peakIndex);

    return 0;
}
