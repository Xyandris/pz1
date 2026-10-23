#include "DoublyLinkedList.h"
#include "Node.h"
#include <iostream>
#include <stdexcept>

DoublyLinkedList::DoublyLinkedList()
    : head(nullptr), tail(nullptr), cursor(nullptr), count(0) {}

DoublyLinkedList::~DoublyLinkedList() { clear(); }

void DoublyLinkedList::addFront(int value) {
    // TODO 1/2: utwórz węzeł i popraw wskaźniki head/tail.
    Node* node = new Node(value);
    node->next = head;
    if (head) head->prev = node;
    else tail = node;
    head = node;
    ++count;
}

void DoublyLinkedList::addBack(int value) {
    // TODO: zaimplementuj dodawanie na koniec listy.
}

void DoublyLinkedList::insertAt(std::size_t index, int value) {
    // TODO: sprawdź zakres i obsłuż wstawianie na początku, końcu oraz w środku.
    (void)index; (void)value;
}

bool DoublyLinkedList::removeFront() {
    // TODO: usuń pierwszy węzeł i popraw head/tail.
    return false;
}

bool DoublyLinkedList::removeBack() {
    // TODO: usuń ostatni węzeł i popraw head/tail.
    return false;
}

bool DoublyLinkedList::removeAt(std::size_t index) {
    // TODO: znajdź węzeł i usuń go, zachowując spójność wskaźników.
    (void)index;
    return false;
}

void DoublyLinkedList::displayForward() const {
    // TODO: wypisz elementy od head do tail.
}

void DoublyLinkedList::displayBackward() const {
    // TODO: wypisz elementy od tail do head.
}

bool DoublyLinkedList::showNext() {
    // TODO: przejdź kursorem do następnego elementu i wyświetl jego wartość.
    return false;
}

bool DoublyLinkedList::showPrevious() {
    // TODO: przejdź kursorem do poprzedniego elementu i wyświetl jego wartość.
    return false;
}

void DoublyLinkedList::clear() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = cursor = nullptr;
    count = 0;
}

std::size_t DoublyLinkedList::size() const { return count; }
bool DoublyLinkedList::empty() const { return count == 0; }

Iterator DoublyLinkedList::iteratorFromFront() const {
    // TODO: zwróć iterator wskazujący na pierwszy element.
    return Iterator();
}

Iterator DoublyLinkedList::iteratorFromBack() const {
    // TODO: zwróć iterator wskazujący na ostatni element.
    return Iterator();
}

Node* DoublyLinkedList::nodeAt(std::size_t index) const {
    // TODO: zaimplementuj wyszukiwanie od bliższego końca listy.
    (void)index;
    return nullptr;
}
