#include <stdio.h>
#include <stdlib.h>

// tipoelem = int
struct nodeQueue {
    int elemento;
    int prioridade;
    struct nodeQueue *proximo;
};

// Descritor
typedef struct {
    struct nodeQueue *inicio;
    struct nodeQueue *fim;
} FilaPrioridade;

void inicializacao(FilaPrioridade *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

short vazia(FilaPrioridade *fila) {  // verifica se a fila está vazia
    if (fila->inicio == NULL)
        return 1;
    else
        return 0;
}

// a código da função fila cheia pode ser inserido na função inserir
short cheia(FilaPrioridade *fila) {  // a fila estará cheia quando não houver memória para ser alocada
    struct nodeQueue *newNode;
    newNode = malloc(sizeof(struct nodeQueue));
    // malloc retorna null quando não houver memória disponível para alocação ou quando ocorrer algum erro durante a alocação - execução do malloc
    if (newNode == NULL)
        return 1;
    else
        return 0;
}

void inserir(FilaPrioridade *fila, int elemento, int prioridade) {  // inserção ordenada
    struct nodeQueue *newNode, *aux, *anterior;
    newNode = malloc(sizeof(struct nodeQueue));
    if (newNode == NULL)
        printf("Fila Cheia!!!");
    else {
        newNode->proximo = NULL;
        newNode->prioridade = prioridade;
        newNode->elemento = elemento;
        aux = fila->inicio;
        anterior = NULL;
        // Percorre a fila enquanto o auxiliar nao for nulo e a prioridade for maior 
        // A prioridade eh decrescente 
        while ((aux != NULL) && (aux->prioridade >= prioridade)) {
            anterior = aux;
            aux = aux->proximo;
        }
        if (aux != NULL) {
            if (anterior == NULL) {
                newNode->proximo = fila->inicio;
                fila->inicio = newNode;
            } else {
                newNode->proximo = aux;
                anterior->proximo = newNode;
            }
        } else {
            // Caso a fila seja vazia
            if (anterior == NULL)  
                fila->inicio = newNode;
            else 
                fila->fim->proximo = newNode;
            fila->fim = newNode;
        }
    }
}

void remover(FilaPrioridade *fila, int *elemento, int *prioridade) {
    struct nodeQueue *aux;
    if (vazia(fila))
        printf("Fila Vazia - Não há elementos para remover!!!");
    else {
        aux = fila->inicio;
        *elemento = aux->elemento;
        *prioridade = aux->prioridade;
        fila->inicio = fila->inicio->proximo;
        free(aux);
    }
}

void selecao(FilaPrioridade *fila, int *elemento) {
    if (vazia(fila))
        printf("Fila Vazia - Não há elementos na fila!!!");
    else
        *elemento = fila->inicio->elemento;
}
// Retorna o elemento que está no inicio da fila

void imprimir(FilaPrioridade *fila) {
    struct nodeQueue *aux = fila->inicio;
    while (aux!=NULL){
        printf("Prioridade: %d Elemento: %d\n",aux->prioridade,aux->elemento);
        aux=aux->proximo;
    }
}

int main(void) {
    int elemIni, elemRem, prioRem;
    struct nodeQueue *i = NULL;
    FilaPrioridade F1;
    inicializacao(&F1);
    if (vazia(&F1))
        printf("\nFila vazia!");

    // Inserindo valores na fila
    inserir(&F1, 1, 4);
    inserir(&F1, 1, 6);
    inserir(&F1, 2, 3);
    inserir(&F1, 3, 5);
    inserir(&F1, 5, 5);
    printf("\nInseri 5 elementos!");

    // Imprimindo a fila
    printf("\nInicio (valor elem): %d", F1.inicio->elemento);
    printf("\nFim (valor elem): %d\n", F1.fim->elemento);
    for (i = F1.inicio; i != NULL; i = i->proximo)
        printf("%d ", i->elemento);

    selecao(&F1, &elemIni);
    printf("\nElemento do inicio: %d", elemIni);

    remover(&F1, &elemRem, &prioRem);
    printf("\nRemovi o elemento: %d com prioridade %d", elemRem, prioRem);
    remover(&F1, &elemRem, &prioRem);
    printf("\nRemovi o elemento: %d com prioridade %d", elemRem, prioRem);

    inserir(&F1, 89, 1);

    // Imprimindo a fila
    printf("\nInicio (valor elem): %d", F1.inicio->elemento);
    printf("\nFim (valor elem): %d\n", F1.fim->elemento);
    for (i = F1.inicio; i != NULL; i = i->proximo)
        printf("%d ", i->elemento);

    imprimir(&F1);
    return (0);
}