#include "Graf.h"
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

void Graf::usun() {
	for (int i = 0; i < liczbaW; i++) 
	{
		delete[] macierz[i];
		delete[] lista[i];
	}
	delete[] zbiorK;
	liczbaW = 0;
	liczbaK = 0;
}

void Graf::plikMST(string nazwa) {
	ifstream plik;
	plik.open(nazwa);
	int i = 0;
	if (plik.is_open()) {
		plik >> liczbaK;
		plik >> liczbaW;
		zbiorK = new Krawedz[liczbaK];
		while (plik.good()) {
			plik >> zbiorK[i].poczatek;
			plik >> zbiorK[i].koniec;
			plik >> zbiorK[i].waga;
			i++;
		}
		plik.close();
	}
}

void Graf::losowoSK(int v, int g){
	liczbaW = v;
	macierz = new int* [liczbaW];
	bool* odwiedzone = new bool[liczbaW];
	for (int i = 0; i < liczbaW; i++)
	{
		macierz[i] = new int[liczbaW];
		for (int j = 0; j < liczbaW; j++)
		{
			macierz[i][j] = 0;
		}
	}
	srand(time(NULL));
	for (int i = 0; i < liczbaW; i++)
	{
		odwiedzone[i] = false;
	}
	liczbaK = (g * liczbaW * (liczbaW - 1)) / 100;
	int i = 0;
	int w = 0;
	int s = 1;
	odwiedzone[w] = true;
	while(i < liczbaW - 1)
	{
		if (w != s && odwiedzone[s] != true) {
			odwiedzone[s] = true;
			macierz[w][s] = rand() % 100 + 1;
			w = s;
			i++;
		}
		s = rand() % liczbaW;
	}
	i = liczbaW - 1;
	while(i < liczbaK)
	{
		if (macierz[w = rand() % liczbaW][s = rand() % liczbaW] == 0 && w != s)
		{
			macierz[w][s] = rand() % 100 + 1;
			i++;
		}
	}
	int k = 0;
	zbiorK = new Krawedz[liczbaK];
	for (int i = 0; i < liczbaW; i++)
	{
		for (int j = 0; j < liczbaW; j++)
		{
			if (macierz[i][j] != 0)
			{
				zbiorK[k].poczatek = i;
				zbiorK[k].koniec = j;
				zbiorK[k].waga = macierz[i][j];
				k++;
			}
		}
	}
	delete[] odwiedzone;
}

void Graf::losowoMST(int v, int g) {
	liczbaW = v;
	macierz = new int* [liczbaW];
	bool* odwiedzone = new bool[liczbaW];
	for (int i = 0; i < liczbaW; i++)
	{
		macierz[i] = new int[liczbaW];
		for (int j = 0; j < liczbaW; j++)
		{
			macierz[i][j] = 0;
		}
	}
	int w = 0;
	odwiedzone[w] = true;
	int s = rand() % liczbaW;
	srand(time(NULL));
	liczbaK = (g * liczbaW * (liczbaW - 1)) / 200;
	zbiorK = new Krawedz[liczbaK];
	int i = 0;
	while (i < liczbaW - 1)
	{
		if (s != w && odwiedzone[s] != true)
		{
			odwiedzone[s] = true;
			macierz[w][s] = rand() % 100 + 1;
			macierz[s][w] = macierz[w][s];
			w = s;
			i++;
		}
		s = rand() % liczbaW;
		
	}
	delete[] odwiedzone;
	while (i < liczbaK)
	{
		if (macierz[w = rand() % liczbaW][s = rand() % liczbaW] == 0 && w != s)
		{
			macierz[w][s] = rand() % 100 + 1;
			macierz[s][w] = macierz[w][s];
			i++;
		}
	}

	int k = 0;
	for (int i = 0; i < liczbaW; i++)
	{
		for (int j = i; j < liczbaW; j++)
		{
			if (macierz[i][j] != 0)
			{
				zbiorK[k].poczatek = i;
				zbiorK[k].koniec = j;
				zbiorK[k].waga = macierz[i][j];
				k++;
			}
		}
	}
}

int Graf::plikSK(string nazwa) {
	ifstream plik;
	plik.open(nazwa);
	int i = 0;
	int x;
	if (plik.is_open()) {
		plik >> liczbaK;
		plik >> liczbaW;
		plik >> x;
		zbiorK = new Krawedz[liczbaK];
		while (plik.good()) {
			plik >> zbiorK[i].poczatek;
			plik >> zbiorK[i].koniec;
			plik >> zbiorK[i].waga;
			i++;
		}
		plik.close();
	}
	return x;
}

