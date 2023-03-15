#include <stdio.h>
#define MAX 15

struct lista {
    int elementos[MAX];
    int quantidadeElementos;
};

int main(void) {
    struct lista lista;
    lista.elementos[0] = 1;
    lista.quantidadeElementos = 1;
    printf("%d", lista.elementos[0]);
}