#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int total = 0;

    int curMax = arr[0], maxSum = arr[0];
    int curMin = arr[0], minSum = arr[0];

    for(int i = 0; i < n; i++) {
        total += arr[i];

        if(i != 0) {
            curMax = max(arr[i], curMax + arr[i]);
            maxSum = max(maxSum, curMax);

            curMin = min(arr[i], curMin + arr[i]);
            minSum = min(minSum, curMin);
        }
    }

    if(maxSum < 0) {
        printf("%d", maxSum);
    } else {
        printf("%d", max(maxSum, total - minSum));
    }

    return 0;
}