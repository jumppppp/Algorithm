#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#define SIZE 100000
// #define PSIZE 100
int a[SIZE]={0};

struct ty{
    int next;

};
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void * p(void *me){
    struct ty *t1 = (struct ty *)me;
            for (size_t j = t1->next; j >0; j--)
    {
        if(a[j-1]>a[j]){
            
            int tmp = a[j-1];
                    pthread_mutex_lock(&mutex);
            a[j-1]=a[j];
            a[j]=tmp;
                    pthread_mutex_unlock(&mutex);
        }
    }
    pthread_exit(NULL);
}
int main(){
    int random_num;
    struct ty t1;
    
    srand((unsigned)time(NULL)); // 初始化随机数种子
    for (size_t i = 0; i < SIZE; i++)
    {
        random_num = rand() % SIZE; // 生成0-10之间的随机数
        a[i]=random_num;
    }
    int count = SIZE;
    pthread_t pid[SIZE]={0};
    for (size_t i = 0; i < count; i++)
    {

        int next = i+1;
        t1.next = next;
        
        pthread_create(&pid[i],NULL,p,(void *)&t1);


        
    }
    for (size_t i = 0; i < count; i++)
    {
        pthread_join(pid[i],NULL);
    }
    

    // for(int i =0;i<SIZE;i++){
    //     printf("%d ",a[i]);
    // }
    exit(0);
}