#include <stdio.h>
#include <stdlib.h>

struct caractere{
    char elemento;
    struct caractere *proximo;
    struct caractere *anterior;
};

struct string{
    struct caractere *inicio;
};

typedef struct string string;
typedef struct caractere caractere;

void inicializa(string *string){
    string = NULL;
}

void adiciona(string *stringrecebido, char elemento){
    caractere *auxiliar = stringrecebido->inicio,*anterior,*novo=malloc(sizeof(caractere));
    while(auxiliar!=NULL){
        anterior = auxiliar;
        auxiliar = auxiliar->proximo;
    }
    novo->elemento = elemento;
    novo->proximo = NULL;
    novo->anterior = auxiliar;
    auxiliar = novo;
    auxiliar->elemento=elemento;
    auxiliar->anterior = anterior;
    anterior->proximo = auxiliar;
}

void imprime(string *stringrecebido){
    caractere *auxiliar = stringrecebido->inicio;
    while (auxiliar!=NULL)
    {
        printf("%c",auxiliar->elemento);
        auxiliar = auxiliar->proximo;
    }
}

int main(void){
    string palavra;
    inicializa(&palavra);
    adiciona(&palavra,'a');
    imprime(&palavra);
    return 0;
}

