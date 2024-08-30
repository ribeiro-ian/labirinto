// IAN RIBEIRO DE OLIVEIRA

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
  FILE *labirinto;
  labirinto = fopen("./labirinto.txt", "w");

  verificarArquivo(labirinto, "labirinto");

  // Gerar labirinto
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (i == 0 || i == n-1 || j == 0 || j == n-1)
        fprintf(labirinto, "#");
      else
        fprintf(labirinto, "%c", criarCelula(p));
    }
    fprintf(labirinto, "\n");
  }

  fclose(labirinto);
}