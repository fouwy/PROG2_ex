#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int* caminho(grafo *g, int inicio, int fim, int *n, int peso17);

int main() {
    grafo *grafo;
    int tamanho;
    int *trail = (int*)malloc(sizeof(int) * 10);
    grafo = grafo_novo(8, 0);

    grafo_adiciona(grafo, 1, 2);
    grafo_adiciona(grafo, 1, 4);
    grafo_adiciona(grafo, 1, 7);
    grafo_adiciona(grafo, 2, 5);
    grafo_adiciona(grafo, 2, 3);
    grafo_adiciona(grafo, 3, 6);
    grafo_adiciona(grafo, 6, 5);
    grafo_adiciona(grafo, 6, 7);
    grafo_adiciona(grafo, 4, 7);
    grafo_adiciona(grafo, 5, 7);

    // grafo_imprime(grafo);
    trail = caminho(grafo, 1, 6, &tamanho, 4);
    trail = realloc(caminho, sizeof(int) * tamanho);
    
    for(int i = 0; i < tamanho; i++) {
        printf("%d", trail[i]);
        if(i != tamanho-1) printf("-> ");
    }
    printf("\n");

    // FIM
    grafo_apaga(grafo);
}

int* caminho(grafo *g, int inicio, int fim, int *n, int peso17) {
    int i, size_inbf;
    grafo *grafo;

    size_inbf = g->tamanho + peso17 -1;
    grafo = grafo_novo(size_inbf, 0);

    grafo_adiciona(grafo, 1, 2);
    grafo_adiciona(grafo, 1, 4);
    grafo_adiciona(grafo, 1, 7);
    grafo_adiciona(grafo, 2, 5);
    grafo_adiciona(grafo, 2, 3);
    grafo_adiciona(grafo, 3, 6);
    grafo_adiciona(grafo, 6, 5);
    grafo_adiciona(grafo, 6, 7);
    grafo_adiciona(grafo, 4, 7);
    grafo_adiciona(grafo, 5, 7);
    
    if(peso17 > 1) {
        grafo_remove(g, 1, 7);
       
        for(i=0; i<peso17; i++) {
            grafo_adiciona(g, 1, g->tamanho -1 -i);
        }
        grafo_adiciona(g, g->tamanho -1 -i, 7);
    }
    
    return grafo_bfs(g, inicio, fim, n);

}
