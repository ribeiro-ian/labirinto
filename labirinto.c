// IAN RIBEIRO DE OLIVEIRA

#include <stdio.h>
#include "labirinto.h"

int verificarArquivo(FILE *f, char* arquivo){
  if (!f){
    fprintf(stderr, "Erro ao abrir o arquivo %s.txt!\n", arquivo);
    return 0;
  }
  
  return 1;
}

int main(){
  int n, p;

  fscanf(stdin, "%i %i", &n, &p);

  // gerarLabirinto(n, p);
  processarLabirinto();
  apresentarFiguras();
  menorCaminho();

  return 0;
}