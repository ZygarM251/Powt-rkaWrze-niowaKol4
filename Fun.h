#pragma once

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

struct Alokacja
{
	int pole1;
	double pole2;
};

Alokacja* alokuj(int rozmiar, Alokacja& prototyp);
void zapisz(const Alokacja* tab, int rozmiar, const char* nazwaPliku);


Alokacja* odczytaj(const char* nazwaPliku, int& rozmiar);