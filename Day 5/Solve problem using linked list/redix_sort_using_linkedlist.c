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

// Function to find the maximum value in the linked list
int getMax(struct Node *head)
{
    int max = head->data;
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data > max)
            max = temp->data;
        temp = temp->next;
    }
    return max;
}

// Function to perform counting sort based on the current digit
void countingSort(struct Node **head_ref, int exp)
{
    struct Node *buckets[10] = {NULL}; // Buckets for digits 0-9
    struct Node *tails[10] = {NULL};   // Tail pointers for each bucket

    struct Node *temp = *head_ref;

    // Place nodes in buckets based on the current digit
    while (temp != NULL)
    {
        int bucketIndex = (temp->data / exp) % 10;
        if (buckets[bucketIndex] == NULL)
        {
            buckets[bucketIndex] = tails[bucketIndex] = temp;
        }
        else
        {
            tails[bucketIndex]->next = temp;
            tails[bucketIndex] = temp;
        }
        temp = temp->next;
    }

    // Reassemble the list from the buckets
    struct Node *newHead = NULL;
    struct Node *newTail = NULL;

    for (int i = 0; i < 10; i++)
    {
        if (buckets[i] != NULL)
        {
            if (newHead == NULL)
            {
                newHead = buckets[i];
                newTail = tails[i];
            }
            else
            {
                newTail->next = buckets[i];
                newTail = tails[i];
            }
        }
    }
    newTail->next = NULL; // End the list
    *head_ref = newHead;
}

// Function to perform radix sort on the linked list
void radixSort(struct Node **head_ref)
{
    int max = getMax(*head_ref);

    // Sort for each digit position (1s, 10s, etc.)
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(head_ref, exp);
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
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        appendNode(&head, arr[i]);
    }

    printf("Original list:\n");
    printList(head);

    // Perform radix sort
    radixSort(&head);

    printf("Sorted list:\n");
    printList(head);

    return 0;
}
