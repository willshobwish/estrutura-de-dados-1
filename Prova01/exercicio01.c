#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct strdim {
    char elemento;
    struct strdim *proximo;
    struct strdim *anterior;
};

typedef struct strdim strdim;

void inicializa(strdim *string) {
    string->elemento = NULL;
    string->proximo = NULL;
    string->anterior = NULL;
}

void insere(strdim *string, char elemento) {
    strdim *auxiliar = string, *novo = malloc(sizeof(strdim));
    novo->proximo = NULL;
    novo->elemento = elemento;
    while (auxiliar->proximo != NULL) {
        auxiliar = auxiliar->proximo;
    }
    novo->anterior = auxiliar;
    auxiliar->proximo = novo;
}

void imprime(strdim *string) {
    strdim *auxiliar = string;
    while (auxiliar != NULL) {
        printf("%c", auxiliar->elemento);
        auxiliar = auxiliar->proximo;
    }
    printf("\n");
}

bool string_igual(strdim *string1, strdim *string2) {
    bool resultado = false;
    strdim *aux1 = string1, *aux2 = string2;
    while (aux1 != NULL) {
        if (aux1->elemento == aux2->elemento) {
            resultado = true;
        } else {
            resultado = false;
            break;
        }
        aux1 = aux1->proximo;
        aux2 = aux2->proximo;
    }
    return resultado;
}

int main(void) {
    strdim s1, s2, s3;
    inicializa(&s1);
    inicializa(&s2);
    inicializa(&s3);

    insere(&s1, 'a');
    insere(&s1, 'b');
    insere(&s1, 'c');
    imprime(&s1);

    insere(&s2, 'a');
    insere(&s2, 'b');
    insere(&s2, 'c');
    imprime(&s2);
    if (string_igual(&s1, &s2)) {
        printf("Strings iguais\n");
    } else {
        printf("Strings diferentes\n");
    }

    insere(&s3, 'a');
    insere(&s3, 'b');
    insere(&s3, 'b');
    imprime(&s3);
    if (string_igual(&s1, &s3)) {
        printf("Strings iguais\n");
    } else {
        printf("Strings diferentes\n");
    }
    return 0;
}