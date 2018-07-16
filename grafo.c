#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "lista.h"
#include "grafo.h"

void Busca_Largura (vertice *Grafo, int id_saida)
{

	int i;

	Fila *fila;
	fila = cria_fila();
	Elemento *aux;
	
	int v;
	v = id_saida;
	insere_fila(fila, v);
	
	int posicao;
	
	while(estado_fila(fila) != 1)
	{
		v = retira_fila(fila);
		aux = Grafo[v].adj->primeiro->prox;
		
		while(aux != NULL)
		{
			posicao = aux->vertice;
			
			if(Grafo[v].tem_bombeiro + 1 < Grafo[posicao].tem_bombeiro)
			{
				insere_fila(fila, posicao);
				Grafo[posicao].tem_bombeiro = Grafo[v].tem_bombeiro + 1;	
			}
			
			aux = aux->prox;
		}
	}
	
	//for(i = 0; i < 9; i++){
		//printf("%d\n", Grafo[i].tem_bombeiro);
	//}
	
	libera_fila(fila);

}

void Dijkstra (vertice *Grafo, int id_saida, int id_chegada, int k, int quarteirao)
{
	int i, j;

	Fila *fila;
	fila = cria_fila();
	Elemento *aux;
	
	int v;
	v = id_saida;
	Grafo[v].probabilidade = 0;
	insere_fila(fila, v);
	
	int posicao;
	double conta;
	
	for(j = 0; j < quarteirao; j++)
	{
		Grafo[j].estado = 'b';
		Grafo[j].anterior = -1;
	}
	
	Grafo[v].anterior = v;
	
	while(estado_fila(fila) != 1)
	{
		v = retira_fila(fila);
		Grafo[v].estado = 'b';
		
		//printf("v: %d\n", v);
		aux = Grafo[v].adj->primeiro->prox;
		
		while(aux != NULL)
		{
			posicao = aux->vertice;
			//printf("%lf %lf\n", Grafo[v].probabilidade, aux->peso);
			
			conta = (1 - ((1 - Grafo[v].probabilidade) * (1 - aux->peso)));
			//printf("Conta: %lf\n", conta);
			
			if(Grafo[posicao].tem_bombeiro <= k && conta < Grafo[posicao].probabilidade)
			{
				if(Grafo[posicao].estado == 'b')
				{
					insere_fila(fila, posicao);
					Grafo[posicao].estado = 'p';
				}
				Grafo[posicao].probabilidade = conta;
				Grafo[posicao].anterior = v;	
			}
			
			if(Grafo[posicao].tem_bombeiro <= k && conta == Grafo[posicao].probabilidade)
			{
				if(Grafo[posicao].anterior == -1)
					Grafo[posicao].anterior = v;
				
				if(Grafo[posicao].anterior > v)
				{
					Grafo[posicao].anterior = v;
				}
			}
			
			aux = aux->prox;
		}
	}
	
	libera_fila(fila);

}
