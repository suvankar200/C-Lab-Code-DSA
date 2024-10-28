#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to swap the data of two nodes
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort function for linked list
void bubbleSort(struct Node *head)
{
    bool swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    // Check if the list is empty
    if (head == NULL)
    {
        return;
    }

    do
    {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(&ptr1->data, &ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
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

// Function to push a new node at the beginning
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int main()
{
    struct Node *head = NULL;

    // Creating the linked list
    push(&head, 34);
    push(&head, 65);
    push(&head, 45);
    push(&head, 34);
    push(&head, 23);
    push(&head, 3);
    push(&head, 23);
    push(&head, 11);
    push(&head, 3);
    push(&head, 2);

    printf("Linked list before sorting:\n");
    printList(head);

    bubbleSort(head);

    printf("Linked list after sorting:\n");
    printList(head);

    return 0;
}
