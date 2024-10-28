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

// Function to insert a node into the sorted part of the linked list
struct Node *sortedInsert(struct Node *sorted, struct Node *newNode)
{
    if (sorted == NULL || sorted->data >= newNode->data)
    {
        newNode->next = sorted;
        return newNode;
    }

    struct Node *current = sorted;
    while (current->next != NULL && current->next->data < newNode->data)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

    return sorted;
}

// Function to sort a linked list using insertion sort
struct Node *insertionSort(struct Node *head)
{
    struct Node *sorted = NULL; // Initialize sorted linked list

    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *next = current->next; // Save the next node
        sorted = sortedInsert(sorted, current);
        current = next;
    }

    return sorted;
}

// Function to print the linked list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to push a new node at the beginning of the linked list
void push(struct Node **head_ref, int new_data)
{
    struct Node *newNode = createNode(new_data);
    newNode->next = *head_ref;
    *head_ref = newNode;
}

int main()
{
    struct Node *head = NULL;

    // Creating the linked list
    int arr[] = {2, 6, 85, 25, 21, 36, 2, 54, 8, 9, 45, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        push(&head, arr[i]);
    }

    printf("Linked list before sorting:\n");
    printList(head);

    head = insertionSort(head);

    printf("Linked list after sorting:\n");
    printList(head);

    return 0;
}
