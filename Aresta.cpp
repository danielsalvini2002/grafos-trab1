/*
 * Trabalho 1 - Zoologico
 *
 * GEN254 - Grafos - 2025/1
 *
 * Nomes:      Alice Boostel | Daniel Salvini
 * Matriculas: 20230003771, 2021101024
 */

#include "Aresta.h"

/**
 * @brief Construtor da classe Aresta.
 * @param origem Vértice de origem.
 * @param destino Vértice de destino.
 * @param tipo Tipo da aresta ('A' para amizade, 'N' para inimizade).
 */
Aresta::Aresta(int origem, int destino, char tipo)
{
    this->origem = origem;
    this->destino = destino;
    this->tipo = tipo;
}

/**
 * @brief Obtém o vértice de origem da aresta.
 * @return Número do vértice de origem.
 */
int Aresta::getOrigem() const
{
    return origem;
}

/**
 * @brief Obtém o vértice de destino da aresta.
 * @return Número do vértice de destino.
 */
int Aresta::getDestino() const
{
    return destino;
}

/**
 * @brief Obtém o tipo da aresta.
 * @return Tipo da aresta ('A' para amizade, 'N' para inimizade).
 */
char Aresta::getTipo() const
{
    return tipo;
}