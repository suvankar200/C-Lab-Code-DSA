#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
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

// Function to add a node at the end of the linked list
void appendNode(struct Node **head_ref, int new_data)
{
    struct Node *newNode = createNode(new_data);
    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        return;
    }
    struct Node *temp = *head_ref;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to partition the linked list
struct Node *partition(struct Node *low, struct Node *high)
{
    int pivot = high->data; // pivot is the last element's value
    struct Node *i = low;   // pointer for elements smaller than pivot
    struct Node *j = low;

    // Reorder nodes based on pivot
    while (j != high)
    {
        if (j->data < pivot)
        {
            int temp = i->data;
            i->data = j->data;
            j->data = temp;
            i = i->next;
        }
        j = j->next;
    }
    int temp = i->data;
    i->data = high->data;
    high->data = temp;
    return i; // Return pivot position
}

// QuickSort function for linked list
void quickSortRec(struct Node *low, struct Node *high)
{
    if (low != high && low != NULL && high != NULL)
    {
        struct Node *pivot = partition(low, high);
        quickSortRec(low, pivot);
        quickSortRec(pivot->next, high);
    }
}

// Function to get the last node of the list (for use in quicksort)
struct Node *getLastNode(struct Node *head)
{
    while (head != NULL && head->next != NULL)
    {
        head = head->next;
    }
    return head;
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

int main()
{
    struct Node *head = NULL;

    // Create a linked list
    int arr[] = {2, 5, 2, 7, 5, 3, 54, 34, 53, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        appendNode(&head, arr[i]);
    }

    printf("Original List:\n");
    printList(head);

    struct Node *last = getLastNode(head);
    quickSortRec(head, last);

    printf("Sorted List:\n");
    printList(head);

    return 0;
}
