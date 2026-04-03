#include <stdio.h>

int main() {
    int arr[100], n, i, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to insert at end: ");
    scanf("%d", &value);

    arr[n] = value;
    n++;

    printf("Updated array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}