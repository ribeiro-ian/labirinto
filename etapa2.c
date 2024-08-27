// IAN RIBEIRO DE OLIVEIRA

#include <stdio.h>
#include "labirinto.h"

void processarLabirinto(){
  FILE *f;
  f = fopen("./labirinto.txt", "r");
  
  if (!verificarArquivo(f, "labirinto"))
    return;
  
  // Ler Labirinto
  char s[1001];
  int x, y = 0;
  while ( fscanf(f, "%s", s) != EOF ){
    x = 0;
    
    while (s[x] != '\0'){
      if (s[x] == '#')
        labirinto[y][x] = -1;

      else
        labirinto[y][x] = 0;

      x++;
    }
    y++;
  }
  tamanho = y;

  fclose(f);
}