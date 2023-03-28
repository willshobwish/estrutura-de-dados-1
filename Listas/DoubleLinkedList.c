#include <stdio.h>
#include <stdlib.h>

struct Lista {
    int elemento;
    struct Lista *proximo = NULL;
    *anterior;
};

void Insere(struct Lista *lista, int elemento) {
    struct Lista *anterior, *proximo, *atual = lista;
    while (atual->proximo != NULL) {
        anterior = atual->anterior;
        atual = atual->proximo;
        proximo = atual->proximo;
        ImprimeInformacoes(anterior);
        ImprimeInformacoes(atual);
        ImprimeInformacoes(proximo);
    }
    atual = proximo;
    atual = malloc(sizeof(struct Lista));
    atual->elemento = elemento;
    atual->anterior = anterior;
    atual->proximo = NULL;
}

void ImprimeInformacoes(struct Lista *lista){
    printf("Endereco anterior: %p\nEndereco atual: %p\nEndereco proximo: %p\n",lista->anterior,lista,lista->proximo);
}

void Imprime(struct Lista *lista) {
    struct Lista *anterior, *proximo, *atual = lista;
    while (atual->proximo != NULL) {
        printf("Elemento: %d\n", atual->elemento);
        anterior = atual->anterior;
        atual = atual->proximo;
        proximo = atual->proximo;
    }
}
int main(void) {
    struct Lista *listaTeste = malloc(sizeof(struct Lista));
    Insere(listaTeste, 1);
    Imprime(listaTeste);
}