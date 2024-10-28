#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // maximum size of the stack

// Stack structure
struct Stack {
    int data[MAX];
    int top;
};

// Initialize the stack
void init(struct Stack *s) {
    s->top = -1;
}

// Check if the stack is full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->data[++(s->top)] = value;
    printf("%d pushed to stack\n", value);
}

// Pop an element from the stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->data[(s->top)--];
}

// Peek the top element of the stack
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->data[s->top];
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

    return 0;
}
