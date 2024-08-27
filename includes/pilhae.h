#ifndef PILHA_H // Include guard
#define PILHA_H

#include <stdbool.h>
// #include "item.h"
typedef int item;

// INTERFACE
typedef struct pilha pilha;
typedef struct celula cel;

struct celula{
  cel *prox;
  int it;
};

struct pilha{
  int qtd;
  cel* prim;
};

/*
Esvazia uma pilha
Entrada: referência para a pilha p
Saída: Não tem
*/
void pilha_esvaziar(pilha *p);

/*
Retorna o item da topo da pilha
Entrada: referência para a pilha p
Saída: item da topo
*/
item pilha_topo(pilha *p);

/*
Informa todos os itens da pilha
Entrada: referência para a pilha p
Saída: os itens da pilha
*/
void pilha_exibir(pilha *p);

/*
Inicializa a pilha
Entrada: referência para a pilha p
Saída: Não tem
*/
void pilha_inicializar(pilha *p);

/*
Libera a memória alocada para a pilha
Entrada: referência para a pilha p
Saída: Não tem
*/
void pilha_liberar(pilha *p);

/*
Insere um item na pilha
Entrada: referência para a pilha p e o item it a ser inserido
Saída: true se inserido com sucesso; false caso contrário
*/
bool pilha_inserir(pilha *p, item it);

/*
Remove o item na topo da pilha
Entrada: referência para a pilha p
Saída: true se removido com sucesso; false caso contrário
*/
bool pilha_remover(pilha *p);

/*
Informa o tamanho da pilha, ou seja, o número
de itens armazenados em um dado momento
Entrada: referência para a pilha p
Saída: o tamanho da pilha
*/
int pilha_tamanho(pilha *p);

/*
Informa se uma pilha está vazia ou não
Entrada: referência para a pilha p
Saída: true se estiver vazia; false caso contrário
*/
bool pilha_vazia(pilha *p);

#endif