#include <stdio.h>

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot's index
int partition(int arr[], int left, int right, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[right]); // Move pivot to the end
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(&arr[i], &arr[storeIndex]);
            storeIndex++;
        }
    }

    swap(&arr[right], &arr[storeIndex]); // Move pivot to its final place
    return storeIndex;
}

// Function to find the kth smallest element using the Median of Medians algorithm
int medianOfMedians(int arr[], int left, int right, int k) {
    if (left == right)
        return arr[left];

    int numElements = right - left + 1;
    int numGroups = (numElements + 4) / 5; // Number of groups of size 5 or less

    int medians[numGroups]; // Array to store medians of groups

    // Divide the array into groups, find the median of each group, and store it
    for (int i = 0; i < numGroups; i++) {
        int groupLeft = left + i * 5;
        int groupRight = groupLeft + 4;
        if (groupRight > right)
            groupRight = right;

        int groupSize = groupRight - groupLeft + 1;

        // Sort the group and find its median
        for (int j = groupLeft; j <= groupRight; j++) {
            for (int k = j + 1; k <= groupRight; k++) {
                if (arr[j] > arr[k])
                    swap(&arr[j], &arr[k]);
            }
        }

        // Find the median of the group
        medians[i] = arr[groupLeft + groupSize / 2];
    }

    // Find the median of medians (the pivot)
    int pivotIndex = medianOfMedians(medians, 0, numGroups - 1, numGroups / 2);

    // Partition the array around the pivot
    int partitionIndex = partition(arr, left, right, pivotIndex);

    if (k == partitionIndex)
        return arr[partitionIndex];
    else if (k < partitionIndex)
        return medianOfMedians(arr, left, partitionIndex - 1, k);
    else
        return medianOfMedians(arr, partitionIndex + 1, right, k);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k = (n - 1) / 2; // Calculate the index for the median
    int median = medianOfMedians(arr, 0, n - 1, k);

    printf("The median is: %d\n", median);

    return 0;
}
