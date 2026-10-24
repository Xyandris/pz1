/**
 * @file Iterator.h
 * @brief Deklaracja iteratora poruszającego się po liście w obu kierunkach.
 */
#ifndef ITERATOR_H
#define ITERATOR_H

class Node;

/**
 * @class Iterator
 * @brief Iterator wskazujący bieżący węzeł listy dwukierunkowej.
 *
 * Iterator nie zarządza pamięcią węzłów. Po usunięciu wskazywanego węzła
 * iterator może stać się nieprawidłowy.
 */
class Iterator {
public:
    /**
     * @brief Tworzy iterator.
     * @param current Węzeł początkowy; domyślnie nullptr.
     */
    explicit Iterator(Node* current = nullptr);

    /** @brief Sprawdza, czy iterator wskazuje na węzeł dostępny przez next(). @return true, jeśli istnieje bieżący węzeł. */
    bool hasNext() const;
    /** @brief Sprawdza, czy iterator wskazuje na węzeł dostępny przez previous(). @return true, jeśli istnieje bieżący węzeł. */
    bool hasPrevious() const;

    /**
     * @brief Pobiera wartość bieżącego węzła i przesuwa iterator do przodu.
     * @return Wartość bieżącego węzła.
     * @throws std::out_of_range Gdy iterator nie wskazuje na żaden węzeł.
     */
    int next();

    /**
     * @brief Pobiera wartość bieżącego węzła i przesuwa iterator do tyłu.
     * @return Wartość bieżącego węzła.
     * @throws std::out_of_range Gdy iterator nie wskazuje na żaden węzeł.
     */
    int previous();

    /**
     * @brief Ustawia iterator na wskazanym węźle.
     * @param node Węzeł, na który ma wskazywać iterator; może być nullptr.
     */
    void set(Node* node);

private:
    Node* current; ///< Aktualnie wskazywany węzeł.
};

#endif