void Graf::stworzMacierz() {
	macierz = new int* [liczbaW];
	int x = 0;
	for (int i = 0; i < liczbaW; i++)
	{
		macierz[i] = new int[liczbaW];
		for (int j = 0; j < liczbaW; j++)
		{
			macierz[i][j] = 0;
		}
	}
	for(int i = 0; i < liczbaW; i++) 
	{
		for (int j = 0; j < liczbaW; j++) 
		{
			if (zbiorK[x].poczatek == i && zbiorK[x].koniec == j) {
				macierz[i][j] = zbiorK[x].waga;
				macierz[j][i] = zbiorK[x].waga;
				x++;
			}
		}
	}
}

void Graf::stworzMacierzSK() {
	macierz = new int* [liczbaW];
	int x = 0;
	for (int i = 0; i < liczbaW; i++)
	{
		macierz[i] = new int[liczbaW];
		for (int j = 0; j < liczbaW; j++)
		{
			macierz[i][j] = 0;
		}
	}
	for (int i = 0; i < liczbaK; i++)
	{
		macierz[zbiorK[i].poczatek][zbiorK[i].koniec] = zbiorK[i].waga;
	}
}

void Graf::stworzListe() {
	lista = new int* [liczbaW];
	for (int i = 0; i < liczbaW; i++) 
	{
		int y = 1;
		int x = 0;
		for (int j = 0; j < liczbaW; j++)
		{
			if (macierz[i][j] != 0) {
				x++;
			}
		}
		lista[i] = new int[2 * x + 1];
		lista[i][0] = x;
		for (int j = 0; j < liczbaW; j++)
		{
			if (macierz[i][j] != 0)
			{
				lista[i][y] = j;
				lista[i][y + 1] = macierz[i][j];
				y+=2;
			}
		}
	}
}

void Graf::primM()
{
	Krawedz* drzewo = new Krawedz[liczbaW - 1];
	kolejka = new Krawedz[liczbaK];
	Krawedz minK;
	bool* odwiedzone = new bool[liczbaW];
	int y = 0;
	int wagaD = 0;
	int v = 0;
	for (int i = 0; i < liczbaW; i++)
	{
		odwiedzone[i] = false;
	}
	for (int j = 0; j < liczbaW - 1; j++)
	{
		odwiedzone[v] = true;
		for (int i = 0; i < liczbaW; i++)
		{
			if (macierz[v][i] != 0 && odwiedzone[i] != true)
			{
				kolejka[y].poczatek = v;
				kolejka[y].koniec = i;
				kolejka[y].waga = macierz[v][i];
				y++;
			}
		}
		int i;
		for (i = 0; i < y; i++)
		{
			if (odwiedzone[kolejka[i].koniec] != true && odwiedzone[kolejka[i].poczatek] == true) {
				minK = kolejka[i];
				v = kolejka[i].koniec;
				break;
			}
		}
		for (; i < y; i++)
		{
			if (minK.waga > kolejka[i].waga && odwiedzone[kolejka[i].koniec] != true)
			{
				minK = kolejka[i];
				v = kolejka[i].koniec;
			}
		}
		drzewo[j] = minK;
	}
	/*cout << endl << "Prim macierz: " << endl;
	for (int i = 0; i < liczbaW - 1; i++) 
	{
		wagaD = drzewo[i].waga + wagaD;
		cout << drzewo[i].poczatek << " - ";
		cout << drzewo[i].koniec << " - ";
		cout << drzewo[i].waga;
		cout << endl;
	}
	cout << wagaD << endl;*/
	delete[] drzewo;
	delete[] kolejka;
	delete[] odwiedzone;
}

