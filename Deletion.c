#include <stdio.h>

int main() {
    int arr[100], n, i, choice, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nChoose deletion operation:\n");
    printf("1. Delete from Front\n");
    printf("2. Delete from End\n");
    printf("3. Delete from Any Position\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1: // Delete from Front
            if(n == 0) {
                printf("Array is empty!\n");
                return 0;
            }

            for(i = 0; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
            break;

        case 2: // Delete from End
            if(n == 0) {
                printf("Array is empty!\n");
                return 0;
            }

            n--;  // Just reduce size
            break;

        case 3: // Delete from Any Position
            if(n == 0) {
                printf("Array is empty!\n");
                return 0;
            }

            printf("Enter position (0 to %d): ", n - 1);
            scanf("%d", &pos);

            if(pos < 0 || pos >= n) {
                printf("Invalid position!\n");
                return 0;
            }

            for(i = pos; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
            break;

        default:
            printf("Invalid choice!");
            return 0;
    }

    printf("\nUpdated array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}