//需求：实现一个数组{0,1,2,3,4,5},随意取范围内数的和，例如2,4就是将下表2和4之间的数相加
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10
#define SN 5
int main() {
    time_t ti = time(NULL);

    int random_num, max, min;
    int a[SIZE] = { 0 };
    srand((unsigned)time(NULL)); // 初始化随机数种子
    for (size_t i = 0; i < SIZE; i++)
    {
        random_num = rand() % SIZE; // 生成0-10之间的随机数
        a[i] = random_num;
    }
    int sum[SN] = { 0 };
    int tmp = 0;
    int b[SIZE] = { 0 };
    for (size_t i = 0; i < SIZE; i++)
    {
        for (int j = 0;j < i;j++) {
            b[i] += a[j];
        }
    }
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    int sum2[SN] = { 0 };
    for (size_t i = 0; i < SN; i++)
    {
        tmp = 0;
        max = rand() % SIZE; // 生成0-10之间的随机数
        min = rand() % SIZE; // 生成0-10之间的随机数
        // printf("max=%d,min=%d\t",max,min);
        if (max < min) {
            max = max + min;
            min = max + min;
            max = min - max;
            min = min - 2 * max;
        }

        for (size_t i = min; i < max; i++)
        {
            tmp += a[i];

        }
        sum[i] = tmp;

        sum2[i] = b[max] - b[min];
        printf("max=%d,min=%d sum=%d,sum2=%d\n", max, min, sum[i], sum2[i]);
    }
    for (size_t i = 0; i < SN; i++)
    {
        printf("%d ", sum[i]);
    }
    printf("\n");
    for (size_t i = 0; i < SN; i++)
    {
        printf("%d ", sum2[i]);
    }
    time_t ti2 = time(NULL);
    FILE* fp;
    fp = fopen("tmp.txt", "w+");
    fprintf(fp, "%f\n", ti2 - ti);
    fclose(fp);
    exit(0);

}