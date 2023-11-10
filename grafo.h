#ifndef GRAFO_H
#define GRAFO_H

#include <stdbool.h>

#define MAX_VERTICES 15

typedef struct Vertice {
    int valor;
    bool visitado;
    int nroVizinhos;
    struct Vertice* vizinhos[MAX_VERTICES];
} VERTICE;

int buscaEmLargura(VERTICE* inicio, VERTICE* destino);
void reinicializarVisitados(VERTICE* vertices, int numVertices);
int* buscaEmProfundidade(VERTICE* inicio, VERTICE* destino, int* sequencia, int* sequenciaIndex);

#endif // GRAFO_H
