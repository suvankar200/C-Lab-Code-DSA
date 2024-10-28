#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end of the linked list
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

// Function to swap data of two nodes
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform selection sort on the linked list
void selectionSort(struct Node *head)
{
    struct Node *temp1 = head;

    // Traverse the list
    while (temp1 != NULL)
    {
        struct Node *minNode = temp1;
        struct Node *temp2 = temp1->next;

        // Find the minimum element in the unsorted list
        while (temp2 != NULL)
        {
            if (temp2->data < minNode->data)
            {
                minNode = temp2;
            }
            temp2 = temp2->next;
        }

        // Swap data of the minimum element with the current element
        swap(&temp1->data, &minNode->data);
        temp1 = temp1->next;
    }
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

    // Create the linked list with initial values
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        appendNode(&head, arr[i]);
    }

    printf("Original list: ");
    printList(head);

    // Perform selection sort
    selectionSort(head);

    printf("Sorted list: ");
    printList(head);

    return 0;
}
