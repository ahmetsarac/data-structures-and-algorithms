#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct stack{
    node *top;
} stack;

void init_stack(stack **stack);
node *create_node(int data);
void push(stack *stack, int data);
int pop(stack *stack);
int peek(stack *stack);
void print_stack(stack *stack);

int main(void) {

    stack *stack; 
    init_stack(&stack);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    print_stack(stack);

    printf("Popped %d from stack\n", pop(stack));
    printf("Popped %d from stack\n", pop(stack));
    printf("Popped %d from stack\n", pop(stack));

    printf("Peeked %d from stack\n", peek(stack));

    printf("Popped %d from stack\n", pop(stack));
    printf("Popped %d from stack\n", pop(stack));

    print_stack(stack);

    return 0;
}

void init_stack(stack **stack) {
    *stack = (struct stack *) malloc(sizeof(*stack));
    (*stack)->top = NULL;
}

node *create_node(int data) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(stack *stack, int data) {
    node *new_node = create_node(data);
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(stack *stack) {
    if(stack->top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    int data = stack->top->data;
    node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int peek(stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->top->data;
}

void print_stack(stack *stack) {
    printf("Stack: ");
    node *temp = stack->top;
    if(temp == NULL) {
        printf("Stack is empty.");
        return;
    }
    while (temp != NULL) {
        printf("\t%d\n", temp->data);
        temp = temp->next;
    }
}