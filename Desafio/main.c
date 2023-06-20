#include <stdio.h>
#include <string.h>
#define MAX 256
#define MAXALOCACAO 10
typedef struct {
    char ID[50];
    char rodata[50];
    char data[50];
    char hora[50];
    char mandante[50];
    char visitante[50];
    char formacao_mandante[50];
    char formacao_visitante[50];
    char tecnico_mandante[50];
    char tecnico_visitante[50];
    char vencedor[50];
    char arena[50];
    char mandante_Placar[50];
    char visitante_Placar[50];
    char mandante_Estado[50];
    char visitante_Estado[50];
} dados;

int main() {
    dados novo[10];
    int index=0;
    char *filename = "arquivo.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s", filename);
        return 1;
    }
    char buffer[MAX];
    while (!feof(fp)) {
        int atribuicao = 0, indexBuffer = 0, indexCpy = 0;
        char atribuicaoDescricao[80];
        fgets(buffer, MAX, fp);
        if(index<MAXALOCACAO){
        for (int letras = 0; letras < strlen(buffer); letras++) {
            if (buffer[letras] == ','||buffer[letras]=='\n') {
                switch (atribuicao) {
                    case 0:
                        strcpy(novo[index].ID, atribuicaoDescricao);
                        break;
                    
                    case 1:
                        strcpy(novo[index].rodata, atribuicaoDescricao);
                        break;
                    
                    case 2:
                        strcpy(novo[index].data, atribuicaoDescricao);
                        break;
                    
                    case 3:
                        strcpy(novo[index].hora, atribuicaoDescricao);
                        break;
                    
                    case 4:
                        strcpy(novo[index].mandante, atribuicaoDescricao);
                        break;
                    
                    case 5:
                        strcpy(novo[index].visitante, atribuicaoDescricao);
                        break;
                    
                    case 6:
                        strcpy(novo[index].formacao_mandante, atribuicaoDescricao);
                        break;
                    
                    case 7:
                        strcpy(novo[index].formacao_visitante, atribuicaoDescricao);
                        break;
                    
                    case 8:
                        strcpy(novo[index].tecnico_mandante, atribuicaoDescricao);
                        break;
                    
                    case 9:
                        strcpy(novo[index].tecnico_visitante, atribuicaoDescricao);
                        break;
                   
                    case 10:
                        strcpy(novo[index].vencedor, atribuicaoDescricao);
                        break;
                    
                    case 11:
                        strcpy(novo[index].arena, atribuicaoDescricao);
                        break;
                    
                    case 12:
                        strcpy(novo[index].mandante_Placar, atribuicaoDescricao);
                        break;
                    
                    case 13:
                        strcpy(novo[index].visitante_Placar, atribuicaoDescricao);
                        break;
                    
                    case 14:
                        strcpy(novo[index].mandante_Estado, atribuicaoDescricao);
                        break;
                    
                    case 15:
                        strcpy(novo[index].visitante_Estado, atribuicaoDescricao);
                        break;
                }
                atribuicao++;
                indexBuffer++;
                indexCpy = 0;
                memset(atribuicaoDescricao, NULL, 70);
            } else {
                atribuicaoDescricao[indexCpy] = buffer[indexBuffer];
                indexCpy++;
                indexBuffer++;
            }
        }
        index++;}
    }

    fclose(fp);

    for(int valor=0;valor<MAXALOCACAO;valor++){
    printf("\n ID: %s\n rodata: %s\n data: %s\n hora: %s\n mandante: %s\n visitante: %s\n formacao_mandante: %s\n formacao_visitante: %s\n tecnico_mandante: %s\n tecnico_visitante: %s\n vencedor: %s\n arena: %s\n mandante_Placar: %s\n visitante_Placar: %s\n mandante_Estado: %s\n visitante_Estado: %s", novo[valor].ID, novo[valor].rodata, novo[valor].data, novo[valor].hora, novo[valor].mandante, novo[valor].visitante, novo[valor].formacao_mandante, novo[valor].formacao_visitante, novo[valor].tecnico_mandante, novo[valor].tecnico_visitante, novo[valor].vencedor, novo[valor].arena, novo[valor].mandante_Placar, novo[valor].visitante_Placar, novo[valor].mandante_Estado, novo[valor].visitante_Estado);
    printf("\n--------------------------------------");
    
    }
    FILE *arquivobinario = fopen("testestruct.bin","wb");
    dados a = novo[3];
    fwrite(&a,sizeof(dados),1,arquivobinario);
    fclose(arquivobinario);
    arquivobinario = fopen("testestruct.bin","rb");
    dados b;
    fread(&b,sizeof(dados),1,arquivobinario);
    printf(" \nLeitura de arquivo binario\n ID: %s\n rodata: %s\n data: %s\n hora: %s\n mandante: %s\n visitante: %s\n formacao_mandante: %s\n formacao_visitante: %s\n tecnico_mandante: %s\n tecnico_visitante: %s\n vencedor: %s\n arena: %s\n mandante_Placar: %s\n visitante_Placar: %s\n mandante_Estado: %s\n visitante_Estado: %s", b.ID, b.rodata, b.data, b.hora, b.mandante, b.visitante, b.formacao_mandante, b.formacao_visitante, b.tecnico_mandante, b.tecnico_visitante, b.vencedor, b.arena, b.mandante_Placar, b.visitante_Placar, b.mandante_Estado, b.visitante_Estado);
    return 0;
}