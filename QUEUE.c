#include <stdio.h>
#include <stdlib.h>
#define SIZE 5  // Define the maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;
int i;

// Function to check if the queue is full
int isFull() {
    return (rear == SIZE - 1);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Function to add an element to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue %d\n", value);
    } else {
        if (front == -1) front = 0;  // Set front to 0 if adding the first element
        rear++;
        queue[rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// Function to remove an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
    } else {
        printf("Dequeued %d\n", queue[front]);
        front++;
        // Reset front and rear when all elements are dequeued
        if (front > rear) front = rear = -1;
    }
}

// Function to view the front element of the queue
void peek() {
    if (isEmpty()) {
        printf("Queue is empty! No element to peek.\n");
    } else {
        printf("Front element is %d\n", queue[front]);
    }
}

// Function to display all elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for ( i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

