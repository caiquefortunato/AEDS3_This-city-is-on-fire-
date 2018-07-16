#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "lista.h"
#include "grafo.h"

int main()
{
	int testes, quarteirao, rua, id_saida, id_chegada;
	int n_bombeiros, distancia, vertice1, vertice2;
	double prob;
	Lista *lista;
	int i, j;
	
	scanf("%d", &testes);
	for(i = 0; i < testes; i++)
	{
		scanf("%d %d", &quarteirao, &rua);
		scanf("%d %d", &id_saida, &id_chegada);
		scanf("%d %d", &distancia, &n_bombeiros);
		
		// Crio meu grafo
		vertice Grafo[quarteirao];
		int imprime[quarteirao];
		
		// Zero meu vetor de imprimir
		for(j = 0; j < quarteirao; j++)
			imprime[j] = 0;
		
		for(j = 0; j < quarteirao; j++)
		{
			Grafo[j].adj = cria_lista();
			Grafo[j].probabilidade = 1;
			Grafo[j].tem_bombeiro = INF;
		}
			
		for(j = 0; j < rua; j++)
		{
			scanf("%d %d %lf", &vertice1, &vertice2, &prob);
			insere_lista(Grafo[vertice1].adj, vertice2, prob);
			insere_lista(Grafo[vertice2].adj, vertice1, prob);
		}
			
		for(j = 0; j < n_bombeiros; j++)
		{
			scanf("%d", &vertice1);
			Grafo[vertice1].tem_bombeiro = 0;
			Busca_Largura (Grafo, vertice1);
		}
				
		Dijkstra (Grafo, id_saida, id_chegada, distancia, quarteirao);
	
		//for(j = 0; j < quarteirao; j++)
			//printf("Anterior do vertice %d eh: %d\n", j, Grafo[j].anterior); 

		//imprimir
		int total = 0, k = 0;
		//if(Grafo[id_chegada].anterior == -1)
		if(Grafo[id_chegada].anterior == -1)
			printf("-1\n");
		///*
		else
		{
			int saida;
			saida = Grafo[id_chegada].anterior;
			imprime[k] = id_chegada;
			while(saida != id_saida)
			{
				imprime[k + 1] = saida;
				saida = Grafo[saida].anterior;
				k++;
				total ++;
			}
			imprime[k + 1] = id_saida;	
			
					
			printf("%.2lf", Grafo[id_chegada].probabilidade);
			for(j = total +1; j >= 0; j--) 
				printf(" %d", imprime[j]);
				printf("\n");
		}
		//*/	
		
		//Libera a lista
		for(j = 0; j < quarteirao; j++)
			libera_lista(Grafo[j].adj); 			
	
	}

	return 0;
}
