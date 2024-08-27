// IAN RIBEIRO DE OLIVEIRA

#include "labirinto.h"
#include <stdio.h>
#include "./includes/pilhae.h"

#define VERMELHO "\e[0;31m"
#define VERDE "\e[0;32m"
#define RESETAR_COR "\e[0m"

void vermelho(){
  fprintf(stdout, VERMELHO);
}
void verde(){
  fprintf(stdout, VERDE);
}
void resetar_cor(){
  fprintf(stdout, RESETAR_COR);
}

char lab[101][101];

void extrair(){
  pilha lin, col;
  pilha_inicializar(&lin); pilha_inicializar(&col);
  
  pilha_inserir(&lin, tamanho-2); pilha_inserir(&col, tamanho-2);
    
  while (1){
    int x, y; 
    x = pilha_topo(&lin);
    y = pilha_topo(&col);

    lab[x][y] = 'X';
    if (x == 1 && y == 1) break;

    int posX[] = {x+1, x-1};
    int posY[] = {y+1, y-1};

    for (int i = 0; i < 2; i++)
      if (posX[i] >= 0 && posX[i] < tamanho
      && labirinto[posX[i]][y] == labirinto[x][y]-1){
        pilha_inserir(&lin, posX[i]);
        pilha_inserir(&col, y);
      }

    for (int i = 0; i < 2; i++)
      if (posY[i] >= 0 && posY[i] < tamanho
      && labirinto[x][posY[i]] == labirinto[x][y]-1){
        pilha_inserir(&lin, x);
        pilha_inserir(&col, posY[i]);
      }
  }

  pilha_liberar(&lin);
  pilha_liberar(&col);
}

void menorCaminho(){
  if (labirinto[tamanho-2][tamanho-2] <= 0){
    fprintf(stdout, "Nao existe caminho!\n");
    return;
  }

  FILE *f;
  f = fopen("F3b.txt", "w");
  if (!verificarArquivo(f, "F3b"))
    return;

  for (int i = 0; i < tamanho; i++)
    for (int j = 0; j < tamanho; j++)
      if (labirinto[i][j] == -1)
        lab[i][j] = '#';
      else
        lab[i][j] = ' ';

  extrair();

  for (int i = 0; i < tamanho; i++){
    for (int j = 0; j < tamanho; j++){
      if ((i == 1 && j == 0) || (i == tamanho-2 && j == tamanho-1))
        verde();
      else if (lab[i][j]=='X')
        vermelho();
      
      fprintf(stdout, "%3c", lab[i][j]);
      fprintf(f, "%3c", lab[i][j]);

      resetar_cor();
    }
    fprintf(stdout, "\n");
    fprintf(f, "\n");
  }
  fprintf(stdout, "\n");

  fclose(f);
}