/**
 * @file DoublyLinkedList.cpp
 * @brief Implementacja operacji listy dwukierunkowej.
 */
#include "DoublyLinkedList.h"
#include "Node.h"
#include <iostream>
#include <stdexcept>

DoublyLinkedList::DoublyLinkedList()
    : head(nullptr), tail(nullptr), cursor(nullptr), count(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::addFront(int value) {
    Node* node = new Node(value);
    node->next = head;

    if (head) {
        head->prev = node;
    } else {
        tail = node;
    }

    head = node;
    ++count;
}

void DoublyLinkedList::addBack(int value) {
    Node* node = new Node(value);
    node->prev = tail;

    if (tail) {
        tail->next = node;
    } else {
        head = node;
    }

    tail = node;
    ++count;
}

void DoublyLinkedList::insertAt(std::size_t index, int value) {
    if (index > count) {
        throw std::out_of_range("Indeks poza zakresem listy.");
    }

    if (index == 0) {
        addFront(value);
        return;
    }

    if (index == count) {
        addBack(value);
        return;
    }

    Node* nextNode = nodeAt(index);
    Node* prevNode = nextNode->prev;
    Node* node = new Node(value);

    node->prev = prevNode;
    node->next = nextNode;
    prevNode->next = node;
    nextNode->prev = node;
    ++count;
}

bool DoublyLinkedList::removeFront() {
    if (!head) {
        return false;
    }

    Node* oldHead = head;
    head = head->next;

    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }

    delete oldHead;
    --count;
    return true;
}

bool DoublyLinkedList::removeBack() {
    if (!tail) {
        return false;
    }

    Node* oldTail = tail;
    tail = tail->prev;

    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }

    delete oldTail;
    --count;
    return true;
}

bool DoublyLinkedList::removeAt(std::size_t index) {
    if (index >= count) {
        return false;
    }

    if (index == 0) {
        return removeFront();
    }

    if (index == count - 1) {
        return removeBack();
    }

    Node* node = nodeAt(index);
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    --count;
    return true;
}

void DoublyLinkedList::displayForward() const {
    std::cout << "Lista od poczatku: ";
    Node* current = head;

    while (current) {
        std::cout << current->value;
        if (current->next) std::cout << " <-> ";
        current = current->next;
    }

    if (!head) std::cout << "(pusta)";
    std::cout << '\n';
}

void DoublyLinkedList::displayBackward() const {
    std::cout << "Lista od konca: ";
    Node* current = tail;

    while (current) {
        std::cout << current->value;
        if (current->prev) std::cout << " <-> ";
        current = current->prev;
    }

    if (!tail) std::cout << "(pusta)";
    std::cout << '\n';
}

bool DoublyLinkedList::showNext() {
    if (!cursor) cursor = head;
    else cursor = cursor->next;

    if (!cursor) {
        std::cout << "Brak nastepnego elementu.\\n";
        return false;
    }

    std::cout << "Nastepny element: " << cursor->value << '\n';
    return true;
}

bool DoublyLinkedList::showPrevious() {
    if (!cursor) cursor = tail;
    else cursor = cursor->prev;

    if (!cursor) {
        std::cout << "Brak poprzedniego elementu.\\n";
        return false;
    }

    std::cout << "Poprzedni element: " << cursor->value << '\n';
    return true;
}

void DoublyLinkedList::clear() {
    Node* current = head;

    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    tail = nullptr;
    cursor = nullptr;
    count = 0;
}

std::size_t DoublyLinkedList::size() const {
    return count;
}

bool DoublyLinkedList::empty() const {
    return count == 0;
}

Iterator DoublyLinkedList::iteratorFromFront() const {
    return Iterator(head);
}

Iterator DoublyLinkedList::iteratorFromBack() const {
    return Iterator(tail);
}

Node* DoublyLinkedList::nodeAt(std::size_t index) const {
    if (index >= count) {
        throw std::out_of_range("Indeks poza zakresem listy.");
    }

    if (index < count / 2) {
        Node* current = head;
        for (std::size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current;
    }

    Node* current = tail;
    for (std::size_t i = count - 1; i > index; --i) {
        current = current->prev;
    }
    return current;
}
