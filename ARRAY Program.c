#include <stdio.h>

// Global array and size variables to store elements and current array size
int arr[100];
int size;

// Function to read array elements from the user
void read() {
    printf("\nHow many numbers you want to insert: ");
    scanf("%d", &size); // User inputs the number of elements

    printf("Enter the numbers:\n");
    // Loop to take 'size' number of inputs and store them in the array
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

// Function to print the current elements in the array
void print() {
    printf("The array: ");
    // Loop through the array and print each element
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to search for an element in the array
int search(int item) {
    int index = -1; // Default value if item is not found

    // Loop to find the item; if found, store index and break
    for (int i = 0; i < size; i++) {
        if (arr[i] == item) {
            index = i;
            break;
        }
    }
    return index; // Return the index of the item or -1 if not found
}

// Function to insert an item at the end of the array
void insertEnd(int item) {
    arr[size++] = item; // Place item at the end and increment size
}

// Function to insert an item at the front of the array
void insertFront(int item) {
    // Shift all elements one position to the right to make space at the front
    for (int i = size; i > 0; i--)
        arr[i] = arr[i - 1];
    
    arr[0] = item; // Insert the item at the front
    size++; // Increment the array size
}

// Function to insert an item at a specific index in the array
void insertAny(int item, int index) {
    // Shift elements one position to the right from the specified index
    for (int i = size; i > index; i--)
        arr[i] = arr[i - 1];
    
    arr[index] = item; // Insert the item at the given index
    size++; // Increment the array size
}

// Function to delete an item from the end of the array
void deleteEnd() {
    size--; // Decrement size to "remove" the last element
}

// Function to delete an item from the front of the array
void deleteFront() {
    // Shift all elements one position to the left, overwriting the first element
    for (int i = 0; i < size - 1; i++)
        arr[i] = arr[i + 1];
    
    size--; // Decrement the array size
}

// Function to delete an item from a specific index in the array
void deleteAny(int index) {
    // Shift elements one position to the left, starting from the specified index
    for (int i = index; i < size - 1; i++)
        arr[i] = arr[i + 1];
    
    size--; // Decrement the array size
}

// Function to sort the array in ascending order using Bubble Sort
void sort() {
    // Outer loop for each pass
    for (int i = 0; i < size - 1; i++) {
        // Inner loop for comparison in each pass
        for (int j = 0; j < size - i - 1; j++) {
            // Swap if the current element is greater than the next element
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Main function to manage user interaction and call appropriate functions
int main() {
    int choice, item, index;

    printf("\n== ARRAY OPERATIONS ==\n");
    read(); // Call read function to input initial array values
    printf("\n1. Print array"
           "\n2. Search"
           "\n3. Insertion at end"
           "\n4. Insertion at front"
           "\n5. Insertion at any position"
           "\n6. Deletion from end"
           "\n7. Deletion from front"
           "\n8. Deletion from any position"
           "\n9. Sort"
           "\n0. Exit");

    // Infinite loop to keep taking user choices
    while (1) {
        printf("\n> ");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            printf("Bye!\n"); // Exit the program
            return 0;

        case 1:
            if (size == 0) {
                printf("Empty array.\n");
                continue;
            }
            print(); // Print current array elements
            break;

        case 2:
            printf("Enter an item to be searched: ");
            scanf("%d", &item);
            index = search(item); // Call search function
            (index == -1) ? printf("Item is not found\n")
                          : printf("Item is found at index %d\n", index);
            break;

        case 3:
            printf("Enter an item to be inserted: ");
            scanf("%d", &item);
            insertEnd(item); // Insert item at the end
            printf("Inserted.\n");
            break;

        case 4:
            printf("Enter an item to be inserted: ");
            scanf("%d", &item);
            insertFront(item); // Insert item at the front
            printf("Inserted.\n");
            break;

        case 5:
            printf("Enter an item to be inserted: ");
            scanf("%d", &item);
            printf("Enter the location where you want to insert the item: ");
            scanf("%d", &index);
            insertAny(item, index); // Insert item at specific index
            printf("Inserted.\n");
            break;

        case 6:
            if (size == 0) {
                printf("Empty array.\n");
                continue;
            }
            deleteEnd(); // Delete item from end
            printf("Deleted.\n");
            break;

        case 7:
            if (size == 0) {
                printf("Empty array.\n");
                continue;
            }
            deleteFront(); // Delete item from front
            printf("Deleted.\n");
            break;

        case 8:
            if (size == 0) {
                printf("Empty array.\n");
                continue;
            }
            printf("Enter the location from where you want to delete: ");
            scanf("%d", &index);
            deleteAny(index); // Delete item from specified index
            printf("Deleted.\n");
            break;

        case 9:
            sort(); // Sort the array in ascending order
            printf("Sorted.\n");
            break;

        default:
            printf("Invalid choice! Try again...\n");
            break;
        }
    }
}

