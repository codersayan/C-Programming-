#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the stack

int stack[MAX];
int top = -1;

// Function prototypes
void push();
void pop();
void viewStack();
void deleteFirst();
void deleteLast();
void insertAtPosition();

int main() {
    int choice;

    while (1) {
        printf("\n\n--- Stack Operations ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. View Stack\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Insert at Position\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: viewStack(); break;
            case 4: deleteFirst(); break;
            case 5: deleteLast(); break;
            case 6: insertAtPosition(); break;
            case 0: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to push an element into the stack
void push() {
    int value;
    if (top == MAX - 1) {
        printf("Stack overflow! Cannot push element.\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        stack[++top] = value;
        printf("Pushed %d into the stack.\n", value);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack underflow! Cannot pop element.\n");
    } else {
        printf("Popped %d from the stack.\n", stack[top--]);
    }
}

// Function to view all elements in the stack
void viewStack() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Function to delete the first element from the stack
void deleteFirst() {
    if (top == -1) {
        printf("Stack is empty! No element to delete.\n");
    } else {
        for (int i = 0; i < top; i++) {
            stack[i] = stack[i + 1];
        }
        top--;
        printf("First element deleted from the stack.\n");
    }
}

// Function to delete the last element from the stack
void deleteLast() {
    if (top == -1) {
        printf("Stack is empty! No element to delete.\n");
    } else {
        printf("Deleted last element: %d\n", stack[top]);
        top--;
    }
}

// Function to insert an element at a specific position
void insertAtPosition() {
    int value, pos;

    if (top == MAX - 1) {
        printf("Stack overflow! Cannot insert element.\n");
    } else {
        printf("Enter value to insert: ");
        scanf("%d", &value);
        printf("Enter position to insert (1 to %d): ", top + 2);
        scanf("%d", &pos);

        if (pos < 1 || pos > top + 2) {
            printf("Invalid position! Please try again.\n");
        } else {
            for (int i = top; i >= pos - 1; i--) {
                stack[i + 1] = stack[i];
            }
            stack[pos - 1] = value;
            top++;
            printf("Inserted %d at position %d.\n", value, pos);
        }
    }
}