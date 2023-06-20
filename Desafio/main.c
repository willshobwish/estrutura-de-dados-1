#include <stdio.h>
#include <string.h>
#define MAX 256
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
    dados novo;
    char *filename = "arquivo.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s", filename);
        return 1;
    }
    char buffer[MAX];
    while (!feof(fp)) {
        int atribuicao = 0, indexBuffer = 0, indexCpy = 0;
        char atribuicaoDescricao[70];
        fgets(buffer, MAX, fp);
        for (int letras = 0; letras < strlen(buffer); letras++) {
            if (buffer[letras] == ','||buffer[letras]=='\n') {
                switch (atribuicao) {
                    case 0:
                        strcpy(novo.ID, atribuicaoDescricao);
                        break;
                    
                    case 1:
                        strcpy(novo.rodata, atribuicaoDescricao);
                        break;
                    
                    case 2:
                        strcpy(novo.data, atribuicaoDescricao);
                        break;
                    
                    case 3:
                        strcpy(novo.hora, atribuicaoDescricao);
                        break;
                    
                    case 4:
                        strcpy(novo.mandante, atribuicaoDescricao);
                        break;
                    
                    case 5:
                        strcpy(novo.visitante, atribuicaoDescricao);
                        break;
                    
                    case 6:
                        strcpy(novo.formacao_mandante, atribuicaoDescricao);
                        break;
                    
                    case 7:
                        strcpy(novo.formacao_visitante, atribuicaoDescricao);
                        break;
                    
                    case 8:
                        strcpy(novo.tecnico_mandante, atribuicaoDescricao);
                        break;
                    
                    case 9:
                        strcpy(novo.tecnico_visitante, atribuicaoDescricao);
                        break;
                   
                    case 10:
                        strcpy(novo.vencedor, atribuicaoDescricao);
                        break;
                    
                    case 11:
                        strcpy(novo.arena, atribuicaoDescricao);
                        break;
                    
                    case 12:
                        strcpy(novo.mandante_Placar, atribuicaoDescricao);
                        break;
                    
                    case 13:
                        strcpy(novo.visitante_Placar, atribuicaoDescricao);
                        break;
                    
                    case 14:
                        strcpy(novo.mandante_Estado, atribuicaoDescricao);
                        break;
                    
                    case 15:
                        strcpy(novo.visitante_Estado, atribuicaoDescricao);
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
    }

    fclose(fp);
    printf(" ID: %s\n rodata: %s\n data: %s\n hora: %s\n mandante: %s\n visitante: %s\n formacao_mandante: %s\n formacao_visitante: %s\n tecnico_mandante: %s\n tecnico_visitante: %s\n vencedor: %s\n arena: %s\n mandante_Placar: %s\n visitante_Placar: %s\n mandante_Estado: %s\n visitante_Estado: %s", novo.ID, novo.rodata, novo.data, novo.hora, novo.mandante, novo.visitante, novo.formacao_mandante, novo.formacao_visitante, novo.tecnico_mandante, novo.tecnico_visitante, novo.vencedor, novo.arena, novo.mandante_Placar, novo.visitante_Placar, novo.mandante_Estado, novo.visitante_Estado);
    return 0;
}