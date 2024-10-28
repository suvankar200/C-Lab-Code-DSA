#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void printData(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("The data is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertAfterANode(struct node *head, int position, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->next->data == position)
        {

            newNode->next = ptr->next;
            ptr->next = newNode;
            return head;
        }
        ptr=ptr->next;
    }

    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    head->data = 5;
    head->next = second;
    second->data = 6;
    second->next = third;
    third->data = 35;
    third->next = NULL;
    printData(head);
    printf("After Insertion at the beginning\n");

    head = insertAfterANode(head, 6, 10);
    printData(head);
    return 0;
}