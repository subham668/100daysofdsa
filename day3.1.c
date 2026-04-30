#include <stdio.h>

int main(){
    /*Write a program to convert temperature from Celsius to Fahrenheit.
Input 1:
0
Output 1:
Fahrenheit=32
Input 2:
100
Output 2:
Fahrenheit=212*/
float celsius, fahrenheit;
printf("enter the temprature in celsius=");
scanf("%f", & celsius);
fahrenheit = (celsius * 9/5) + 32;
printf("temprature in fahrenheit : %.2f/n" , fahrenheit);
    return 0;
}