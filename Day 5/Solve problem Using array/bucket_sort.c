#include <stdio.h>
#include <stdlib.h>

// Function to sort the buckets using insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to implement Bucket Sort
void bucketSort(int arr[], int n) {
    int max = arr[0], min = arr[0];

    // Find the maximum and minimum values in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int bucket_count = 10;  // Number of buckets
    int range = (max - min + 1);  // Range of values
    int bucket_size = (range + bucket_count - 1) / bucket_count;  // Size of each bucket

    // Allocate buckets and their sizes
    int buckets[bucket_count][n];
    int bucket_sizes[bucket_count];

    // Initialize bucket sizes
    for (int i = 0; i < bucket_count; i++) {
        bucket_sizes[i] = 0;
    }

    // Distribute the array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] - min) / bucket_size;
        buckets[bucket_index][bucket_sizes[bucket_index]++] = arr[i];
    }

    // Sort each bucket and concatenate the results
    int index = 0;
    for (int i = 0; i < bucket_count; i++) {
        insertionSort(buckets[i], bucket_sizes[i]);
        for (int j = 0; j < bucket_sizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {42, 32, 23, 52, 37, 47, 51};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
