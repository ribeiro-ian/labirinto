// IAN RIBEIRO DE OLIVEIRA

#include "./includes/filae.h"
#include "labirinto.h"

void anotar(){
  fila lin, col;
  fila_inicializar(&lin);
  fila_inicializar(&col);

  if (lab->dadosInteiros[1][1] == 0){
    fila_inserir(&lin, 1);
    fila_inserir(&col, 1);
    lab->dadosInteiros[1][1] = 1;
  }

  while (!fila_vazia(&lin)){
    int x = fila_frente(&lin);
    int y = fila_frente(&col);

    int posX[] = {x+1, x-1};
    int posY[] = {y+1, y-1};

    for (int i = 0; i < 2; i++){
      if (posX[i] >= 0 && posX[i] < lab->tamanho && lab->dadosInteiros[posX[i]][y] == 0){
        lab->dadosInteiros[posX[i]][y] = lab->dadosInteiros[x][y] + 1;
        fila_inserir(&lin, posX[i]);
        fila_inserir(&col, y);
      }
    }

    for (int i = 0; i < 2; i++){
      if (posY[i] >= 0 && posY[i] < lab->tamanho && lab->dadosInteiros[x][posY[i]] == 0){
        lab->dadosInteiros[x][posY[i]] = lab->dadosInteiros[x][y] + 1;
        fila_inserir(&lin, x);
        fila_inserir(&col, posY[i]);
      }
    }

    fila_remover(&lin);
    fila_remover(&col);
  }
  
  fila_liberar(&lin);
  fila_liberar(&col);
}

void apresentarFiguras(labirinto *lab){
  FILE *a, *b, *c;

  /* ========== Figura A ========== */
  a = fopen("F2a.txt", "w");
  
  if (!verificarArquivo(a, "F2a")) return;

  for (int i = 0; i < lab->tamanho; i++){
    for (int j = 0; j < lab->tamanho; j++){
      int num = lab->dados[i][j];
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
  
  for (int i = 0; i < lab->tamanho; i++){
    for (int j = 0; j < lab->tamanho; j++){
      fprintf(stdout, "%3d", lab->dados[i][j]);
      fprintf(b, "%3d", lab->dados[i][j]);
    }
    fprintf(stdout, "\n");
    fprintf(b, "\n");
  }
  fprintf(stdout, "\n");

  fclose(b);

  /* ========== Figura C ========== */
  c = fopen("F2c.txt", "w");
  
  if (!verificarArquivo(c, "F2c")) return;
  
  anotar();
  
  for (int i = 0; i < lab->tamanho; i++){
    for (int j = 0; j < lab->tamanho; j++){
      fprintf(stdout, "%4d", lab->dados[i][j]);
      fprintf(c, "%4d", lab->dados[i][j]);
    }
    fprintf(stdout, "\n");
    fprintf(c, "\n");
  }
  fprintf(stdout, "\n");

  fclose(c);
}