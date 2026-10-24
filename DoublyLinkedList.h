/**
 * @file DoublyLinkedList.h
 * @brief Deklaracja listy dwukierunkowej liczb całkowitych.
 */
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <cstddef>
#include "Iterator.h"

class Node;

/**
 * @class DoublyLinkedList
 * @brief Lista dwukierunkowa z dostępem do obu końców oraz iteratorem.
 *
 * Klasa jest właścicielem swoich węzłów. Kopiowanie jest zabronione,
 * aby uniknąć wielokrotnego zwalniania tej samej pamięci.
 */
class DoublyLinkedList {
public:
    /** @brief Tworzy pustą listę. */
    DoublyLinkedList();
    /** @brief Zwalnia pamięć wszystkich węzłów. */
    ~DoublyLinkedList();

    /** @brief Kopiowanie listy jest zabronione. */
    DoublyLinkedList(const DoublyLinkedList&) = delete;
    /** @brief Przypisanie kopiujące jest zabronione. */
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    /**
     * @brief Dodaje element na początku listy.
     * @param value Wartość nowego elementu.
     */
    void addFront(int value);
    /**
     * @brief Dodaje element na końcu listy.
     * @param value Wartość nowego elementu.
     */
    void addBack(int value);
    /**
     * @brief Wstawia element pod wskazany indeks.
     * @param index Indeks od zera; wartość size() oznacza wstawienie na końcu.
     * @param value Wartość nowego elementu.
     * @throws std::out_of_range Gdy index jest większy niż rozmiar listy.
     */
    void insertAt(std::size_t index, int value);

    /** @brief Usuwa pierwszy element. @return true, jeśli usunięto element. */
    bool removeFront();
    /** @brief Usuwa ostatni element. @return true, jeśli usunięto element. */
    bool removeBack();
    /**
     * @brief Usuwa element pod wskazanym indeksem.
     * @param index Indeks elementu liczony od zera.
     * @return true, jeśli element istniał i został usunięty.
     */
    bool removeAt(std::size_t index);

    /** @brief Wyświetla elementy od początku do końca. */
    void displayForward() const;
    /** @brief Wyświetla elementy od końca do początku. */
    void displayBackward() const;

    /** @brief Przesuwa wewnętrzny kursor do następnego elementu i wyświetla go. @return true, jeśli znaleziono element. */
    bool showNext();
    /** @brief Przesuwa wewnętrzny kursor do poprzedniego elementu i wyświetla go. @return true, jeśli znaleziono element. */
    bool showPrevious();

    /** @brief Usuwa wszystkie elementy i zeruje stan listy. */
    void clear();
    /** @brief Zwraca liczbę elementów. @return Aktualny rozmiar listy. */
    std::size_t size() const;
    /** @brief Sprawdza, czy lista jest pusta. @return true, jeśli lista nie zawiera elementów. */
    bool empty() const;

    /** @brief Tworzy iterator wskazujący pierwszy element. @return Iterator od początku listy. */
    Iterator iteratorFromFront() const;
    /** @brief Tworzy iterator wskazujący ostatni element. @return Iterator od końca listy. */
    Iterator iteratorFromBack() const;

private:
    Node* head; ///< Pierwszy węzeł listy.
    Node* tail; ///< Ostatni węzeł listy.
    Node* cursor; ///< Wewnętrzny kursor używany przez showNext/showPrevious.
    std::size_t count; ///< Liczba elementów w liście.

    /**
     * @brief Znajduje węzeł pod podanym indeksem.
     * @param index Indeks liczony od zera.
     * @return Wskaźnik na znaleziony węzeł.
     * @throws std::out_of_range Gdy indeks jest poza zakresem.
     */
    Node* nodeAt(std::size_t index) const;
};

#endif
