#include "Fun.h"
#include <iostream>
#include <fstream>
#include <cstring>

Alokacja* alokuj(int rozmiar, Alokacja& prototyp) 
{
    Alokacja* tab = new Alokacja[rozmiar];

    for (int i = 0; i < rozmiar; ++i) {
       tab[i] = prototyp;
    }

    return tab;
}

void zapisz(const Alokacja* tab, int rozmiar, const char* nazwaPliku) {
    FILE* plik = fopen(nazwaPliku, "w");
    if (!plik) {
        cerr << "B³¹d przy otwieraniu pliku do zapisu!" << endl;
        return;
    }
    // Zapisujemy rozmiar tablicy
    fwrite(&rozmiar, sizeof(int), 1, plik);

    // Zapisujemy elementy tablicy
    fwrite(tab, sizeof(Alokacja), rozmiar, plik);

    fclose(plik);
}

Alokacja* odczytaj(const char* nazwaPliku, int& rozmiar) {
    FILE* plik = fopen(nazwaPliku, "r");
    if (!plik) {
        cerr << "B³¹d przy otwieraniu pliku do odczytu!" << endl;
        rozmiar = 0;
        return nullptr;
    }

    fread(&rozmiar, sizeof(int), 1, plik);

    Alokacja* tab = new Alokacja[rozmiar];

    fread(tab, sizeof(Alokacja), rozmiar, plik);

    fclose(plik);
    return tab;
}