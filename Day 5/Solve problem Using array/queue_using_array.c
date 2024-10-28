#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // maximum size of the queue

// Queue structure
struct Queue {
    int data[MAX];
    int front, rear;
};

// Initialize the queue
void init(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(struct Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// Check if the queue is empty
int isEmpty(struct Queue *q) {
    return q->front == -1;
}

// Enqueue an element into the queue
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue overflow!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; // Set front to 0 if adding the first element
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    printf("%d enqueued to queue\n", value);
}

// Dequeue an element from the queue
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow!\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        // Queue is now empty after this dequeue
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

// Peek the front element of the queue
int peek(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->data[q->front];
}

int main() {
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
