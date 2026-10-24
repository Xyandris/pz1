/**
 * @file Node.h
 * @brief Deklaracja węzła listy dwukierunkowej.
 */
#ifndef NODE_H
#define NODE_H

/**
 * @class Node
 * @brief Pojedynczy węzeł przechowujący wartość oraz odnośniki do sąsiadów.
 */
class Node {
public:
    /**
     * @brief Tworzy węzeł o podanej wartości.
     * @param value Wartość przechowywana w węźle.
     */
    explicit Node(int value);

    int value; ///< Wartość przechowywana w węźle.
    Node* prev; ///< Wskaźnik na poprzedni węzeł lub nullptr.
    Node* next; ///< Wskaźnik na następny węzeł lub nullptr.
};

#endif
