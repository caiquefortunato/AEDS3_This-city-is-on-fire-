#include <stdio.h>
#include <stdlib.h>
//#include "grafo.h"
#include "lista.h"

Lista *cria_lista()
{
	Lista *lista;
	lista = (Lista*)malloc(sizeof(Lista));
	
	lista->primeiro = (Elemento*)malloc(sizeof(Elemento));
	lista->primeiro->prox = NULL;
	lista->ultimo = lista->primeiro;
	
	return lista;
}

void insere_lista(Lista *lista, int vertice, double prob)
{
	Elemento *aux;
	
	aux = (Elemento*)malloc(sizeof(Elemento));
	aux->vertice = vertice;
	aux->peso = prob;
	aux->prox = NULL;
		
	// Ligo os componentes
	lista->ultimo->prox = aux;
	lista->ultimo = lista->ultimo->prox;
}

void libera_lista(Lista *lista)
{
	Elemento *limpa_atual, *x;
	limpa_atual = lista->primeiro->prox;
	
	while(limpa_atual != NULL)
	{
		x = limpa_atual;
		limpa_atual = limpa_atual->prox;
		free(x);
	}
	
	free(lista->primeiro);
	free(lista);
}
