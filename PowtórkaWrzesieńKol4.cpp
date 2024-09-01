#include <iostream>
#include "Fun.h"


int main()
{
    char nazwisko = 'Z';  
    int rozmiar = static_cast<int>(nazwisko);

    // Tworzenie instancji wzorcowej
    Alokacja prototyp = { 42, 3.14 };

    Alokacja* tab = alokuj(rozmiar, prototyp);

    // Zapis tablicy do pliku binarnego
    zapisz(tab, rozmiar, "test.txt");

    // Odczyt tablicy z pliku binarnego
    int nowyRozmiar;
    Alokacja* tab2 = odczytaj("test.txt", nowyRozmiar);

    bool czyTakieSame = false;
    if (rozmiar == nowyRozmiar) {
        czyTakieSame = (memcmp(tab, tab2, rozmiar * sizeof(Alokacja)) == 0);
    }

    // Wyświetlenie wyniku porównania
    if (czyTakieSame) {
        cout << "Odczytana tablica jest identyczna z zapisana." << endl;
    }
    else {
        cout << "Odczytana tablica NIE jest identyczna z zapisana." << endl;
    }

    // Zwolnienie pamięci
    delete[] tab;
    delete[] tab2;
}
