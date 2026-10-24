/**
 * @file Node.cpp
 * @brief Implementacja konstruktora węzła.
 */
#include "Node.h"

/**
 * @brief Inicjalizuje wartość oraz zeruje oba wskaźniki.
 * @param value Wartość początkowa węzła.
 */
Node::Node(int value) : value(value), prev(nullptr), next(nullptr) {}
