/*
 * Trabalho 1 - Zoologico
 *
 * GEN254 - Grafos - 2025/1
 *
 * Nomes:      Alice Boostel | Daniel Salvini
 * Matriculas: 20230003771, 2021101024
 */

#ifndef ARESTA_H
#define ARESTA_H

/**
 * @brief Classe que representa uma aresta em um grafo.
 *
 * Esta classe armazena informações sobre uma ligação entre dois vértices,
 * incluindo a origem, o destino e o tipo da conexão.
 */
class Aresta
{
private:
    /** @brief Vértice de origem da aresta */
    int origem;

    /** @brief Vértice de destino da aresta */
    int destino;

    /** @brief Tipo da aresta ('A' para amizade, 'N' para inimizade) */
    char tipo;

public:
    /**
     * @brief Construtor da classe Aresta.
     * @param origem Vértice de origem.
     * @param destino Vértice de destino.
     * @param tipo Tipo da aresta ('A' para amizade, 'N' para inimizade).
     */
    Aresta(int origem, int destino, char tipo);

    /**
     * @brief Obtém o vértice de origem da aresta.
     * @return Número do vértice de origem.
     */
    int getOrigem() const;

    /**
     * @brief Obtém o vértice de destino da aresta.
     * @return Número do vértice de destino.
     */
    int getDestino() const;

    /**
     * @brief Obtém o tipo da aresta.
     * @return Tipo da aresta ('A' para amizade, 'N' para inimizade).
     */
    char getTipo() const;
};

#endif // ARESTA_H