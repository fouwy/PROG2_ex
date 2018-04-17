#include "grafo.h"
#include <stdio.h>

void imprime_vetor(vetor *v);

int main()
{
	/* exemplo da alinea 1.2 */
	int adj[] = {1,2,1,3,1,4,2,5,3,5,4,5};
	grafo *g12 = grafo_deLista(adj, 6);
	grafo_imprime(g12);

	/* outros testes */

	// alinea 1.1
	int num;
	grafo *G;

	G = grafo_novo(3);

	num = grafo_adiciona(G, 0, 1);

	if (num == -1) {
		printf("ERRO\n");
	}
	else if (num == 0) {
		printf("Aresta já existe\n");
	}
	else if (num == 1) {
		printf("Aresta adicionada\n");
	}


	// teste remove
	num = grafo_remove(G, 0, 1);

	if (num == -1) {
		printf("ERRO\n");
	}
	else if (num == 0) {
		printf("Aresta nao existe\n");
	}
	else if (num == 1) {
		printf("Aresta removida\n");
	}


	// teste aresta
	num = grafo_aresta(G, 0, 1);
	
	if (num == -1) {
		printf("ERRO\n");
	}
	else if (num == 0) {
		printf("Aresta nao existe\n");
	}
	else if (num == 1) {
		printf("Aresta existe\n");
	}


	// teste arestasSaida
	vetor *V;

	V = vetor_novo();

	if(V==NULL) {
		printf("ERRO a criar vetor\n");
	}
	

	V = grafo_arestasSaida(g12, 1);

	imprime_vetor(V);

	vetor_apaga(V);

	// arestas Entrada
	vetor *glub;

	glub = vetor_novo();

	if(glub==NULL) {
		printf("ERRO a criar vetor\n");
	}
	

	glub = grafo_arestasEntrada(g12, 5);

	imprime_vetor(glub);

	vetor_apaga(glub);


	// grafo completo
	int adj[] = {0,1,}


	printf("\nFIM\n");

	// liberta a memoria
	grafo_apaga(G);
	grafo_apaga(g12);

	return 0;
}

void imprime_vetor(vetor *v) {
	int i;

	if(v == NULL) return;
	
	for(i=0; i<v->tamanho; i++) {
		printf("%d	", v->elementos[i]);
	}

	printf("\n");
}