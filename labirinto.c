// IAN RIBEIRO DE OLIVEIRA

#include <stdio.h>
#include "labirinto.h"

int main(){
  int n, p;
  labirinto l;

  fprintf(stdout, "Insira o tamanho N do labirinto: \n");
  fscanf(stdin, "%i", &n);

  fprintf(stdout, "Insira a probabilidade P de uma celula ser parede: \n");
  fscanf(stdin, "%i", &p);

  gerarLabirinto(n, p);

  processarLabirinto(&l);

  // apresentarFiguras();
  // menorCaminho();

  return 0;
}