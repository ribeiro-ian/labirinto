/* Ian Ribeiro de Oliveira */

#include "labirinto.h"

void processarLabirinto(labirinto *lab){

  FILE *f;
  f = fopen("./labirinto.txt", "r");
  verificarArquivo(f, "labirinto");

  // Ler Labirinto
  char s[MAXN];
  int x, y = 0;
  while ( fscanf(f, "%s", s) != EOF ){
    x = 0;
    
    while (s[x] != '\0'){
      if (s[x] == '#')
        lab->matriz[y][x] = -1;

      else
        lab->matriz[y][x] = 0;

      x++;
    }
    y++;
  }
  lab->tamanho = y;

  fclose(f);
}