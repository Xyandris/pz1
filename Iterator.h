#ifndef ITERATOR_H
#define ITERATOR_H

class Node;

class Iterator {
public:
    explicit Iterator(Node* current = nullptr);

    bool hasNext() const;
    bool hasPrevious() const;

    // Zwraca wartość bieżącego elementu i przesuwa iterator do przodu.
    int next();

    // Zwraca wartość bieżącego elementu i przesuwa iterator do tyłu.
    int previous();

    // Ustawia iterator na konkretnym węźle.
    void set(Node* node);

private:
    Node* current;
};

#endif
