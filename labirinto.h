// IAN RIBEIRO DE OLIVEIRA

#ifndef LABIRINTO
#define LABIRINTO

#include <stdio.h>
int labirinto[101][101];
int tamanho;

/*
Verifica se foi possível abrir/acessar o arquivo f
Entrada: referencia para o arquivo f e o nome do arquivo
Saída: retorna 0 se não foi possível abrir o arquivo
*/ 
int verificarArquivo(FILE *f, char *arquivo);

/*
Gera um labarinto de tamanho n x n
Entrada: tamanho n e probabilidade p de a uma célula ser parede
Saída: arquivo "labirinto.txt" com o labirinto gerado
*/ 
void gerarLabirinto(int n, int p);

/*
Processa o labarinto no arquivo "labirinto.txt"
Entrada: nenhuma
Saída: nenhuma
*/ 
void processarLabirinto();
void apresentarFiguras();
void menorCaminho();

#endif