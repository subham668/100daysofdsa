#include <stdio.h>

int search(int nums[], int n, int target) {
    int left = 0, right = n - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    
    return -1;
}

int main() {
    int n, target;
    
    printf("Enter size: ");
    scanf("%d", &n);
    
    int nums[n];
    
    printf("Enter sorted elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    printf("Enter target: ");
    scanf("%d", &target);
    
    int result = search(nums, n, target);
    
    if(result != -1)
        printf("Target found at index: %d\n", result);
    else
        printf("Target not found\n");
    
    return 0;
}