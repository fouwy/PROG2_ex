/*****************************************************************/
/*   Grafo c/ matriz de adjacencias | PROG2 | MIEEC | 2017/18    */      
/*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

/* cria grafo com n vertices */
grafo* grafo_novo(int n)
{
    int v;
    grafo* g;
    
    g = (grafo*)malloc(sizeof(grafo));
    g->tamanho = n;

    /* cria array de listas de adjacencias */
    g->adjacencias = (int**)malloc(n * sizeof(int*));
    for(v=0; v<n; v++)
    {
        g->adjacencias[v] = (int*)calloc(n, sizeof(int));
    }

    return g;
}

/* apaga grafo e liberta memoria */
void grafo_apaga(grafo* g)
{
    if(g == NULL)
        return;

    if(g->adjacencias != NULL)
    {
        int v;
        for (v = 0; v < g->tamanho; v++)
            free(g->adjacencias[v]);
        free(g->adjacencias);
    }
    free(g);
}

/* adiciona no grafo g uma aresta entre os vertices origem e destino
   retorna -1 em caso de erro (parametros invalidos)
   retorna 0 se a aresta ja existir e 1 se foi adicionada */
int grafo_adiciona(grafo *g, int origem, int dest)
{   
    if (g == NULL)   return -1;
    if (origem > g->tamanho || dest > g->tamanho || origem == dest)	return -1;

	if (g->adjacencias[origem][dest]==1) {
		return 0;
	}
	else {
		g->adjacencias[origem][dest] = 1;
		return 1;
	}

	return -1;
}

/* remove do grafo g a aresta entre os vertices origem e destino
   retorna -1 em caso de erro (parametros invalidos)
   retorna 0 se a aresta nao existir e 1 se foi removida */
int grafo_remove(grafo *g, int origem, int dest)
{
	if (g == NULL)   return -1;
    if (origem > g->tamanho || dest > g->tamanho || origem == dest)	return -1;

	if (g->adjacencias[origem][dest] == 0) {
		return 0;
	}
	else {
		g->adjacencias[origem][dest] = 0;
		return 1;
	}

	return -1;
}

/* testa no grafo g a aresta entre os vertices origem e destino
   retorna -1 em caso de erro (parametros invalidos)
   retorna 0 se a aresta nao existir e 1 se existir */
int grafo_aresta(grafo *g, int origem, int dest)
{	
	if (g == NULL)   return -1;
    if (origem > g->tamanho || dest > g->tamanho || origem == dest)	return -1;

	if (g->adjacencias[origem][dest] == 0) {
		return 0;
	}

	else if (g->adjacencias[origem][dest] == 1); {
		return 1;
	}

    return -1;
}

/* cria um novo grafo com base numa lista de adjacencias
   parametro adjacencies e' um array de inteiros, representado
   um numero n_edges de arestas.
   retorna um apontador para o grafo criado */
grafo* grafo_deLista(int* adjacencias, int n_arestas)
{
	grafo *g;
	
	int i;
	int max = 0;
	
	// procura o maximo do vetor
	for(i=0; i< n_arestas * 2; i++) {
		if(adjacencias[i] > max) {
			max = adjacencias[i];
		}
	}

	g = grafo_novo(max+1);

	if (g == NULL) {
		return NULL;
	}
	
	for (i=0; i<n_arestas * 2; i+=2) {
		grafo_adiciona(g, adjacencias[i], adjacencias[i+1]);
	}

    return g;
}

/* cria e retorna um vetor de inteiros contendo os vertices
   de destino de todas as arestas com origem em i */
vetor* grafo_arestasSaida(grafo* g, int i)
{
	int size_grafo, j;
	vetor *v;

	size_grafo = g->tamanho;
	v = vetor_novo();

	if(v == NULL) {
		return NULL;
	}

	if(g==NULL) {
		return NULL;
	}

	if(i > g->tamanho) {
		return NULL;
	}

	// pesquisa a linha do elemento i
	for(j=0; j<size_grafo; j++) {
		if(j == i)	continue;

		// se existir aresta, insere no final do vetor
		if(grafo_aresta(g, i, j) == 1) {
			vetor_insere(v, j, -1);
		}
	}

	return v;
}

/* cria e retorna um vetor de inteiros contendo os vertices
   de origem de todas as arestas com destino a i */
vetor* grafo_arestasEntrada(grafo* g, int i)
{
	int size_grafo, j;
	vetor *v;

	size_grafo = g->tamanho;
	v = vetor_novo();

	if(v == NULL) {
		return NULL;
	}

	if(g==NULL) {
		return NULL;
	}

	if(i > g->tamanho) {
		return NULL;
	}

	// pesquisa a coluna do elemento i
	for(j=0; j<size_grafo; j++) {
		if(j == i)	continue;

		// se existir aresta, insere no final do vetor
		if(grafo_aresta(g, j, i) == 1) {
			vetor_insere(v, j, -1);
		}
	}

	return v;
}

/* verifica se o grafo g e' completo
   retorna -1 em caso de erro (parametros invalidos)
   retorna 1 se o grafo for completo e 0 se nao o for */
int grafo_completo(grafo* g)
{	
	int i, j, vertices;
	if(g==NULL) return -1;

	vertices = grafo->tamanho;

	for(i=0; i<vertices; i++) {
		for(j=0; j<vertices; j++) {
			if(i == j) continue;
			if(grafo_aresta(g, i, j) == false) {
				return 0;
			}
		}
	}

    return 1;
}

/* verifica se o vertice i do grafo g e' uma celebridade
   retorna -1 em caso de erro (parametros invalidos)
   retorna 1 se o vertice for uma celebridade e 0 se nao o for */
int grafo_eCelebridade(grafo* g, int i)
{
    /* alinea 1.5 */ 

    return 0;
}

/* verifica se o grafo g tem pelo menos uma celebridade
   retorna -1 em caso de erro (parametros invalidos)
   retorna 1 se existir uma celebridade e 0 se nao existir */
int grafo_temCelebridade(grafo* g)
{
    /* alinea 1.5 */ 

    return 0;
}

/* imprime as adjacencias do grafo */
void grafo_imprime(grafo* g)
{
    int i, j;

    if (g == NULL)
        return;

    for (i = 0; i < g->tamanho; i++)
    {
        printf("%d: ", i);
        for(j = 0; j < g->tamanho; j++)
        {
            if(g->adjacencias[i][j] != 0)
                printf("%d ", j);
        }
        printf("\n");
    }
}

