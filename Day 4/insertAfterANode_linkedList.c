#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void printelement(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct node *insertelementafternode(struct node *head, struct node *prevnode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
   ptr->next=prevnode->next;
   prevnode->next=ptr;
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
    head->data = 7;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 98;
    printf("Before insert\n");
    third->next = NULL;
    printelement(head);
      printf("After insert\n");
    head = insertelementafternode(head, second,34);
    printelement(head);
    return 0;
}