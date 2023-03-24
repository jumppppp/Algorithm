//有序数组寻找数字

//需求：实现一个数组{0,1,2,3,4,5},随意取范围内数的和，例如2,4就是将下表2和4之间的数相加
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100
int main() {
    int random_num;
    int a[SIZE] = { 0 };
    srand((unsigned)time(NULL)); // 初始化随机数种子
    for (size_t i = 0; i < SIZE; i++)
    {
        random_num = rand() % SIZE; // 生成0-10之间的随机数
        a[i] = random_num;
    }
    int count = SIZE;

    for (size_t i = 0; i < count; i++)
    {
        int next = i + 1;
        for (size_t j = next; j > 0; j--)
        {
            if (a[j - 1] > a[j]) {
                int tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
        }

    }
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }
    int k = 19;
    int d = 0;
    int l = 0;
    int r = SIZE - 1;
    printf("\n");
    while (l <= r)
    {
        d = l + (r - l) / 2;
        printf("a[%d]=%d,l=%d,r=%d\n", d, a[d], l, r);

        if (a[d] == k) {
            printf("a[%d]=%d\n", d, k);
            break;
        }
        else if (a[d] > k) {
            r = d - 1;
        }
        else if (a[d] < k) {
            l = d + 1;
        }

    }
    d = 0;
    l = 0;
    r = SIZE - 1;
    while (l <= r)
    {
        d = l + (r - l) / 2;
        printf("a[%d]=%d,l=%d,r=%d\n", d, a[d], l, r);

        if (a[d] == k) {
            printf("a[%d]=%d\n", d + 1, a[d + 1]);
            break;
        }
        else if (a[d] > k) {
            r = d - 1;
        }
        else if (a[d] < k) {
            l = d + 1;
        }

    }
    d = 0;
    l = 0;
    r = SIZE - 1;
    while (l <= r)
    {
        d = l + (r - l) / 2;
        printf("a[%d]=%d,l=%d,r=%d\n", d, a[d], l, r);

        if (a[d] == k) {
            printf("a[%d]=%d\n", d - 1, a[d - 1]);
            break;
        }
        else if (a[d] > k) {
            r = d - 1;
        }
        else if (a[d] < k) {
            l = d + 1;
        }

    }
    d = 0;
    l = 0;
    r = SIZE - 1;
    int ap = 0;
    while (l <= r)
    {
        d = l + (r - l) / 2;
        printf("a[%d]=%d,l=%d,r=%d\n", d, a[d], l, r);

        if (a[d] >= k) {
            ap = d;
            r = d - 1;
        }
        else if (a[d] < k) {
            l = d + 1;
        }

    }
    printf("end;a[%d]=%d\n", ap, a[ap]);



}