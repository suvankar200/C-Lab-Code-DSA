#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Stack structure using linked list
struct Stack {
    struct Node* top;
};

// Initialize the stack
void init(struct Stack* s) {
    s->top = NULL;
}

// Check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == NULL;
}

// Push an element onto the stack
void push(struct Stack* s, int value) {
    // Allocate a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack overflow!\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    printf("%d pushed to stack\n", value);
}

// Pop an element from the stack
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    struct Node* temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

// Peek the top element of the stack
int peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->top->data;
}

// Clean up stack by freeing memory
void freeStack(struct Stack* s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

int main() {
    struct Stack stack;
    init(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is %d\n", peek(&stack));

    printf("%d popped from stack\n", pop(&stack));
    printf("Top element is %d\n", peek(&stack));

    // Free all nodes in the stack
    freeStack(&stack);

    return 0;
}
