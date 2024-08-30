/* Ian Ribeiro de Oliveira */

#ifndef LABIRINTO
#define LABIRINTO

#include <stdio.h>
#define MAXN 101

typedef struct labirinto{
  int matriz[MAXN][MAXN];
  int tamanho;
} labirinto;

/*
Verifica se foi possível abrir/acessar o arquivo f
Entrada: referência para o arquivo f e o nome do arquivo
Saída: fecha o programa caso não seja possível acessar o arquivo f
*/ 
void verificarArquivo(FILE *f, char *arquivo);

/*
Gera um labarinto de tamanho n x n
Entrada: tamanho n e probabilidade p de a uma célula ser parede
Saída: arquivo "labirinto.txt" com o labirinto gerado
*/ 
void gerarLabirinto(int n, int p);

/*
Processa o labarinto no arquivo "labirinto.txt"
Entrada: a estrutura labirinto lab
Saída: nenhuma
*/ 
void processarLabirinto(labirinto *lab);

/*
Anota a distância entre cada célula e a entrada do labirinto
Entrada: a estrutura labirinto lab
Saída: nenhuma
*/ 
void anotarLabirinto(labirinto *lab);

/*
Processa o labarinto no arquivo "labirinto.txt"
Entrada: a estrutura labirinto lab
Saída: nenhuma
*/ 
void procurarMenorCaminho(labirinto *lab);

#endif