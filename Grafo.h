/*
 * Trabalho 1 - Zoologico
 *
 * GEN254 - Grafos - 2025/1
 *
 * Nomes:      Alice Boostel | Daniel Salvini
 * Matriculas: 20230003771, 2021101024
 */

#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
using namespace std;

/**
 * @brief Classe que representa um grafo usando matriz de adjacência.
 *
 * Esta classe implementa operações básicas de um grafo não direcionado,
 * incluindo verificação de bipartição através de diferentes algoritmos.
 */
class Grafo
{
private:
    /** @brief Número de vértices do grafo */
    int numVertices;

    /** @brief Matriz de adjacência (0 = sem aresta, 1 = aresta tipo 'A', 2 = aresta tipo 'N') */
    std::vector<std::vector<int>> matrizAdj;

    /** @brief Componentes conexos do grafo identificados durante verificação de bipartição */
    vector<vector<int>> componentes;

public:
    /**
     * @brief Construtor da classe Grafo.
     * @param numVertices O número de vértices do grafo.
     */
    Grafo(int numVertices);

    /**
     * @brief Insere uma ligação (aresta) entre dois vértices no grafo.
     * @param origem Vértice de origem.
     * @param destino Vértice de destino.
     * @param tipo Tipo da aresta ('A' para amizade, 'N' para inimizade).
     */
    void inserirLigacao(int origem, int destino, char tipo);

    /**
     * @brief Verifica se o grafo é bipartido usando algoritmo recursivo.
     * @return true se o grafo for bipartido, false caso contrário.
     */
    bool checarBiparticaoRecursiva();

    /**
     * @brief Verifica se o grafo é bipartido usando algoritmo iterativo.
     * @return true se o grafo for bipartido considerando apenas arestas tipo 'A', false caso contrário.
     */
    bool checarBiparticaoIterativa();

    /**
     * @brief Obtém os componentes conectados do grafo.
     * @return Uma referência constante para o vetor de componentes.
     */
    const vector<vector<int>> &getComponentes() const;

private:
    /**
     * @brief Implementação recursiva da busca em profundidade para verificar bipartição.
     * @param verticeAtual Vértice atual sendo visitado.
     * @param cores Vetor com as cores atribuídas a cada vértice.
     * @param cor Cor a ser atribuída ao vértice atual.
     * @param componenteAtual Vetor que armazena os vértices do componente atual.
     * @return true se o componente for bipartido, false caso contrário.
     */
    bool dfsRecursivo(int verticeAtual, std::vector<int> &cores, int cor, vector<int> &componenteAtual);

    /**
     * @brief Implementação iterativa da busca em profundidade para verificar bipartição.
     * @param verticeInicial Vértice inicial da busca.
     * @param cores Vetor com as cores atribuídas a cada vértice.
     * @param componenteAtual Vetor que armazena os vértices do componente atual.
     * @return true se o componente for bipartido, false caso contrário.
     */
    bool dfsIterativo(int verticeInicial, std::vector<int> &cores, vector<int> &componenteAtual);
};

#endif // GRAFO_H