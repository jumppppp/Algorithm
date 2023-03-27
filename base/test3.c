//有序数组寻找数字

//需求：实现一个数组{0,1,2,3,4,5},随意取范围内数的和，例如2,4就是将下表2和4之间的数相加
#include<stdio.h>
#include<stdlib.h>
//一堆数中找出现奇数次数的
#include<time.h>
#define SIZE 11
int main() {
    int random_num;
    int a[SIZE] = { 0,0,2,2,4,5,5,5,4,6,6 };
    int e = 0;
    for (int i = 0;i < SIZE;i++) {
        e ^= a[i];
    }
    printf("%d\n", e);

}