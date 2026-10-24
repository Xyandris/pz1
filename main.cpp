/**
 * @file main.cpp
 * @brief Interaktywne menu demonstracyjne listy dwukierunkowej.
 */
#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>

#include "DoublyLinkedList.h"
#include "ListFactory.h"

using namespace std;

int main() {
    // Factory tworzy obiekt, a unique_ptr bezpiecznie zarządza jego życiem.
    unique_ptr<DoublyLinkedList> lista(ListFactory::createList());

    int wybor;
    do {
        cout << "\n--- LISTA DWUKIERUNKOWA ---\n"
             << "1. Dodaj na poczatek\n"
             << "2. Dodaj na koniec\n"
             << "3. Dodaj pod indeks\n"
             << "4. Usun z poczatku\n"
             << "5. Usun z konca\n"
             << "6. Usun pod indeks\n"
             << "7. Wyswietl od poczatku\n"
             << "8. Wyswietl odwrotnie\n"
             << "9. Przejdz iteratorem do nastepnego elementu\n"
             << "10. Przejdz iteratorem do poprzedniego elementu\n"
             << "11. Wyczysc liste\n"
             << "0. Koniec\n"
             << "Wybor: ";

        if (!(cin >> wybor)) {
            cout << "Nieprawidlowe dane.\n";
            return 1;
        }

        int wartosc;
        size_t indeks;

        try {
            switch (wybor) {
            case 1:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                lista->addFront(wartosc);
                break;
            case 2:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                lista->addBack(wartosc);
                break;
            case 3:
                cout << "Podaj indeks (0-" << lista->size() << "): ";
                cin >> indeks;
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                lista->insertAt(indeks, wartosc);
                break;
            case 4:
                cout << (lista->removeFront() ? "Usunieto element.\n" : "Lista jest pusta.\n");
                break;
            case 5:
                cout << (lista->removeBack() ? "Usunieto element.\n" : "Lista jest pusta.\n");
                break;
            case 6:
                cout << "Podaj indeks: ";
                cin >> indeks;
                cout << (lista->removeAt(indeks) ? "Usunieto element.\n" : "Brak elementu pod tym indeksem.\n");
                break;
            case 7:
                lista->displayForward();
                break;
            case 8:
                lista->displayBackward();
                break;
            case 9: {
                // Prosty, niezależny iterator demonstracyjny: zaczyna od początku.
                Iterator it = lista->iteratorFromFront();
                if (!it.hasNext()) cout << "Lista jest pusta.\n";
                else cout << "Nastepny element: " << it.next() << '\n';
                break;
            }
            case 10: {
                Iterator it = lista->iteratorFromBack();
                if (!it.hasPrevious()) cout << "Lista jest pusta.\n";
                else cout << "Poprzedni element: " << it.previous() << '\n';
                break;
            }
            case 11:
                lista->clear();
                cout << "Lista wyczyszczona.\n";
                break;
            case 0:
                cout << "Koniec programu.\n";
                break;
            default:
                cout << "Nieznana opcja.\n";
            }
        } catch (const exception& e) {
            cout << "Blad: " << e.what() << '\n';
        }

    } while (wybor != 0);

    return 0;
}
