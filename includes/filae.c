/* Ian Ribeiro de Oliveira */

#include <stdlib.h>
#include <stdio.h>
#include "filae.h"

/* <============== IMPLEMENTAÇÃO ==============> */

// Dados ocultos
struct celula{
  cel *prox;
  item it;
};

struct fila{ 
  int qtd;
  cel *prim;
};

cel* criar_celula_fila(item it){
  cel* nova = (cel*) malloc(sizeof(cel));

  if (nova){
    nova->it = it;
    nova->prox = NULL;
  }
  
  return nova;
}

fila* fila_criar(){
  fila *f = (fila*) malloc(sizeof(fila));
  
  if (!f) return f;

  f->prim = NULL;
  f->qtd = 0;

  return f;
}

void fila_liberar(fila **f){
  fila_esvaziar(*f);
  free(*f);
  *f = NULL;
}

item fila_frente(fila *f){
  return f->prim->it;
}

int fila_tamanho(fila *f){
  return f->qtd;
}

bool fila_vazia(fila *f){
  return f->qtd == 0;
}

void fila_esvaziar(fila *f){
  while (!fila_vazia(f))
    fila_remover(f);

  f->qtd = 0;
}

bool fila_inserir(fila *f, item it){
  cel* nova = criar_celula_fila(it);
  
  if (!nova)
    return false;
  if (fila_vazia(f))
    f->prim = nova;
  else {
    cel* temp = f->prim;
    while (temp->prox != NULL)
      temp = temp->prox;
    temp->prox = nova;
  }

  f->qtd++;
  return true;
}

bool fila_remover(fila *f){
  if (fila_vazia(f))
    return false;
  
  cel *temp = f->prim;
  f->prim = temp->prox;
  free(temp);

  f->qtd--;
  return true;  
}

void fila_exibir(fila *f){
  cel *temp = f->prim;

  while (temp != NULL){
    printf("%i ", temp->it);
    temp = temp->prox;
  }
  
  printf("\n");
}