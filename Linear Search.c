#include <stdio.h>

int main() {
    int arr[100], n, i, key, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Element found at index %d", i);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Element not found");
    }

    return 0;
}


