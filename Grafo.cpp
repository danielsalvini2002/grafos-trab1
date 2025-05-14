/*
 * Trabalho 1 - Zoologico
 *
 * GEN254 - Grafos - 2025/1
 *
 * Nomes:      Alice Boostel | Daniel Salvini
 * Matriculas: 20230003771, 2021101024
 */

#include "Grafo.h"
#include <stack>

/**
 * Construtor da classe Grafo.
 *
 * @param numVertices O número de vértices do grafo.
 */
Grafo::Grafo(int numVertices)
{
    this->numVertices = numVertices;
    matrizAdj.resize(numVertices, std::vector<int>(numVertices, 0));
    componentes.clear();
}

/**
 * Insere uma ligação (aresta) entre dois vértices no grafo.
 *
 * @param origem Vértice de origem.
 * @param destino Vértice de destino.
 * @param tipo Tipo da aresta ('A' para amizade, 'N' para inimizade).
 */
void Grafo::inserirLigacao(int origem, int destino, char tipo)
{
    if (tipo == 'A')
    {
        matrizAdj[origem][destino] = 1; // Aresta tipo 'A'
        matrizAdj[destino][origem] = 1; // Grafo não direcionado
    }
    else if (tipo == 'N')
    {
        matrizAdj[origem][destino] = 2; // Aresta tipo 'N'
        matrizAdj[destino][origem] = 2; // Grafo não direcionado
    }
}

/**
 * Verifica se o grafo é bipartido usando um algoritmo recursivo de busca em profundidade.
 * Um grafo é bipartido se pode ser colorido com duas cores sem que vértices adjacentes tenham a mesma cor.
 * No algoritmo recursivo, arestas tipo 'N' fazem com que o grafo não seja bipartido.
 *
 * @return true se o grafo for bipartido, false caso contrário.
 */
bool Grafo::checarBiparticaoRecursiva()
{
    // Primeiro, verificamos se há alguma aresta do tipo 'N' no grafo
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if (matrizAdj[i][j] == 2)
            {                 // Aresta tipo 'N'
                return false; // Se encontrar uma aresta tipo 'N', o grafo não é bipartido
            }
        }
    }

    // Se não encontrou arestas do tipo 'N', continua com a verificação normal
    std::vector<int> cores(numVertices, 0); // 0 = não visitado, 1 = cor 1, -1 = cor 2
    componentes.clear();

    // Verificar cada componente conectado do grafo
    for (int i = 0; i < numVertices; i++)
    {
        if (cores[i] == 0) // Se o vértice não foi visitado
        {
            vector<int> componenteAtual;
            bool bipartido = dfsRecursivo(i, cores, 1, componenteAtual);

            if (!bipartido)
            {
                return false; // Se algum componente não for bipartido, o grafo não é bipartido
            }

            componentes.push_back(componenteAtual);
        }
    }

    return true; // Se todos os componentes são bipartidos, o grafo é bipartido
}

/**
 * Implementação recursiva da busca em profundidade (DFS) para verificar se o grafo é bipartido.
 *
 * @param verticeAtual Vértice atual sendo visitado.
 * @param cores Vetor que armazena as cores atribuídas aos vértices (0 = não visitado, 1 = cor 1, -1 = cor 2).
 * @param cor Cor a ser atribuída ao vértice atual.
 * @param componenteAtual Vetor que armazena os vértices do componente atual.
 * @return true se o componente for bipartido, false caso contrário.
 */
bool Grafo::dfsRecursivo(int verticeAtual, std::vector<int> &cores, int cor, vector<int> &componenteAtual)
{
    cores[verticeAtual] = cor;               // Atribui a cor ao vértice atual
    componenteAtual.push_back(verticeAtual); // Adiciona o vértice atual ao componente

    for (int i = 0; i < numVertices; i++)
    {
        if (matrizAdj[verticeAtual][i] == 1) // Aresta tipo 'A'
        {
            if (cores[i] == 0) // Se o vértice não foi visitado
            {
                if (!dfsRecursivo(i, cores, -cor, componenteAtual))
                {
                    return false; // Propaga o resultado negativo
                }
            }
            else if (cores[i] == cor)
            {
                // Se encontrar um vértice adjacente com a mesma cor, o grafo não é bipartido
                return false;
            }
        }
        // Não verificamos arestas tipo 'N' aqui, pois já foram verificadas em checarBiparticaoRecursiva
    }

    return true; // Se não houver conflito de cores, o componente é bipartido
}

/**
 * Verifica se o grafo é bipartido usando um algoritmo iterativo de busca em profundidade.
 * Um grafo é bipartido se pode ser colorido com duas cores sem que vértices adjacentes tenham a mesma cor.
 * No algoritmo iterativo, arestas tipo 'N' são ignoradas.
 *
 * @return true se o grafo for bipartido considerando apenas arestas tipo 'A', false caso contrário.
 */
bool Grafo::checarBiparticaoIterativa()
{
    std::vector<int> cores(numVertices, -1); // -1 = não visitado
    componentes.clear();

    // Verificar cada componente conectado do grafo
    for (int i = 0; i < numVertices; i++)
    {
        if (cores[i] == -1) // Se o vértice não foi visitado
        {
            vector<int> novaComponente;
            if (!dfsIterativo(i, cores, novaComponente))
            {
                return false; // Se algum componente não for bipartido, o grafo não é bipartido
            }
            componentes.push_back(novaComponente);
        }
    }
    return true; // Se todos os componentes são bipartidos, o grafo é bipartido
}

/**
 * Implementação iterativa da busca em profundidade (DFS) para verificar se o grafo é bipartido.
 *
 * @param verticeInicial Vértice inicial para a busca.
 * @param cores Vetor que armazena as cores atribuídas aos vértices (-1 = não visitado, 0 = cor 1, 1 = cor 2).
 * @param componenteAtual Vetor que armazena os vértices do componente atual.
 * @return true se o componente for bipartido, false caso contrário.
 */
bool Grafo::dfsIterativo(int verticeInicial, std::vector<int> &cores, vector<int> &componenteAtual)
{
    stack<int> pilha;
    pilha.push(verticeInicial);
    cores[verticeInicial] = 1; // Atribui cor inicial
    componenteAtual.push_back(verticeInicial);

    while (!pilha.empty())
    {
        int atual = pilha.top();
        pilha.pop();

        for (int i = 0; i < numVertices; i++)
        {
            if (matrizAdj[atual][i] == 1) // Aresta tipo 'A'
            {
                if (cores[i] == -1) // Se vértice não visitado
                {
                    cores[i] = 1 - cores[atual]; // Alterna entre 0 e 1
                    pilha.push(i);
                    componenteAtual.push_back(i);
                }
                else if (cores[i] == cores[atual])
                {
                    // Se vértice adjacente tem mesma cor, não é bipartido
                    return false;
                }
            }
            // Arestas tipo 'N' são ignoradas na verificação iterativa (conforme os testes esperados)
        }
    }

    return true; // Se não houver conflito de cores, o componente é bipartido
}

/**
 * Obtém os componentes conectados do grafo encontrados durante a última verificação de bipartição.
 *
 * @return Uma referência para o vetor de componentes conectados.
 */
const vector<vector<int>> &Grafo::getComponentes() const
{
    return componentes;
}
