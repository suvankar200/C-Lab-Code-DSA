#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node
{
    int data;
    struct Node *next;
};

// Queue structure using linked list
struct Queue
{
    struct Node *front;
    struct Node *rear;
};

// Initialize the queue
void init(struct Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

// Check if the queue is empty
int isEmpty(struct Queue *q)
{
    return q->front == NULL;
}

// Enqueue an element into the queue
void enqueue(struct Queue *q, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL)
    { // If queue is empty, front and rear are the same
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued to queue\n", value);
}

// Dequeue an element from the queue
int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow!\n");
        return -1;
    }

    struct Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
    { // Queue is now empty, update rear as well
        q->rear = NULL;
    }

    free(temp);
    return value;
}

// Peek the front element of the queue
int peek(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

int main()
{
    struct Queue queue;
    init(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element is %d\n", peek(&queue));

    printf("%d dequeued from queue\n", dequeue(&queue));
    printf("Front element is now %d\n", peek(&queue));

    return 0;
}
