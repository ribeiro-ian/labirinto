// IAN RIBEIRO DE OLIVEIRA

#include "./includes/filae.h"
#include "labirinto.h"

void anotar(labirinto *lab){
  fila *linha = fila_criar(), *coluna = fila_criar();
  const int TAM = lab->tamanho;

  if (lab->matriz[1][1] == 0){
    fila_inserir(linha, 1);
    fila_inserir(coluna, 1);
    lab->matriz[1][1] = 1;
  }

  while (!fila_vazia(linha) && !fila_vazia(coluna)){
    int x = fila_frente(linha);
    int y = fila_frente(coluna);

    int posX[] = {x+1, x-1};
    int posY[] = {y+1, y-1};

    for (int i = 0; i < 2; i++){
      int lin = posX[i];

      if (lin >= 0 && lin < TAM && lab->matriz[lin][y] == 0){
        lab->matriz[lin][y] = lab->matriz[x][y] + 1;
        fila_inserir(linha, lin);
        fila_inserir(coluna, y);
      }
    }

    for (int i = 0; i < 2; i++){
      int col = posY[i];

      if (col >= 0 && col < TAM && lab->matriz[x][col] == 0){
        lab->matriz[x][col] = lab->matriz[x][y] + 1;
        fila_inserir(linha, x);
        fila_inserir(coluna, col);
      }
    }

    fila_remover(linha);
    fila_remover(coluna);
  }
  
  fila_liberar(&linha);
  fila_liberar(&coluna);
}

void anotarLabirinto(labirinto *lab){
  FILE *a, *b, *c;
  const int TAM = lab->tamanho;

  /* ========== Figura A ========== */
  a = fopen("F2a.txt", "w");
  
  if (!verificarArquivo(a, "F2a")) return;

  for (int i = 0; i < TAM; i++){
    for (int j = 0; j < TAM; j++){
      int num = lab->matriz[i][j];
      char c = (num == -1 ? '#' : ' ');

      fprintf(stdout, "%3c", c);
      fprintf(a, "%3c", c);
    }
    fprintf(stdout, "\n");
    fprintf(a, "\n");
  }
  fprintf(stdout, "\n");

  fclose(a);

  /* ========== Figura B ========== */
  b = fopen("F2b.txt", "w");
  
  if (!verificarArquivo(b, "F2b")) return;
  
  for (int i = 0; i < TAM; i++){
    for (int j = 0; j < TAM; j++){
      fprintf(stdout, "%3d", lab->matriz[i][j]);
      fprintf(b, "%3d", lab->matriz[i][j]);
    }
    fprintf(stdout, "\n");
    fprintf(b, "\n");
  }
  fprintf(stdout, "\n");

  fclose(b);

  /* ========== Figura C ========== */
  c = fopen("F2c.txt", "w");
  
  if (!verificarArquivo(c, "F2c")) return;

  anotar(lab);

  for (int i = 0; i < TAM; i++){
    for (int j = 0; j < TAM; j++){
      fprintf(stdout, "%4d", lab->matriz[i][j]);
      fprintf(c, "%4d", lab->matriz[i][j]);
    }
    fprintf(stdout, "\n");
    fprintf(c, "\n");
  }
  fprintf(stdout, "\n");

  fclose(c);

}