#include<stdio.h>
#include<stdlib.h>
int main() {
    int a = 7809;
    int b = 12;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("a=%d,b=%d\n", a, b);
}