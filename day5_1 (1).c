#include <stdio.h>
int main() {
    int p, q;
    printf("Enter number of elements in first array: ");
    scanf("%d", &p);
    int log1[p];
    printf("Enter elements of first sorted array:\n");
    for(int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }
    printf("Enter number of elements in second array: ");
    scanf("%d", &q);
    int log2[q];
    printf("Enter elements of second sorted array:\n");
    for(int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }
    int merged[p + q];
    int i = 0, j = 0, k = 0;
    while(i < p && j < q) {
        if(log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }
    while(i < p) {
        merged[k++] = log1[i++];
    }
    while(j < q) {
        merged[k++] = log2[j++];
    }
    printf("Merged array is:\n");
    for(int i = 0; i < p + q; i++) {
        printf("%d ", merged[i]);
    }
    return 0;
}
