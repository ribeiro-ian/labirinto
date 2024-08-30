// IAN RIBEIRO DE OLIVEIRA

#include <stdio.h>
#include "labirinto.h"

int main(){
  int n, p;
  labirinto l;

  fprintf(stdout, "Insira o tamanho N (um inteiro de 7 a 100) do labirinto: \n");
  fscanf(stdin, "%i", &n);

  fprintf(stdout, "Insira a probabilidade P (um inteiro de 10 a 80) de uma celula ser parede: \n");
  fscanf(stdin, "%i", &p);

  gerarLabirinto(n, p);
  processarLabirinto(&l);
  anotarLabirinto(&l);
  menorCaminho(&l);

  return 0;
}