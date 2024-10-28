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

// Function to split the linked list into two halves
void splitList(struct Node *source, struct Node **front, struct Node **back)
{
    struct Node *slow = source;
    struct Node *fast = source->next;

    // Move `fast` two nodes, and `slow` one node at a time
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // `slow` is at the midpoint in the list, so split it into two halves
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

// Function to merge two sorted linked lists
struct Node *sortedMerge(struct Node *a, struct Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    struct Node *result = NULL;

    // Pick either `a` or `b`, and recursively sort the merged list
    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

// Function to implement merge sort on a linked list
void mergeSort(struct Node **head_ref)
{
    struct Node *head = *head_ref;
    struct Node *a;
    struct Node *b;

    // Base case: if the list is empty or has only one element
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

    // Split the list into two halves
    splitList(head, &a, &b);

    // Recursively sort the two halves
    mergeSort(&a);
    mergeSort(&b);

    // Merge the sorted halves
    *head_ref = sortedMerge(a, b);
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
    int arr[] = {2, 65, 8, 25, 75, 26, 35, 75};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        push(&head, arr[i]);
    }

    printf("Linked list before sorting:\n");
    printList(head);

    // Sorting the linked list
    mergeSort(&head);

    printf("Linked list after sorting:\n");
    printList(head);

    return 0;
}
