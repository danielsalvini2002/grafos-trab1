/*
 * Trabalho 1 - Zoologico
 *
 * GEN254 - Grafos - 2025/1
 *
 * Nomes:      Alice Boostel | Daniel Salvini
 * Matriculas: 20230003771, 2021101024
 */

#include <iostream>
#include "Grafo.h"

using namespace std;

/**
 * Função principal que processa a entrada, constrói o grafo e
 * verifica se ele é bipartido usando dois algoritmos diferentes.
 *
 * @return 0 se o programa executar com sucesso.
 */
int main()
{
    // Leitura do número de vértices e arestas
    int numVert, numAres;
    cin >> numVert >> numAres;

    // Criação do grafo com o número especificado de vértices
    Grafo rede(numVert);

    // Leitura e inserção das ligações (arestas) no grafo
    for (int i = 0; i < numAres; i++)
    {
        int orig, dest;
        char tipo;
        cin >> orig >> dest >> tipo;
        rede.inserirLigacao(orig, dest, tipo);
    }

    // Verificação de bipartição usando algoritmo recursivo
    bool resultado1 = rede.checarBiparticaoRecursiva();
    if (resultado1)
    {
        cout << "SIM" << endl;
    }
    else
    {
        cout << "NAO" << endl;
    }

    // Verificação de bipartição usando algoritmo iterativo
    bool resultado2 = rede.checarBiparticaoIterativa();
    if (resultado2)
    {
        cout << "SIM" << endl;
    }
    else
    {
        cout << "NAO" << endl;
    }

    return 0;
}