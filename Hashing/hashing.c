#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

struct aluno {
    int matricula;
    char nome[80];
    char email[40];
};
typedef struct aluno aluno;

void inicializa_tabela_hash(aluno *tabela) {
    for (int i = 0; i < MAX; i++) {
        tabela[i].matricula = -1;
    }
}
int hash(int matricula) {
    return (matricula% 101) % MAX;
}

void inserir(aluno *tabela, aluno elemento) {
    int chave = hash(elemento.matricula);
    tabela[chave] = elemento;
};

void remocao(aluno *tabela, int matricula){
    int chave = hash(matricula);
    if(tabela[chave].matricula==matricula){
        tabela[chave].matricula=-1;
        strcpy(tabela[chave].email,"");
        strcpy(tabela[chave].nome,"");
    }else{
        printf("Matricula nao existente\n");
    }
}

void busca(aluno *tabela, int matricula){
    int chave=hash(matricula);
    if(tabela[chave].matricula==matricula){
        printf("Matricula: %d\nEmail: %s\nNome: %s\n",tabela[chave].matricula,tabela[chave].email,tabela[chave].nome);
    }else{
        printf("Matricula nao encontrada\n");
    }
}

void imprimir(aluno *tabela) {
    for (int i = 0; i < MAX; i++) {
        if (tabela[i].matricula != -1) {
            printf("%d %3d %s %s\n", i, tabela[i].matricula, tabela[i].email, tabela[i].nome);
        } else {
            printf("%d --- Vazio\n", i);
        }
    }printf("\n");
}

aluno insere_informacoes(int matricula,char email[],char nome[]){
    aluno novo;
    novo.matricula = matricula;
    strcpy(novo.email,email);
    strcpy(novo.nome,nome);
    return novo;
}
int main(void) {
    aluno tabHash[MAX], a;
    inicializa_tabela_hash(&tabHash);
    inserir(&tabHash, insere_informacoes(230,"email@teste.com","nome teste"));
    inserir(&tabHash, insere_informacoes(23,"email@teste2.com","nome teste 2"));
    imprimir(&tabHash);
    remocao(&tabHash,230);
    imprimir(&tabHash);
    busca(&tabHash,23);
}