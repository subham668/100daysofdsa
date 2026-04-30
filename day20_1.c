#include <stdio.h>
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int prefix_sum = 0;
    int count = 0;
    int hash[1000] = {0};
    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if(prefix_sum == 0) {
            count++;
        }
        if(hash[prefix_sum + 500] > 0) {
            count += hash[prefix_sum + 500];
        }
        hash[prefix_sum + 500]++;
    }
    printf("Count of zero sum subarrays: %d", count);
    return 0;
}