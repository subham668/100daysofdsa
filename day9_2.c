#include <stdio.h>
#include <string.h>
void reverseString(char s[]) {
    int start = 0;
    int end = strlen(s) - 1;
    char temp;
    while(start < end) {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}
int main() {
    char s[100];
    printf("Enter string: ");
    scanf("%s", s);
    reverseString(s);
    printf("Reversed string: %s", s);
    return 0;
}

