#include "ListFactory.h"
#include "DoublyLinkedList.h"

DoublyLinkedList* ListFactory::createList() {
    return new DoublyLinkedList();
}
