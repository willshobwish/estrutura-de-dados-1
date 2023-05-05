#include <stdio.h>
#include <stdlib.h>

#define MAX 15
#define NPilha 3
struct PilhaMultp {
    int P[MAX];
    int base[NPilha];
    int topo[NPilha];
    int NElemP;
};

// Inicializando todas as pilhas, ou seja, dando valor à base e topo
void InicializaPilhas(struct PilhaMultp *PM) {
    int i;
    PM->NElemP = MAX / NPilha;
    for (i = 0; i < NPilha; i++) {
        PM->base[i] = PM->NElemP * i;
        PM->topo[i] = PM->base[i];
    }
}

// Verifica se uma pilha X está cheia - todas as pilhas são do mesmo tamanho (NElemP)
short PilhaXCheia(struct PilhaMultp *PM, int PilhaX) {
    if ((PM->topo[PilhaX] - PM->base[PilhaX]) < PM->NElemP)
        return 0;
    else
        return 1;
}

// Verifica se uma pilha X está cheia - as pilhas não tem o mesmo tamanho
/*short PilhaXCheia(struct PilhaMultp *PM, int PilhaX)
{
    if (PM->topo[PilhaX] < PM->base[PilhaX+1])
        return 0;
    else
        return 1;
}*/

// Verifica se uma pilha X está vazia
short PilhaXVazia(struct PilhaMultp *PM, int PilhaX) {
    if (PM->topo[PilhaX] == PM->base[PilhaX])
        return 1;
    else
        return 0;
}

int push(struct PilhaMultp *PM, int elemento, int PilhaX) {
    if (!PilhaXCheia(PM, PilhaX)) {
        PM->P[PM->topo[PilhaX]] = elemento;
        PM->topo[PilhaX]++;
    } else
        printf("Pilha Cheia");
}

int pop(struct PilhaMultp *PM, int *elemento, int PilhaX) {
    if (!PilhaXVazia(PM, PilhaX)) {
        PM->topo[PilhaX]--;
        *elemento = PM->P[PM->topo[PilhaX]];
    } else
        printf("Pilha Vazia");
}

int main(void) {
    int i, PilhaX, elemR;
    struct PilhaMultp P1;
    InicializaPilhas(&P1);

    //---------Inserindo elementos na pilha------//
    push(&P1, 15, 2);
    push(&P1, 5, 0);
    push(&P1, 22, 1);
    push(&P1, 41, 1);
    push(&P1, 11, 0);
    push(&P1, 18, 0);
    push(&P1, 7, 0);
    push(&P1, 13, 1);
    push(&P1, 14, 2);
    pop(&P1, &elemR, 0);
    printf("\n Removi o elemento: %d", elemR);
    push(&P1, 33, 1);
    push(&P1, 9, 0);
    push(&P1, 19, 0);
    pop(&P1, &elemR, 1);
    printf("\n Removi o elemento: %d", elemR);

    printf("\n      RESULTADO FINAL: \n");
    printf("      ");
    for (i = 0; i < MAX; i++)
        printf("  %d", P1.P[i]);
    for (i = 0; i < NPilha; i++) {
        printf("\n      BASE[%d]:%2.d", i, P1.base[i]);
        printf("      TOPO[%d]:%2.d", i, P1.topo[i]);
    }
    return (0);
}