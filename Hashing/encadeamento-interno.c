#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15

struct aluno {
    int matricula;
    char nome[80];
    char email[80];
    int proximo;
};

struct tabela{
    struct aluno alunos [MAX];
    int primeiraColisao;
};

typedef struct tabela tabela;
typedef struct aluno aluno;

void inicializa(tabela *tabela){
    tabela->primeiraColisao=7;
    for(int i=0;i<MAX;i++){
        tabela->alunos[i].proximo=-1;
    }
}

int hash(int matricula) {
    return (matricula % 101) % MAX;
}

int main(void){
    return 0;
}