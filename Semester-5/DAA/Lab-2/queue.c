#include<stdio.h>
#include<stdlib.h>

#define SIZE 100
struct Queue {
    int items[SIZE];
    int front, rear;
};
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}
void enqueue(struct Queue* q, int element) {
    if (q->rear == SIZE - 1) {
        printf("Queue overflow\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->items[++q->rear] = element;
        printf("Enqueued: %d\n", element);
    }
}
void dequeue(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue underflow\n");
    } else {
        printf("Dequeued: %d\n", q->items[q->front++]);
    }
}
void display(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}
void main() {
    struct Queue* q = createQueue();
    int choice, element;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(q, element);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                free(q);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}