#ifndef GRAFO_H
#define GRAFO_H
#include "lista.h"
#define INF 999999999

typedef struct vertice
{
	Lista *adj;
	double probabilidade;
	int tem_bombeiro;
	char estado;
	int anterior;
} vertice;

void Busca_Largura (vertice *Grafo, int id_saida);

void Dijkstra (vertice *Grafo, int id_saida, int id_chegada, int k, int quarteirao);

#endif
