#include <stdio.h>
int main()
{
    int n, val;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    printf("Enter value to remove: ");
    scanf("%d", &val);
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] != val)
        {
            nums[k] = nums[i];
            k++;
        }
    }
    printf("k = %d\n", k);
    printf("Updated array: ");
    for(int i = 0; i < k; i++)
    {
        printf("%d ", nums[i]);
    }
    return 0;
}
