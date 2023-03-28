#include<stdio.h>
#include<stdlib.h>
struct strdim
{
    char c;
    struct strdim *proximo;
    struct strdim *anterior;
};
 

struct strdim * inicializa(){
    struct strdim *string = malloc(sizeof(struct strdim));
    string->anterior=NULL;
    string->proximo = malloc(sizeof(struct strdim));
    return string;
}

void insere(struct strdim *string, char elemento){
    struct strdim *anterior, *proximo;
    anterior = string->anterior;
    anterior->proximo = string;
    string->proximo = malloc(sizeof(struct strdim));
    string->c = elemento;
}

void imprime(struct strdim *string){
    printf("Caractere armazenado: %c\n",string->c);
}
int main(void){
    struct strdim *string=inicializa();
    printf("Endereco em memoria: %p\nEndereco para o anterior: %p\nEndereco para o proximo: %p\n",string,string->anterior,string->proximo);
    insere(string,'a');
    insere(string,'b');

    imprime(string);
}