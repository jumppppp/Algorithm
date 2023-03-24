#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10000
int main(){
    int random_num;
        int a[SIZE]={0};
    srand((unsigned)time(NULL)); // 初始化随机数种子
    for (size_t i = 0; i < SIZE; i++)
    {
        random_num = rand() % SIZE; // 生成0-10之间的随机数
        a[i]=random_num;
    }

    for(int i=0;i<SIZE;i++){
        for(int j=i;j<SIZE;j++){
            if(a[i]>a[j]){
                int tmp = a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
    
    // for(int i =0;i<SIZE;i++){
    //     printf("%d ",a[i]);
    // }
}