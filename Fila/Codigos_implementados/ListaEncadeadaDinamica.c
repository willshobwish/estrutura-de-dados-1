#include <stdio.h>
#include <stdlib.h>

// Os nos que sao armazenados em fila
struct noFila {
    int elemento;
    struct noFila *prox;
};

// Descritor da fila
typedef struct{
    // Um no que aponta para o inicio
    struct noFila *inicio;
    // Um no que aponta para o final da fila
    struct noFila *fim;
} Fila;

void inicializacao(Fila *fila) {
    // O no que aponta para o inicio e final inicializados com null
    fila->inicio = NULL;
    fila->fim = NULL;
}

short vazia(Fila *fila) {  
    // Verifica se a fila esta vazia
    // Caso o ponteiro para o inicio seja null significa que esta vazio
    if (fila->inicio == NULL)
        return 1;
    else
        return 0;
}

// o código da função fila cheia pode ser inserido na função inserir
short cheia(Fila *fila) {  // a fila estará cheia quando não houver memória para ser alocada
    struct noFila *novoNo;
    novoNo = malloc(sizeof(struct noFila));
    // malloc retorna null quando não houver memória disponível para alocação ou quando ocorrer algum erro durante a alocação - execução do malloc
    if (novoNo == NULL)
        return 1;
    else
        return 0;
}

void inserir(Fila *fila, int elemento) {
    struct noFila *novoNo;
    // Alocando espaco em memoria e devolvendo um ponteiro
    novoNo = malloc(sizeof(struct noFila));
    // Caso o novo ponteiro seja null, isso quer dizer que a alocacao falhou
    if (novoNo == NULL)
        printf("Fila Cheia!!!");
    // Caso contrario 
    else {
        // Define o elemento para o novo ponteiro 
        novoNo->elemento = elemento;
        // O novo ponteiro aponta para null
        novoNo->prox = NULL;
        // Caso ao fila esteja vazia
        if (vazia(fila))
        // E inserido no comeco sem a necessidade de apontar o final anterior para o novo
            fila->inicio = novoNo;
        else
        // Caso ja possua elementos
        // O final anterior aponta para o novo elemento
            fila->fim->prox = novoNo;
        // Independente, o ponteiro para o final aponta para o novo elemento inserido
        fila->fim = novoNo;
    }
}

void remover(Fila *fila, int *elemento) {
    // Utiliza o endereco do descritor e retorna por parametro o elemento removido
    struct noFila *aux;
    // Checa se a fila possui elementos
    if (vazia(fila))
        printf("Fila Vazia - Não há elementos para remover!!!");
    else {
        // Caso tenha elementos
        // O auxiliar pega o endereco do inicio da fila atraves do descritor
        aux = fila->inicio;
        *elemento = aux->elemento;
        // O inicio da fila eh o inicio da fila proxima
        fila->inicio = fila->inicio->prox;
        // Liberacao do espaco alocado para o elemento anterior
        free(aux);
    }
}

// Retorna o elemento que está no inicio da fila
void obterIncioFila(Fila *fila, int *elemento) {
    if (vazia(fila))
        printf("Fila Vazia - Não há elementos na fila!!!");
    else
        *elemento = fila->inicio->elemento;
}

int main(void) {
    int elemIni, elemRem;
    struct noFila *i = NULL;
    Fila F1;
    inicializacao(&F1);
    if (vazia(&F1))
        printf("\nFila vazia!");

    // Inserindo valores na fila
    inserir(&F1, 1);
    inserir(&F1, 1);
    inserir(&F1, 2);
    inserir(&F1, 3);
    inserir(&F1, 5);
    inserir(&F1, 8);
    inserir(&F1, 13);
    inserir(&F1, 21);
    inserir(&F1, 34);
    inserir(&F1, 55);
    printf("\nInseri 10 elementos!");

    // Imprimindo a fila
    printf("\nInicio (valor elem): %d", F1.inicio->elemento);
    printf("\nFim (valor elem): %d\n", F1.fim->elemento);
    for (i = F1.inicio; i != NULL; i = i->prox)
        printf("%d ", i->elemento);

    obterIncioFila(&F1, &elemIni);
    printf("\nElemento do inicio: %d", elemIni);

    remover(&F1, &elemRem);
    printf("\nRemovi o elemento: %d", elemRem);
    remover(&F1, &elemRem);
    printf("\nRemovi o elemento: %d", elemRem);
    remover(&F1, &elemRem);
    printf("\nRemovi o elemento: %d", elemRem);
    remover(&F1, &elemRem);
    printf("\nRemovi o elemento: %d", elemRem);

    inserir(&F1, 89);

    // Imprimindo a fila
    printf("\nInicio (valor elem): %d", F1.inicio->elemento);
    printf("\nFim (valor elem): %d\n", F1.fim->elemento);
    for (i = F1.inicio; i != NULL; i = i->prox)
        printf("%d ", i->elemento);

    return (0);
}