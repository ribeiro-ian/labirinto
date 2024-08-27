#include <stdlib.h>
#include <stdio.h>
#include "filae.h"

/* <============== IMPLEMENTAÇÃO ==============> */

cel* criar_celula_fila(item it){
  cel* nova = (cel*) malloc(sizeof(cel));

  if (nova){
    nova->it = it;
    nova->prox = NULL;
  }
  
  return nova;
}

void fila_inicializar(fila *f){
  f->prim = NULL;
  f->qtd = 0;
}

void fila_liberar(fila *f){
  fila_esvaziar(f);
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

void fila_esvaziar(fila *f){
  while (!fila_vazia(f))
    fila_remover(f);

  f->qtd = 0;
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
