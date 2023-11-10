#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "grafo.h"

int main() {
    // Grafo para busca em largura
    VERTICE verticesLargura[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        verticesLargura[i].valor = i;
        verticesLargura[i].visitado = false;
        verticesLargura[i].nroVizinhos = 0;
    }

    verticesLargura[0].vizinhos[verticesLargura[0].nroVizinhos++] = &verticesLargura[1];
    verticesLargura[0].vizinhos[verticesLargura[0].nroVizinhos++] = &verticesLargura[2];
    verticesLargura[1].vizinhos[verticesLargura[1].nroVizinhos++] = &verticesLargura[3];
    verticesLargura[1].vizinhos[verticesLargura[1].nroVizinhos++] = &verticesLargura[4];
    verticesLargura[1].vizinhos[verticesLargura[1].nroVizinhos++] = &verticesLargura[5];
    verticesLargura[3].vizinhos[verticesLargura[3].nroVizinhos++] = &verticesLargura[6];
    verticesLargura[3].vizinhos[verticesLargura[3].nroVizinhos++] = &verticesLargura[7];
    verticesLargura[5].vizinhos[verticesLargura[5].nroVizinhos++] = &verticesLargura[8];
    verticesLargura[5].vizinhos[verticesLargura[5].nroVizinhos++] = &verticesLargura[9];
    verticesLargura[7].vizinhos[verticesLargura[7].nroVizinhos++] = &verticesLargura[10];
    verticesLargura[7].vizinhos[verticesLargura[7].nroVizinhos++] = &verticesLargura[11];
    verticesLargura[7].vizinhos[verticesLargura[7].nroVizinhos++] = &verticesLargura[12];
    verticesLargura[9].vizinhos[verticesLargura[9].nroVizinhos++] = &verticesLargura[13];
    verticesLargura[9].vizinhos[verticesLargura[9].nroVizinhos++] = &verticesLargura[14];

    // Reinicializar visitados
    reinicializarVisitados(verticesLargura, MAX_VERTICES);

    // Realizar a busca em largura a partir do vértice 0 para o vértice 1
    int resultadoLargura = buscaEmLargura(&verticesLargura[0], &verticesLargura[1]);

    // Exibir o resultado da busca em largura
    if (resultadoLargura != -1) {
        printf("Busca em Largura: O vertice %d foi encontrado na posicao %d da fila.\n", verticesLargura[1].valor, resultadoLargura);
    } else {
        printf("Busca em Largura: O vertice %d nao foi encontrado no grafo.\n", verticesLargura[1].valor);
    }

    // Grafo para busca em profundidade
    VERTICE verticesProfundidade[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        verticesProfundidade[i].valor = i;
        verticesProfundidade[i].visitado = false;
        verticesProfundidade[i].nroVizinhos = 0;
    }

    verticesProfundidade[0].vizinhos[verticesProfundidade[0].nroVizinhos++] = &verticesProfundidade[1];
    verticesProfundidade[1].vizinhos[verticesProfundidade[1].nroVizinhos++] = &verticesProfundidade[2];
    verticesProfundidade[1].vizinhos[verticesProfundidade[1].nroVizinhos++] = &verticesProfundidade[4];
    verticesProfundidade[2].vizinhos[verticesProfundidade[2].nroVizinhos++] = &verticesProfundidade[3];
    verticesProfundidade[2].vizinhos[verticesProfundidade[2].nroVizinhos++] = &verticesProfundidade[4];
    verticesProfundidade[2].vizinhos[verticesProfundidade[2].nroVizinhos++] = &verticesProfundidade[9];
    verticesProfundidade[3].vizinhos[verticesProfundidade[3].nroVizinhos++] = &verticesProfundidade[4];
    verticesProfundidade[4].vizinhos[verticesProfundidade[4].nroVizinhos++] = &verticesProfundidade[5];
    verticesProfundidade[4].vizinhos[verticesProfundidade[4].nroVizinhos++] = &verticesProfundidade[6];
    verticesProfundidade[4].vizinhos[verticesProfundidade[4].nroVizinhos++] = &verticesProfundidade[7];
    verticesProfundidade[5].vizinhos[verticesProfundidade[5].nroVizinhos++] = &verticesProfundidade[6];
    verticesProfundidade[7].vizinhos[verticesProfundidade[7].nroVizinhos++] = &verticesProfundidade[8];
    verticesProfundidade[7].vizinhos[verticesProfundidade[7].nroVizinhos++] = &verticesProfundidade[9];

    // Reinicializar visitados
    reinicializarVisitados(verticesProfundidade, MAX_VERTICES);

    // Realizar a busca em profundidade a partir do vértice 0 para o vértice 9
    int sequenciaProfundidade[MAX_VERTICES];
    int sequenciaIndexProfundidade = 0;
    int* resultadoProfundidade = buscaEmProfundidade(&verticesProfundidade[0], &verticesProfundidade[9], sequenciaProfundidade, &sequenciaIndexProfundidade);

    // Exibir a sequência de vértices descobertos na busca em profundidade
    printf("\nBusca em Profundidade: Sequencia de vertices descobertos: ");
    for (int i = 0; i < sequenciaIndexProfundidade; i++) {
        printf("%d ", resultadoProfundidade[i]);
    }
    printf("\n");

    return 0;
}
