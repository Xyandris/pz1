/**
 * @file ListFactory.h
 * @brief Deklaracja prostej fabryki list dwukierunkowych.
 */
#ifndef LIST_FACTORY_H
#define LIST_FACTORY_H

class DoublyLinkedList;

/**
 * @class ListFactory
 * @brief Udostępnia metodę tworzącą nową listę.
 */
class ListFactory {
public:
    /**
     * @brief Tworzy nowy obiekt listy na stercie.
     * @return Wskaźnik na nową listę; wywołujący odpowiada za jej usunięcie.
     */
    static DoublyLinkedList* createList();
};

#endif
