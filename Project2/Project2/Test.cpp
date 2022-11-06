#include "Test.h"

void Test::testowanie()
{
	Czas czas;
	ofstream plikDM;
	Graf graf;
	int liczba[] = { 10, 20, 30, 40, 50, 60, 70 };
	int gestosci[] = { 20, 60, 99 };
	long srednia = 0;
	czas.czasStart();
	plikDM.open("bWyniki.txt");
	czas.czasStop();
	cout << czas.czasTrwania();
	for (int w = 0; w < 7; w++)
	{
		for (int g = 0; g < 3; g++)
		{
			plikDM << "gestosc " << gestosci[g] << " dla " << liczba[w] << " wierzcholkow, macierz, Dijkstra" << endl;
			for (int i = 0; i < 50; i++)
			{
				graf.losowoSK(liczba[w], gestosci[g]);
				graf.stworzListe();
				czas.czasStart();
				graf.dijkstraM(0);
				czas.czasStop();
				srednia = srednia + czas.czasTrwania();
				graf.usun();
			}
			srednia = srednia / 50;
			plikDM << srednia << endl;
			srednia = 0;
		}
	}

	for (int w = 0; w < 7; w++)
	{
		for (int g = 0; g < 3; g++)
		{
			plikDM << "gestosc " << gestosci[g] << " dla " << liczba[w] << " wierzcholkow, macierz, Ballman-Ford" << endl;
			for (int i = 0; i < 50; i++)
			{
				graf.losowoSK(liczba[w], gestosci[g]);
				graf.stworzListe();
				czas.czasStart();
				graf.bellmanM(0);
				czas.czasStop();
				srednia = srednia + czas.czasTrwania();
				graf.usun();
			}
			srednia = srednia / 50;
			plikDM << srednia << endl;
			srednia = 0;
		}
	}

	for (int w = 0; w < 7; w++)
	{
		for (int g = 0; g < 3; g++)
		{
			plikDM << "gestosc " << gestosci[g] << " dla " << liczba[w] << " wierzcholkow, macierz, Prim" << endl;
			for (int i = 0; i < 50; i++)
			{
				graf.losowoMST(liczba[w], gestosci[g]);
				graf.stworzListe();
				czas.czasStart();
				graf.primM();
				czas.czasStop();
				srednia = srednia + czas.czasTrwania();
				graf.usun();
			}
			srednia = srednia / 50;
			plikDM << srednia << endl;
			srednia = 0;
		}
	}

	for (int w = 0; w < 7; w++)
	{
		for (int g = 0; g < 3; g++)
		{
			plikDM << "gestosc " << gestosci[g] << " dla " << liczba[w] << " wierzcholkow, macierz, Kruskal" << endl;
			for (int i = 0; i < 50; i++)
			{
				graf.losowoMST(liczba[w], gestosci[g]);
				graf.stworzListe();
				czas.czasStart();
				graf.kruskalM();
				czas.czasStop();
				srednia = srednia + czas.czasTrwania();
				graf.usun();
			}
			srednia = srednia / 50;
			plikDM << srednia << endl;
			srednia = 0;
		}
	}

	for (int w = 0; w < 7; w++)
	{
		for (int g = 0; g < 3; g++)
		{
			plikDM << "gestosc " << gestosci[g] << " dla " << liczba[w] << " wierzcholkow, lista, Dijkstra" << endl;
			for (int i = 0; i < 50; i++)
			{
				graf.losowoSK(liczba[w], gestosci[g]);
				graf.stworzListe();
				czas.czasStart();
				graf.dijkstraL(0);
				czas.czasStop();
				srednia = srednia + czas.czasTrwania();
				graf.usun();
			}
			srednia = srednia / 50;
			plikDM << srednia << endl;
			srednia = 0;
		}
	}

	for (int w = 0; w < 7; w++)
	{
		for (int g = 0; g < 3; g++)
		{
			plikDM << "gestosc " << gestosci[g] << " dla " << liczba[w] << " wierzcholkow, lista, Bellman-Ford" << endl;
			for (int i = 0; i < 50; i++)
			{
				graf.losowoSK(liczba[w], gestosci[g]);
				graf.stworzListe();
				czas.czasStart();
				graf.bellmanL(0);
				czas.czasStop();
				srednia = srednia + czas.czasTrwania();
				graf.usun();
			}
			srednia = srednia / 50;
			plikDM << srednia << endl;
			srednia = 0;
		}
	}

	for (int w = 0; w < 7; w++)
	{
		for (int g = 0; g < 3; g++)
		{
			plikDM << "gestosc " << gestosci[g] << " dla " << liczba[w] << " wierzcholkow, lista, Prim" << endl;
			for (int i = 0; i < 50; i++)
			{
				graf.losowoMST(liczba[w], gestosci[g]);
				graf.stworzListe();
				czas.czasStart();
				graf.primL();
				czas.czasStop();
				srednia = srednia + czas.czasTrwania();
				graf.usun();
			}
			srednia = srednia / 50;
			plikDM << srednia << endl;
			srednia = 0;
		}
	}

	for (int w = 0; w < 7; w++)
	{
		for (int g = 0; g < 3; g++)
		{
			plikDM << "gestosc " << gestosci[g] << " dla " << liczba[w] << " wierzcholkow, lista, Kruskal" << endl;
			for (int i = 0; i < 50; i++)
			{
				graf.losowoMST(liczba[w], gestosci[g]);
				graf.stworzListe();
				czas.czasStart();
				graf.kruskalL();
				czas.czasStop();
				srednia = srednia + czas.czasTrwania();
				graf.usun();
			}
			srednia = srednia / 50;
			plikDM << srednia << endl;
			srednia = 0;
		}
	}
	plikDM.close();
}
