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
    return string;
}

void insere(struct strdim *string, char elemento){
    struct strdim *anterior, *proximo;
    anterior = string->anterior;
    proximo = string->proximo;
    string->c = elemento;
}

void imprime(struct strdim *string){
    printf("Caractere armazenado: %c\n",string->c);
}
int main(void){
    struct strdim *string=inicializa();
    printf("Endereco em memoria: %p\n",string);
    insere(string,'a');
    imprime(string);
}