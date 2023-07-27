#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int main(void){
    int *ponteiro = (int*)calloc(MAX,sizeof(int));
    for(int i=0;i<MAX;i++){
        ponteiro[i] = i*20;
    }
    for(int i=0;i<MAX;i++){
        printf("%d\n",ponteiro[i]);
    }
    // printf("%d",sizeof(ponteiro));
    return 0;
}