void Graf::primL()
{
	Krawedz* drzewo = new Krawedz[liczbaW - 1];
	kolejka = new Krawedz[liczbaK];
	Krawedz minK;
	bool* odwiedzone = new bool[liczbaW];
	int y = 0;
	int v = 0;
	int wagaD = 0;
	for (int i = 0; i < liczbaW; i++)
	{
		odwiedzone[i] = false;
	}
	for (int j = 0; j < liczbaW - 1; j++)
	{
		odwiedzone[v] = true;
		for (int i = 0; i < lista[v][0]; i++)
		{
			if (odwiedzone[lista[v][2 * i + 1]] != true)
			{
				kolejka[y].poczatek = v;
				kolejka[y].koniec = lista[v][2 * i + 1];
				kolejka[y].waga = lista[v][2 * i + 2];
				y++;
			}
		}
		int i;
		for (i = 0; i < y; i++)
		{
			if (odwiedzone[kolejka[i].koniec] != true && odwiedzone[kolejka[i].poczatek] == true) {
				minK = kolejka[i];
				v = kolejka[i].koniec;
				break;
			}
		}
		for (; i < y; i++)
		{
			if (minK.waga > kolejka[i].waga && odwiedzone[kolejka[i].koniec] != true)
			{
				minK = kolejka[i];
				v = kolejka[i].koniec;
			}
		}
		drzewo[j] = minK;
	}
	cout << endl << "Prim lista: " << endl;
	for (int i = 0; i < liczbaW - 1; i++)
	{
		wagaD = drzewo[i].waga + wagaD;
		cout << drzewo[i].poczatek << " - ";
		cout << drzewo[i].koniec << " - ";
		cout << drzewo[i].waga;
		cout << endl;
	}
	cout << wagaD << endl;
	delete[] drzewo;
	delete[] kolejka;
	delete[] odwiedzone;
}

void Graf::kruskalM()
{
	drzewo = new Krawedz[liczbaW - 1];
	kolejka = new Krawedz[liczbaK];
	Krawedz minK;
	int y = 0;
	int x = 0;
	tab = new int[liczbaW];
	for (int i = 0; i < liczbaW; i++)
	{
		tab[i] = i;
	}
	for (int i = 0; i < liczbaW; i++)
	{
		for (int j = i; j < liczbaW; j++) {
			if (macierz[i][j] != 0) {
				kolejka[y].poczatek = i;
				kolejka[y].koniec = j;
				kolejka[y].waga = macierz[i][j];
				kolejka[y].uzyta = false;
				y++;
			}
		}
	}
	for (int j = 0; j < liczbaW - 1; j++) //k07
	{
		for (int i = 0; i < liczbaK; i++)
		{
			if (kolejka[i].uzyta == false)
			{
				minK = kolejka[i];
				x = i;
				break;
			}
		}
		for (int i = 0; i < liczbaK; i++)
		{
			if (minK.waga > kolejka[i].waga && kolejka[i].uzyta != true)
			{
				if (tab[kolejka[i].poczatek] == tab[kolejka[i].koniec]) //k09
				{
					kolejka[i].uzyta = true;
				}
				else
				{
					minK = kolejka[i];
					x = i;
				}	
			}
		} //k08
		kolejka[x].uzyta = true;
		drzewo[j] = kolejka[x]; //k10
		//kruskalRekM(kolejka[x].koniec, tab[kolejka[x].poczatek], tab[kolejka[x].koniec]); //k011
		//tab[kolejka[x].koniec] = tab[kolejka[x].poczatek];
		int temp = tab[kolejka[x].koniec];
		for (int i = 0; i < liczbaW; i++)
		{
			if (tab[i] == temp)
			{
				tab[i] = tab[kolejka[x].poczatek];
			}
		}
	}
	cout << endl << "Kruskal macierz: " << endl;
	int wagaD = 0;
	for (int i = 0; i < liczbaW - 1; i++)
	{
		wagaD = drzewo[i].waga + wagaD;
		cout << drzewo[i].poczatek << " - ";
		cout << drzewo[i].koniec << " - ";
		cout << drzewo[i].waga;
		cout << endl;
	}
	cout << wagaD << endl;
	delete[] drzewo;
	delete[] kolejka;
	delete[] tab;
}

