#include <stdio.h>

int main() {
    int arr[100], n, i, choice, value, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nChoose operation:\n");
    printf("1. Insert at Front\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Any Position\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1: // Insert at Front
            printf("Enter value: ");
            scanf("%d", &value);

            for(i = n; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = value;
            n++;
            break;

        case 2: // Insert at End
            printf("Enter value: ");
            scanf("%d", &value);

            arr[n] = value;
            n++;
            break;

        case 3: // Insert at Any Position
            printf("Enter position (0 to %d): ", n);
            scanf("%d", &pos);

            if(pos < 0 || pos > n) {
                printf("Invalid position!\n");
                return 0;
            }

            printf("Enter value: ");
            scanf("%d", &value);

            for(i = n; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = value;
            n++;
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