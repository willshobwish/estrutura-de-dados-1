#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 3
#define MAXPILHA 10

typedef struct{
    int Pilhas[MAX];
    int base[MAXPILHA];
    int top[MAXPILHA];
    int NumeroElementoPilha;
} PilhaMultipla;

void InicializaPilha(PilhaMultipla *Pilha){
    int i;
    Pilha->NumeroElementoPilha = MAX;
}

int main(void){

}