void Graf::kruskalL()
{
	drzewo = new Krawedz[liczbaW - 1];
	kolejka = new Krawedz[liczbaK];
	Krawedz minK;
	int x = 0;
	int y = 0;
	tab = new int[liczbaW];
	for (int i = 0; i < liczbaW; i++)
	{
		tab[i] = i;
	}
	for (int i = 0; i < liczbaK; i++)
	{
		{
			kolejka[y].poczatek = zbiorK[i].poczatek;
			kolejka[y].koniec = zbiorK[i].koniec;
			kolejka[y].waga = zbiorK[i].waga;
			kolejka[y].uzyta = false;
			y++;
		}
	}
	for (int j = 0; j < liczbaW - 1; j++) //k07
	{
		for (int i = 0; i < liczbaK; i++)
		{
			if (kolejka[i].uzyta == false)
			{
				minK = kolejka[i];
				x = i;
				break;
			}
		}
		for (int i = 0; i < liczbaK; i++)
		{
			if (minK.waga > kolejka[i].waga && kolejka[i].uzyta != true)
			{
				if (tab[kolejka[i].poczatek] == tab[kolejka[i].koniec]) //k09
				{
					kolejka[i].uzyta = true;
				}
				else
				{
					minK = kolejka[i];
					x = i;
				}
			}
		} //k08
		kolejka[x].uzyta = true;
		drzewo[j] = kolejka[x]; //k10
		int temp = tab[kolejka[x].koniec];
		for (int i = 0; i < liczbaW; i++)
		{
			if (tab[i] == temp)
			{
				tab[i] = tab[kolejka[x].poczatek];
			}
		}
	}
	cout << endl << "Kruskal lista: " << endl;
	int wagaD = 0;
	for (int i = 0; i < liczbaW - 1; i++)
	{
		wagaD = drzewo[i].waga + wagaD;
		cout << drzewo[i].poczatek << " - ";
		cout << drzewo[i].koniec << " - ";
		cout << drzewo[i].waga;
		cout << endl;
	}
	cout << wagaD << endl;
	delete[] drzewo;
	delete[] kolejka;
	delete[] tab;
}

