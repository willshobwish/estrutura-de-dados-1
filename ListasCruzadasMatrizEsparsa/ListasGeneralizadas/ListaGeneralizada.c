#include <stdio.h>
#include<stdlib.h>

struct no{
    //  0 == atomo; 1 == lista
    int tipo;
    union{
        // Pode ser um elemento do tipo int ou um ponteiro para uma outra lista por causa do union
        int elemento;
        struct no *lista;
    }car;
    struct no *prox;
};
typedef struct no Rec;
Rec *lista;
