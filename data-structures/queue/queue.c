#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct queue {
    node *front;
    node *rear;
} queue;

void init_queue(queue **queue);
node *create_node(int data);
void enqueue(queue *queue, int data);
int dequeue(queue *queue);
int peek(queue *queue);
void print_queue(queue *queue);

int main(void) {

    queue *queue;
    init_queue(&queue);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    print_queue(queue);

    printf("Dequeued %d from the queue\n", dequeue(queue));
    printf("Peeked %d from the queue\n", peek(queue));
    printf("Dequeued %d from the queue\n", dequeue(queue));
    printf("Dequeued %d from the queue\n", dequeue(queue));

    print_queue(queue);

    return 0;
}

void init_queue(queue **queue) {
    *queue = (struct queue *) malloc(sizeof(queue));
    (*queue)->front = NULL;
    (*queue)->rear = NULL;
}

node *create_node(int data) {
    node *node = (struct node *) malloc(sizeof(node));
    node->data = data;
    node->next = NULL;
    return node;
}

void enqueue(queue *queue, int data) {
    node *node = create_node(data);
    if (queue->rear != NULL) {
        queue->rear->next = node;
    }
    queue->rear = node;
    if (queue->front == NULL) {
        queue->front = node;
    }
}

int dequeue(queue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    node *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

int peek(queue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->front->data;
}

void print_queue(queue *queue) {
    printf("Queue: ");
    node *temp = queue->front;
    if(temp == NULL) {
        printf("Queue is empty.");
        return;
    }
    while(temp != NULL) {
        printf("\t%d\n", temp->data);
        temp = temp->next;
    }
}