#include <stdio.h>
#include <stdlib.h>

int main(void){
    char string[]="cinco";
    printf("%d\n",sizeof(string)/sizeof(char));
    for(int i=0;i<sizeof(string)/sizeof(char);i++){
        printf("%c = %d\n",string[i],string[i]);
    }
}