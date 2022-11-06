#pragma once
#include "Wierzcholek.h"
#include "Krawedz.h"
#include <iostream>
#include <stdio.h>
#include "Kolejka.h"

using namespace std;

class Graf
{
public:
	Krawedz* zbiorK;
	Krawedz* kolejka;
	Krawedz* drzewo;
	int liczbaW;
	int liczbaK;
	int* tab;
	int** macierz;
	int** lista;
	
	void usun();

	void plikMST(string nazwa);

	int plikSK(string nazwa);

	void losowoMST(int v, int g);

	void losowoSK(int v, int g);

	void stworzMacierz();

	void stworzMacierzSK();

	void stworzListe();

	void primM();

	void primL();

	void kruskalRekM(int w, int id, int pop);

	void kruskalRekL(int w, int id, int pop);

	void kruskalM();

	void kruskalL();

	bool bellmanM(int v);

	bool bellmanL(int v);

	void dijkstraM(int v);

	void dijkstraL(int v);

	void wyswietl();
};

