#ifndef FILA_H // Include guard
#define FILA_H

#include <stdbool.h> // bool => {false, true}
typedef int item;

/* <============== INTERFACE ==============> */
typedef struct fila fila;
typedef struct celula cel;

struct celula{
  cel *prox;
  item it;
};

struct fila{ 
  int qtd;
  cel *prim;
};

/*
Inicializa a fila
Entrada: referência para a fila f
Saída: Não tem
*/
void fila_inicializar(fila *f);

/*
Libera a memória alocada para a fila
Entrada: referência para a fila f
Saída: Não tem
*/
void fila_liberar(fila *f);

/*
Insere um item na fila
Entrada: referência para a fila f e o item it a ser inserido
Saída: true se inserido com sucesso; false caso contrário
*/
bool fila_inserir(fila* f, item it);

/*
Remove o item na frente da fila
Entrada: referência para a fila f
Saída: true se removido com sucesso; false caso contrário
*/
bool fila_remover(fila *f);

/*
Esvazia uma fila
Entrada: referência para a fila f
Saída: Não tem
*/
void fila_esvaziar(fila *f);

/*
Retorna o item da frente da fila
Entrada: referência para a fila f
Saída: item da frente
*/
item fila_frente(fila *f);

/*
Informa o tamanho da fila, ou seja, o número
de itens armazenados em um dado momento
Entrada: referência para a fila f
Saída: o tamanho da fila
*/
int fila_tamanho(fila *f);

/*
Informa se uma fila está vazia ou não
Entrada: referência para a fila f
Saída: true se estiver vazia; false caso contrário
*/
bool fila_vazia(fila *f);

#endif