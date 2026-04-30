#include <stdio.h>
int main() {
    int n1, n2;
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter size of second array: ");
    scanf("%d", &n2);
    int nums1[n1], nums2[n2];
    printf("Enter elements of first array:\n");
    for(int i = 0; i < n1; i++) {
        scanf("%d", &nums1[i]);
    }
    printf("Enter elements of second array:\n");
    for(int i = 0; i < n2; i++) {
        scanf("%d", &nums2[i]);
    }
    int result[1000];
    int k = 0;
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            if(nums1[i] == nums2[j]) {
                result[k++] = nums1[i];
                nums2[j] = -1;  
                break;
            }
        }
    }
    printf("Intersection array:\n");
    for(int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}
