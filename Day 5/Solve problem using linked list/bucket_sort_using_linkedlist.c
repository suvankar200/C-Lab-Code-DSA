#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node with given data
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in a sorted order into a linked list
void sortedInsert(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL || (*head)->data >= data)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        struct Node *current = *head;
        while (current->next != NULL && current->next->data < data)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to concatenate all the buckets into the original array
void concatenateBuckets(struct Node **buckets, int bucket_count, int arr[], int n)
{
    int index = 0;
    for (int i = 0; i < bucket_count; i++)
    {
        struct Node *node = buckets[i];
        while (node != NULL)
        {
            arr[index++] = node->data;
            node = node->next;
        }
    }
}

// Function to implement bucket sort using linked lists
void bucketSort(int arr[], int n)
{
    int max = arr[0], min = arr[0];

    // Find the maximum and minimum values in the array
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int bucket_count = 10; // Number of buckets
    int range = (max - min + 1);
    int bucket_size = (range + bucket_count - 1) / bucket_count;

    // Create an array of linked lists for buckets
    struct Node *buckets[bucket_count];
    for (int i = 0; i < bucket_count; i++)
    {
        buckets[i] = NULL;
    }

    // Distribute array elements into buckets
    for (int i = 0; i < n; i++)
    {
        int bucket_index = (arr[i] - min) / bucket_size;
        sortedInsert(&buckets[bucket_index], arr[i]);
    }

    // Concatenate all buckets back to the array
    concatenateBuckets(buckets, bucket_count, arr, n);

    // Free the memory used for linked list nodes
    for (int i = 0; i < bucket_count; i++)
    {
        struct Node *current = buckets[i];
        while (current != NULL)
        {
            struct Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

// Function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {42, 32, 23, 52, 37, 47, 51};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