void Graf::wyswietl()
{
	cout << " ";
	for (int i = 0; i < liczbaW; i++) 
	{
		cout << " " << i;
	}
	cout << endl;
	for (int i = 0; i < liczbaW; i++)
	{
		cout << i;
		for (int j = 0; j < liczbaW; j++)
		{
			cout << " " << macierz[i][j];
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < liczbaW; i++) 
	{
		int x = 0;
		cout << i;
		int y = 1;
		for (int j = 0; j < lista[i][0]; j++) 
		{
			cout << "-->" << " [ " << lista[i][y] << " | " << lista[i][y + 1] << " ] ";
			y+=2;
		}
		cout << endl;
	}
}

bool Graf::bellmanM(int v) {
	bool test = false;
	int* tabWag = new int[liczbaW];
	int* tab = new int[liczbaW];
	for (int i = 0; i < liczbaW; i++)
	{
		tabWag[i] = 1000;
		tab[i] = -1;
	}
	tabWag[v] = 0;
	for (int s = 0; s < liczbaW - 1 && test == false; s++)
	{
		test = true;
		for (int i = 0; i < liczbaW; i++)
		{
			for (int j = 0; j < liczbaW; j++)
			{
				if (macierz[i][j] != 0) {
					if (tabWag[j] <= (tabWag[i] + macierz[i][j])) {
					}
					else {
						test = false;
						tabWag[j] = (tabWag[i] + macierz[i][j]);
						tab[j] = i;
					}
				}
			}
		}
		/*if (test == true)
		{
			tabWag = NULL;
			tab = NULL;
			return true;
		}*/
	}
	for (int i = 0; i < liczbaW; i++)
	{
		for (int j = 0; j < liczbaW; j++)
		{
			if (macierz[i][j] != 0) {
				if (tabWag[j] > (tabWag[i] + macierz[i][j])) {
					delete[] tabWag;
					delete[] tab;
					return false;
				}
			}
		}
	}
	for (int x = 0; x < liczbaW; x++)
	{
		cout << tab[x] << "  ";
	}
	cout << endl;
	for (int x = 0; x < liczbaW; x++)
	{
		cout << tabWag[x] << "  ";
	}
	cout << endl;
	delete[] tabWag;
	delete[] tab;
	return true;
}

bool Graf::bellmanL(int v) {
	bool test = false;
	int* tabWag = new int[liczbaW];
	int* tab = new int[liczbaW];
	for (int i = 0; i < liczbaW; i++)
	{
		tabWag[i] = 1000;
		tab[i] = -1;
	}
	tabWag[v] = 0;
	for (int s = 0; s < liczbaW - 2 && test == false; s++)
	{
		test = true;
		for (int i = 0; i < liczbaW; i++)
		{
			for (int j = 0; j < 2 * lista[i][0]; j += 2)
			{
				if (tabWag[lista[i][j + 1]] <= (tabWag[i] + lista[i][j + 2])) {
				}
				else {
					test = false;
					tabWag[lista[i][j + 1]] = (tabWag[i] + lista[i][j + 2]);
					tab[lista[i][j + 1]] = i;
				}
			}
		}
	}
	for (int i = 0; i < liczbaW; i++)
	{
		for (int j = 0; j < 2 * lista[i][0]; j += 2)
		{
			if (lista[i][j + 2] != 0) {
				if (tabWag[lista[i][j + 1]] > (tabWag[i] + lista[i][j + 2])) {
					delete[] tabWag;
					delete[] tab;
					return false;
				}
			}
		}
	}
	for (int x = 0; x < liczbaW; x++)
	{
		cout << tab[x] << "  ";
	}
	cout << endl;
	for (int x = 0; x < liczbaW; x++)
	{
		cout << tabWag[x] << "  ";
	}
	cout << endl;
	delete[] tabWag;
	delete[] tab;
	return true;
}

void Graf::dijkstraM(int v) {
	int minW;
	int x = 0;
	int y = liczbaW;
	/*int* sprawdzone = new int[x];
	int* nieSprawdzone = new int[y];*/
	bool* sprawdzone = new bool[liczbaW];
	int* tabWag = new int[liczbaW];
	int* tab = new int[liczbaW];
	for (int i = 0; i < liczbaW; i++)
	{
		sprawdzone[i] = false;
		tabWag[i] = 1000;
		tab[i] = -1;
	}
	tabWag[v] = 0;
	int indeks;
	for (int i = 0; i < liczbaW; i++) //k08
	{
		indeks = 0;
		int j = 0;
		while (true)
		{
			if (sprawdzone[j] == false) {
				indeks = j;
				break;
			}
			j++;
		}
		for (int j = 0; j < liczbaW; j++) {
			if (tabWag[indeks] > tabWag[j] && sprawdzone[j] == false)
			{
				indeks = j;
			}
		}
		sprawdzone[indeks] = true;
		//koniec k09
		for (int j = 0; j < liczbaW; j++) //wierzcho³ek którego s¹siadów badamy to i
		{
			if (macierz[indeks][j] != 0 && sprawdzone[j] == false)
			{
				if (tabWag[j] > tabWag[indeks] + macierz[indeks][j])
				{
					tabWag[j] = tabWag[indeks] + macierz[indeks][j];
					tab[j] = indeks;
				}
			}
		}
	}
	for (int x = 0; x < liczbaW; x++)
	{
		cout << tab[x] << "  ";
	}
	cout << endl;
	for (int x = 0; x < liczbaW; x++)
	{
		cout << tabWag[x] << "  ";
	}
	cout << endl;
	delete[] sprawdzone;
}

void Graf::dijkstraL(int v) {
	int minW;
	bool* sprawdzone = new bool[liczbaW];
	int* tabWag = new int[liczbaW];
	int* tab = new int[liczbaW];
	for (int i = 0; i < liczbaW; i++)
	{
		sprawdzone[i] = false;
		tabWag[i] = 1000;
		tab[i] = -1;
	}
	tabWag[v] = 0;
	int indeks;
	for (int i = 0; i < liczbaW; i++) //k08
	{
		indeks = 0;
		int j = 0;
		while (true)
		{
			if (sprawdzone[j] == false) {
				indeks = j;
				break;
			}
			j++;
		}
		for (int j = 0; j < liczbaW; j++) {
			if (tabWag[indeks] > tabWag[j] && sprawdzone[j] == false)
			{
				indeks = j;
			}
		}
		sprawdzone[indeks] = true;
		//koniec k09
		for (int j = 0; j < 2 * lista[indeks][0]; j+=2) //wierzcho³ek którego s¹siadów badamy zaczyna siê w --> sprawdzone[x-1]
		{
			if (sprawdzone[lista[indeks][j + 1]] == false)
			{
				if (tabWag[lista[indeks][j + 1]] > tabWag[indeks] + lista[indeks][j + 2])
				{
					tabWag[lista[indeks][j + 1]] = tabWag[indeks] + lista[indeks][j + 2];
					tab[lista[indeks][j + 1]] = indeks;
				}
			}
		}
	}
	for (int x = 0; x < liczbaW; x++)
	{
		cout << tab[x] << "  ";
	}
	cout << endl;
	for (int x = 0; x < liczbaW; x++)
	{
		cout << tabWag[x] << "  ";
	}
	cout << endl;
	delete[] sprawdzone;
	delete[] tab;
	delete[] tabWag;
}