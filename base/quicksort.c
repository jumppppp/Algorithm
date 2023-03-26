#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100000

void qs(size_t a[], int l, int r) {
    //printf("l=%d,r=%d\n", l, r);
    if (l >= r) {
        return;
    }
    int key = a[l];
    int i = l;
    // int p = l;
    int j = r;
    while (i < j) {
        while (i < j && a[j] >= key) {
            j--;
        }
        // a[p] = a[j];
        // p = j;
        while (i < j && a[i] <= key) {
            i++;
        }
        //printf("i=%d,j=%d,key=%d\n", i, j, key);
        // a[p] = a[i];
        // p = i;
        if (i < j) {
            a[i] = a[i] ^ a[j];
            a[j] = a[i] ^ a[j];
            a[i] = a[i] ^ a[j];
        }
    }
    if (a[i] != a[l]) {
        a[i] = a[l] ^ a[i];
        a[l] = a[l] ^ a[i];
        a[i] = a[l] ^ a[i];
    }

    // a[i] = key;
    // for (int i = 0;i < SIZE;i++) {
    //     printf("%d ", a[i]);
    // }
    //printf("\n");
    qs(a, l, i - 1);
    qs(a, j + 1, r);
}
int main() {
    size_t random_num;
    size_t a[SIZE] = { 0 };
    srand((unsigned)time(NULL)); // 初始化随机数种子
    for (size_t i = 0; i < SIZE; i++)
    {
        random_num = rand() % SIZE; // 生成0-10之间的随机数
        a[i] = random_num;
    }
    // for (int i = 0;i < SIZE;i++) {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    qs(a, 0, SIZE - 1);

    // for (size_t i = 0;i < SIZE;i++) {
    //     printf("%d ", a[i]);
    // }
}