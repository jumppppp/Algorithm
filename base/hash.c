#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int main() {

    struct hash_t
    {
        int key;
        char val;
    };

    struct hash_t hash[SIZE];

    for (size_t i = 0; i < SIZE; i++)
    {
        hash[i].key = i;
        sprintf(&hash[i].val, "%c", i);

    }
    for (size_t i = 0; i < SIZE; i++)
    {
        fprintf(stdout, "key=%d\tval=%c\n", hash[i].key, hash[i].val);

    }










    exit(0);
}