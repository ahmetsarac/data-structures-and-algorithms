#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    int priority;
    struct node *next;
} node;

typedef struct priority_queue {
    node *front;
    node *rear;
} priority_queue;

void init_priority_queue(priority_queue **priority_queue);
node *create_node(int data, int priority);
void enqueue(priority_queue *priority_queue, int data, int priority);
int dequeue(priority_queue *priority_queue);
int peek(priority_queue *priority_queue);
void print_priority_queue(priority_queue *priority_queue);

int main(void) {
    priority_queue *priority_queue;

    init_priority_queue(&priority_queue);
    enqueue(priority_queue, 20, 3);
    enqueue(priority_queue, 10, 1);
    enqueue(priority_queue, 30, 2);

    print_priority_queue(priority_queue);

    printf("Dequeued %d from the queue\n", dequeue(priority_queue));
    printf("Peeked %d from the queue\n", peek(priority_queue));
    printf("Dequeued %d from the queue\n", dequeue(priority_queue));
    printf("Dequeued %d from the queue\n", dequeue(priority_queue));

    print_priority_queue(priority_queue);

    return 0;
}

void init_priority_queue(priority_queue **priority_queue) {
    *priority_queue = (struct priority_queue *)malloc(sizeof(priority_queue));
    (*priority_queue)->front = NULL;
    (*priority_queue)->rear = NULL;
}

node *create_node(int data, int priority) {
    node *new_node = (struct node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;
    return new_node;
}

void enqueue(priority_queue *priority_queue, int data, int priority) {
    node *new_node = create_node(data, priority);

    if (priority_queue->front == NULL) {
        priority_queue->front = priority_queue->rear = new_node;
        return;
    }

    if (priority_queue->front->priority > priority) {
        new_node->next = priority_queue->front;
        priority_queue->front = new_node;
        return;
    }

    node *temp = priority_queue->front;
    while (temp->next != NULL && temp->next->priority <= priority) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    if (temp == priority_queue->rear) {
        priority_queue->rear = new_node;
    }
}

int dequeue(priority_queue *priority_queue) {
    if (priority_queue->front == NULL) {
        printf("Priority queue is empty.\n");
        return -1;
    }
    node *temp = priority_queue->front;
    int data = temp->data;
    priority_queue->front = priority_queue->front->next;
    if (priority_queue->front == NULL) {
        priority_queue->rear = NULL;
    }
    free(temp);
    return data;
}

int peek(priority_queue *priority_queue) {
    if (priority_queue->front == NULL) {
        printf("Priority queue is empty.\n");
        return -1;
    }
    return priority_queue->front->data;
}

void print_priority_queue(priority_queue *priority_queue) {
    printf("\nPriority Queue\n");
    printf("--------------\n");
    node *temp = priority_queue->front;
    if (temp == NULL) {
        printf("Queue is empty.");
        return;
    }
    while (temp != NULL) {
        printf("%8d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}