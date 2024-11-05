#include <stdio.h>

void reverseArray(int arr[], int size) {
    int start = 0, end = size - 1;
    
    while (start < end) {
        // Swap elements at start and end
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        // Move pointers towards each other
        start++;
        end--;
    }
}

int main() {
    int n,i;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal Array: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    // Reverse the array
    reverseArray(arr, n);
    
    printf("\nReversed Array: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    return 0;
}

