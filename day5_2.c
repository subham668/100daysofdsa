#include <stdio.h>
void merge(int nums1[], int m, int nums2[], int n) {    
    int i = m - 1;        
    int j = n - 1;      
    int k = m + n - 1;   
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
   while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}
int main() {
    int m, n;
    printf("Enter number of elements in nums1 (m): ");
    scanf("%d", &m);
    printf("Enter number of elements in nums2 (n): ");
    scanf("%d", &n);    
    int nums1[m + n];
    int nums2[n];
    printf("Enter %d sorted elements for nums1:\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }
for (int i = m; i < m + n; i++) {
        nums1[i] = 0;
    }
     printf("Enter %d sorted elements for nums2:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }
    merge(nums1, m, nums2, n);
    printf("\nMerged Sorted Array:\n");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }
    return 0;
}
