#include "Iterator.h"
#include "Node.h"
#include <stdexcept>

Iterator::Iterator(Node* current) : current(current) {}

bool Iterator::hasNext() const {
    return current != nullptr;
}

bool Iterator::hasPrevious() const {
    return current != nullptr;
}

int Iterator::next() {
    if (!current) {
        throw std::out_of_range("Iterator nie wskazuje na element.");
    }

    int result = current->value;
    current = current->next;
    return result;
}

int Iterator::previous() {
    if (!current) {
        throw std::out_of_range("Iterator nie wskazuje na element.");
    }

    int result = current->value;
    current = current->prev;
    return result;
}

void Iterator::set(Node* node) {
    current = node;
}
