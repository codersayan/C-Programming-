#include <stdio.h>
#include <stdlib.h>

// Define structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Define structure for a doubly linked list node
struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
};

// Function prototypes for singly linked list operations
void initializeList();
void insertAtBeginning();
void insertAtEnd();
void viewList();
void convertToCircular();
void convertToDoubly();

// Function prototypes for doubly linked list operations
void viewDoublyList();

// Global pointers to the head of each list type
struct Node* head = NULL;
struct DNode* dhead = NULL;  // For doubly linked list
int isCircular = 0;
int isDoubly = 0;

int main() {
    int choice;

    while (1) {
        printf("\n\n--- Linked List Operations ---\n");
        printf("1. Initialize List with Elements\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. View List\n");
        printf("5. Convert to Circular Linked List\n");
        printf("6. Convert to Doubly Linked List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: initializeList(); break;
            case 2: insertAtBeginning(); break;
            case 3: insertAtEnd(); break;
            case 4: viewList(); break;
            case 5: convertToCircular(); break;
            case 6: convertToDoubly(); break;
            case 0: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to initialize the list with a specified number of elements
void initializeList() {
    int n, value,i;
    printf("Enter the number of elements to initialize the list: ");
    scanf("%d", &n);

    for ( i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(value);
    }
}

// Function to insert a node at the beginning of the list
void insertAtBeginning() {
    int value;
    printf("Enter value to insert at beginning: ");
    scanf("%d", &value);

    if (isDoubly) {
        struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
        newNode->data = value;
        newNode->next = dhead;
        newNode->prev = NULL;
        if (dhead != NULL) {
            dhead->prev = newNode;
        }
        dhead = newNode;
    } else {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        if (isCircular) {
            struct Node* temp = head;
            while (temp->next != NULL && temp->next != head) {
                temp = temp->next;
            }
            temp->next = head;
        }
    }
    printf("Inserted %d at the beginning.\n", value);
}

// Function to insert a node at the end of the list
void insertAtEnd(int value) {
    if (isDoubly) {
        struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
        newNode->data = value;
        newNode->next = NULL;
        if (dhead == NULL) {
            dhead = newNode;
            newNode->prev = NULL;
        } else {
            struct DNode* temp = dhead;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    } else {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            if (isCircular) {
                head->next = head;
            }
        } else {
            struct Node* temp = head;
            while (temp->next != NULL && temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            if (isCircular) {
                newNode->next = head;
            }
        }
    }
    printf("Inserted %d at the end.\n", value);
}

// Function to view the current list structure
void viewList() {
    if (isDoubly) {
        viewDoublyList();
        return;
    }

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List elements: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != NULL && temp != head);
    
    if (isCircular) {
        printf("...");
    } else {
        printf("NULL");
    }
    printf("\n");
}

// Function to view the doubly linked list
void viewDoublyList() {
    if (dhead == NULL) {
        printf("Doubly linked list is empty.\n");
        return;
    }

    struct DNode* temp = dhead;
    printf("Doubly linked list elements: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to convert a singly linked list to a circular linked list
void convertToCircular() {
    if (head == NULL) {
        printf("List is empty. Cannot convert to circular linked list.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;  // Link last node to the head
    isCircular = 1;
    printf("Converted to Circular Linked List.\n");
}

// Function to convert the list to a doubly linked list
void convertToDoubly() {
    if (head == NULL) {
        printf("List is empty. Cannot convert to doubly linked list.\n");
        return;
    }

    struct Node* temp = head;
    dhead = NULL;

    while (temp != NULL && (!isCircular || temp->next != head)) {
        struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
        newNode->data = temp->data;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (dhead == NULL) {
            dhead = newNode;
        } else {
            struct DNode* dtemp = dhead;
            while (dtemp->next != NULL) {
                dtemp = dtemp->next;
            }
            dtemp->next = newNode;
            newNode->prev = dtemp;
        }
        temp = temp->next;
    }
    isDoubly = 1;
    head = NULL;
    isCircular = 0;
    printf("Converted to Doubly Linked List.\n");
}

