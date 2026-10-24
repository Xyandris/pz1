/**
 * @file ListFactory.cpp
 * @brief Implementacja fabryki listy.
 */
#include "ListFactory.h"
#include "DoublyLinkedList.h"

DoublyLinkedList* ListFactory::createList() {
    return new DoublyLinkedList();
}
