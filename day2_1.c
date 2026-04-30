#include <stdio.h>
int main() {
    int n, pos;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position of element to delete: ");
    scanf("%d", &pos);
    for(int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    printf("Array after deletion is:\n");
    for(int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
