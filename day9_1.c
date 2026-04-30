#include <stdio.h>
#include <string.h>
int main() {
    int a, b;
    char s[50];
    printf("Enter the string: ");
    scanf("%s", s);  
    b = strlen(s);
    for(a = b - 1; a >= 0; a--) {
        printf("%c", s[a]);
    }
    return 0;
}
