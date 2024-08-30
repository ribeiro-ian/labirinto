// IAN RIBEIRO DE OLIVEIRA

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

  /* TESTE
  fprintf(stderr, "tamanho do labirinto: %i\n", lab->tamanho);
  for (int i = 0; i < lab->tamanho; i++){
    for (int j = 0; j < lab->tamanho; j++){
      fprintf(stderr, "%3d", lab->dadosInteiros[i][j]);
    }
    fprintf(stderr, "\n");
  }
  fprintf(stderr, "\n");
  */
  
  fclose(f);
}