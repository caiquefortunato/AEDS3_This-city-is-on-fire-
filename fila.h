#ifndef FILA_H
#define FILA_H

typedef struct Elemento1
{
	int vertice;
	struct Elemento1 *prox;
}Elemento1;

typedef struct Fila
{
	Elemento1 *primeiro;
	Elemento1 *ultimo;
	int tamanho;
}Fila;

Fila *cria_fila();

void insere_fila(Fila *fila, int vertice);

int retira_fila(Fila *fila);

void libera_fila(Fila *fila);

void imprime_fila(Fila *fila);

int estado_fila(Fila *fila);

#endif
