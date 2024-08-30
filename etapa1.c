/* Ian Ribeiro de Oliveira */

#include <stdlib.h>
#include <time.h>
#include "labirinto.h"

void verificarArquivo(FILE *f, char* arquivo){
  if (!f){
    fprintf(stderr, "Erro ao abrir o arquivo %s.txt!\n", arquivo);
    exit(EXIT_FAILURE);
  }
}

char criarCelula(int p){
  int x = rand() % 100 + 1;

  return (x <= p ? '#' : '.');
}

void gerarLabirinto(int n, int p){
  srand(time(NULL));

  // Criar arquivo
  FILE *l;

  l = fopen("./labirinto.txt", "w");
  verificarArquivo(l, "labirinto");

  // Gerar labirinto
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (i == 0 || i == n-1 || j == 0 || j == n-1)
        fprintf(l, "#");
      else
        fprintf(l, "%c", criarCelula(p));
    }
    fprintf(l, "\n");
  }

  fclose(l);
}