#ifndef LIST_FACTORY_H
#define LIST_FACTORY_H

class DoublyLinkedList;

class ListFactory {
public:
    // Tworzy nową listę na stercie. Właściciel musi ją usunąć przez delete.
    static DoublyLinkedList* createList();
};

#endif
