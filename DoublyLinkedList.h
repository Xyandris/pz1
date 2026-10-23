#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <cstddef>
#include "Iterator.h"

class Node;

class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Lista zarządza pamięcią, dlatego kopiowanie jest wyłączone.
    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    void addFront(int value);
    void addBack(int value);
    void insertAt(std::size_t index, int value);

    bool removeFront();
    bool removeBack();
    bool removeAt(std::size_t index);

    void displayForward() const;
    void displayBackward() const;

    // Operacje wyświetlające kolejny/poprzedni element kursora.
    bool showNext();
    bool showPrevious();

    void clear();

    std::size_t size() const;
    bool empty() const;

    Iterator iteratorFromFront() const;
    Iterator iteratorFromBack() const;

private:
    Node* head;
    Node* tail;
    Node* cursor;
    std::size_t count;

    Node* nodeAt(std::size_t index) const;
};

#endif
