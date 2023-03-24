#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100000
int main(){
    int random_num;
        int a[SIZE]={0};
    srand((unsigned)time(NULL)); // 初始化随机数种子
    for (size_t i = 0; i < SIZE; i++)
    {
        random_num = rand() % SIZE; // 生成0-10之间的随机数
        a[i]=random_num;
    }
    int count = SIZE;
    for (size_t i = 0; i < count; i++)
    {
        int next = i+1;
        for (size_t j = next; j >0; j--)
        {
            if(a[j-1]>a[j]){
                int tmp = a[j-1];
                a[j-1]=a[j];
                a[j]=tmp;
            }
        }
        
    }
    
    
    
    
    // for(int i =0;i<SIZE;i++){
    //     printf("%d ",a[i]);
    // }
}