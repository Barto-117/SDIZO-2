#include "Kolejka.h"
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

void Kolejka::push(Krawedz j) {
	Krawedz* nowyWskaznik = new Krawedz[rozmiar + 1];
	for (int i = 0; i < rozmiar; i++) {
		nowyWskaznik[i] = wskaznik[i];
	}
	nowyWskaznik[rozmiar] = j;
	wskaznik = nowyWskaznik;
	doGory();
	rozmiar++;
}

Krawedz Kolejka::pop() {
	int k = 0;
	Krawedz x = wskaznik[k];
	Krawedz* nowyWskaznik = new Krawedz[rozmiar - 1];
	nowyWskaznik = wskaznik;
	nowyWskaznik[k] = wskaznik[rozmiar - 1];
	rozmiar--;
	wskaznik = nowyWskaznik;
	doDolu();
	return x;
}

void Kolejka::doDolu() {
	Krawedz temp;
	int k = 0;
	while (2 * k + 1 < rozmiar)
	{
		if (wskaznik[2 * k + 1].waga < wskaznik[2 * k + 2].waga) {
			temp = wskaznik[k];
			wskaznik[k] = wskaznik[2 * k + 1];
			wskaznik[2 * k + 1] = temp;
			k = 2 * k + 1;
		}
		else {
			temp = wskaznik[k];
			wskaznik[k] = wskaznik[2 * k + 2];
			wskaznik[2 * k + 2] = temp;
			k = 2 * k + 2;
		}
	}
}

void Kolejka::doGory() {
	Krawedz temp;
	int k = rozmiar - 1;
	while (wskaznik[k].waga > wskaznik[(k - 1) / 2].waga && k > 0)
	{
		temp = wskaznik[k];
		wskaznik[k] = wskaznik[(k - 1) / 2];
		wskaznik[(k - 1) / 2] = temp;
		k = (k - 1) / 2;
	}
}