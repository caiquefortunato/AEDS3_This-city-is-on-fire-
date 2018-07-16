#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila *cria_fila()
{
	Fila *fila;
	fila = (Fila*)malloc(sizeof(Fila));
	
	fila->tamanho = 0;
	fila->primeiro = (Elemento1*)malloc(sizeof(Elemento1));
	fila->primeiro->prox = NULL;
	fila->ultimo = fila->primeiro;
	
	return fila;
}

void insere_fila(Fila *fila, int vertice)
{
	Elemento1 *novo;
	
	novo = (Elemento1*)malloc(sizeof(Elemento1));
	novo->vertice = vertice;
	novo->prox = NULL;
	
	// Ligacao
	fila->tamanho += 1;
	fila->ultimo->prox = novo;
	fila->ultimo = fila->ultimo->prox;
}

int retira_fila(Fila *fila)
{
	int retira;
	retira = fila->primeiro->prox->vertice;
	fila->tamanho -= 1;
	Elemento1 *elimina;
	
	elimina = fila->primeiro->prox;
	fila->primeiro->prox = elimina->prox;
	
	if(fila->ultimo == elimina)
		fila->ultimo = fila->primeiro;
		
	free(elimina);
	
	return retira;
}

void libera_fila(Fila *fila)
{
	Elemento1 *aux, *x;
	aux = fila->primeiro->prox;
	
	while(aux != NULL)
	{
		x = aux;
		aux = aux->prox;
		free(x);
	}
	
	free(fila->primeiro);
	free(fila);
}
/*
void imprime_fila(Fila *fila)
{
	Elemento1 *atual;
	atual = fila->primeiro->prox;
	int i = 0;
	
	while(atual != NULL)
	{
		printf("O elemento %d eh %d\n", i, atual->vertice);
		i++;
		atual = atual->prox;
	}
}
*/
int estado_fila(Fila *fila)
{
	if(fila->primeiro->prox == NULL)
		return 1;
		
	else
		return 0;
}

