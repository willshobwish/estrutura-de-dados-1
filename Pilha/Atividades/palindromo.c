#include<stdio.h>
#include<stdlib.h>

struct nodePilha{
    char elemento;
    struct nodePilha *proximo;
};

struct Pilha{
    struct nodePilha *topo;
};
typedef struct nodePilha nodePilha;
typedef struct Pilha Pilha;

void push(Pilha *pilha, char elemento){
    nodePilha *novo = malloc(sizeof(nodePilha));
    if(novo==NULL){
        novo->elemento = elemento;
        novo->proximo=NULL;
        pilha->topo = novo;
    }else{
        novo->elemento = elemento;
        novo->proximo = pilha->topo;
        pilha->topo = novo;
    }
}

void push_word(Pilha *pilha, char *word){
    for(int i =0 ;i<word/sizeof(char);i++){

    }

}

void print(Pilha *pilha){
    nodePilha *aux = pilha->topo;
    while(aux!=NULL){
        printf("%c",aux->elemento);
        aux = aux->proximo;
    }
}

int main(void){
    Pilha pilha;
    push(&pilha,'a');
    push(&pilha,'b');
    push(&pilha,'c');
    print(&pilha);
    return 0;
}