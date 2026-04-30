#include <stdio.h>

int main(){
/* Write a program to swap two numbers using a third variable.
Input 1:
3 5
Output 1:
After swap: 5 3
Input 2:
-1 1
Output 2:
After swap: 1 -1*/
int a,b, temp;
scanf("%d",&a);
scanf("%d",&b);
temp = a ;
a = b ;
b = temp ;
printf("after swap : %d %d \n" , a,b);
    return 0;
}