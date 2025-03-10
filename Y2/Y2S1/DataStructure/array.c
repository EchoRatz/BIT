#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 21  // Max length for student names (20 + 1 for '\0')

// Node for each student in the queue
typedef struct Node {
    char name[MAX_LEN];
    struct Node* next;
} Node;

// Queue structure with pointers to the front and rear
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to add a student to the end of the queue
void enqueue(Queue* q, const char* studentName) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, studentName);
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove the student at the front of the queue
void dequeue(Queue* q) {
    if (q->front == NULL) {
        return;  // Queue is empty
    }

    Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;  // If the queue is now empty, reset the rear as well
    }

    free(temp);
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to get the name of the student at the front of the queue
void queueHead(Queue* q) {
    if (isEmpty(q)) {
        printf("Empty queue\n");
    } else {
        printf("%s\n", q->front->name);
    }
}

// Function to get the name of the student at the end of the queue
void queueTail(Queue* q) {
    if (isEmpty(q)) {
        printf("Empty queue\n");
    } else {
        printf("%s\n", q->rear->name);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Queue q;
    initQueue(&q);

    char operation[30];
    char studentName[MAX_LEN];

    for (int i = 0; i < n; i++) {
        scanf("%s", operation);

        if (strcmp(operation, "Arrive") == 0) {
            scanf("%s", studentName);
            enqueue(&q, studentName);
        } else if (strcmp(operation, "Leave") == 0) {
            dequeue(&q);
        } else if (strcmp(operation, "QueueHead") == 0) {
            queueHead(&q);
        } else if (strcmp(operation, "QueueTail") == 0) {
            queueTail(&q);
        }
    }

    return 0;
}
