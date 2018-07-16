#ifndef LISTA_H
#define LISTA_H

typedef struct Elemento
{
	int vertice;
	double peso;
	struct Elemento *prox;
} Elemento;

typedef struct Lista
{
	Elemento *primeiro;
	Elemento *ultimo;
}Lista;

Lista *cria_lista();

void insere_lista(Lista *grafo, int vertice, double prob);

void libera_lista(Lista *lista);

#endif
