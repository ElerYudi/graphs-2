#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

int buscaEmLargura(VERTICE* inicio, VERTICE* destino) {
    int iniFila = 0;
    int tamFila = 1;

    VERTICE** FILA = (VERTICE**)malloc(MAX_VERTICES * sizeof(VERTICE*));
    for (int i = 0; i < MAX_VERTICES; i++) {
        FILA[i] = NULL;
    }
    FILA[iniFila] = inicio;

    while (iniFila < tamFila) {
        if (FILA[iniFila] == destino) return iniFila;

        for (int i = 0; i < FILA[iniFila]->nroVizinhos; i++) {
            if (FILA[iniFila]->vizinhos[i]->visitado == false) {
                FILA[iniFila]->vizinhos[i]->visitado = true;
                FILA[tamFila] = FILA[iniFila]->vizinhos[i];
                tamFila++;
            }
        }
        iniFila++;
    }
    free(FILA);
    return -1;
}

void reinicializarVisitados(VERTICE* vertices, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        vertices[i].visitado = false;
    }
}

int* buscaEmProfundidade(VERTICE* inicio, VERTICE* destino, int* sequencia, int* sequenciaIndex) {
    inicio->visitado = true;
    sequencia[(*sequenciaIndex)++] = inicio->valor;

    if (inicio == destino) return sequencia;

    for (int i = 0; i < inicio->nroVizinhos; i++) {
        if (inicio->vizinhos[i]->visitado == false) {
            sequencia = buscaEmProfundidade(inicio->vizinhos[i], destino, sequencia, sequenciaIndex);
        }
    }

    return sequencia;
}