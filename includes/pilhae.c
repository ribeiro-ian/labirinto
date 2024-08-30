#include <stdlib.h>
#include <stdio.h>
#include "pilhae.h"

/* <============== IMPLEMENTAÇÃO ==============> */

struct celula{
  cel *prox;
  item it;
};

struct pilha{
  int qtd;
  cel* prim;
};

cel* criar_celula_pilha(item it){
  cel* nova = (cel*) malloc(sizeof(cel));

  if (nova){
    nova->it = it;
    nova->prox = NULL;
  }
  
  return nova;
}

pilha* pilha_criar(){
  pilha *p = (pilha*) malloc(sizeof(pilha));
  
  if (!p) return p;

  p->prim = NULL;
  p->qtd = 0;

  return p;
}

void pilha_liberar(pilha **p){
  pilha_esvaziar(*p);
  free(*p);
  *p = NULL;
}

item pilha_topo(pilha *p){
  item it;

  if (pilha_vazia(p))
    return it;

  return p->prim->it;
}

int pilha_tamanho(pilha *p){
  return p->qtd;
}

bool pilha_vazia(pilha *p){
  return p->qtd == 0;
}

void pilha_esvaziar(pilha *p){
  while (!pilha_vazia(p))
    pilha_remover(p);
}

bool pilha_inserir(pilha *p, item it){
  cel* nova = criar_celula_pilha(it);
  
  if (!nova)
    return false;

  nova->prox = p->prim;
  p->prim = nova;

  p->qtd++;
  return true;
}

bool pilha_remover(pilha *p){
  if (pilha_vazia(p))
    return false;
  
  cel *temp = p->prim;
  p->prim = temp->prox;
  free(temp);

  p->qtd--;
  return true;  
}

void pilha_exibir(pilha *p){

  cel *temp = p->prim;

  while(temp != NULL){
    printf("%d ", temp->it);
    temp = temp->prox;
  }
  printf("\n");
}