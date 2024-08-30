/* Ian Ribeiro de Oliveira */

#include "labirinto.h"
#include "./includes/pilhae.h"

void vermelho(){
  fprintf(stdout, "\e[0;31m");
}
void verde(){
  fprintf(stdout, "\e[0;32m");
}
void resetar_cor(){
  fprintf(stdout, "\e[0m");
}

void extrair(labirinto *lab, const int TAM, char labChar[TAM][TAM]){
  pilha *lin = pilha_criar(), *col = pilha_criar();

  pilha_inserir(lin, TAM-2);
  pilha_inserir(col, TAM-2);
    
  while (1){
    int x, y; 
    x = pilha_topo(lin);
    y = pilha_topo(col);

    labChar[x][y] = 'X';
    if (x == 1 && y == 1) break;

    int posX[] = {x+1, x-1};
    int posY[] = {y+1, y-1};

    for (int i = 0; i < 2; i++)
      if (posX[i] >= 0 && posX[i] < TAM &&
      lab->matriz[posX[i]][y] == lab->matriz[x][y]-1){
        pilha_inserir(lin, posX[i]);
        pilha_inserir(col, y);
      }

    for (int i = 0; i < 2; i++)
      if (posY[i] >= 0 && posY[i] < TAM &&
      lab->matriz[x][posY[i]] == lab->matriz[x][y]-1){
        pilha_inserir(lin, x);
        pilha_inserir(col, posY[i]);
      }
  }

  pilha_liberar(&lin);
  pilha_liberar(&col);
}

void procurarMenorCaminho(labirinto *lab){
  const int TAM = lab->tamanho;
  
  if (lab->matriz[TAM-2][TAM-2] <= 0){
    fprintf(stdout, "Nao existe caminho!\n");
    return;
  }

  FILE *f;
  f = fopen("F3b.txt", "w");
  verificarArquivo(f, "F3b");

  char labirintoChar[TAM][TAM];
  // Preencher celulas do labirinto de caracteres
  for (int i = 0; i < TAM; i++)
    for (int j = 0; j < TAM; j++)
      if (lab->matriz[i][j] == -1)
        labirintoChar[i][j] = '#';
      else
        labirintoChar[i][j] = ' ';

  extrair(lab, TAM, labirintoChar);

  for (int i = 0; i < TAM; i++){
    for (int j = 0; j < TAM; j++){
      if ((i == 1 && j == 0) || (i == TAM-2 && j == TAM-1))
        verde();
      else if (labirintoChar[i][j]=='X')
        vermelho();
      
      fprintf(stdout, "%3c", labirintoChar[i][j]);
      fprintf(f, "%3c", labirintoChar[i][j]);

      resetar_cor();
    }
    fprintf(stdout, "\n");
    fprintf(f, "\n");
  }
  fprintf(stdout, "\n");

  fclose(f);
}