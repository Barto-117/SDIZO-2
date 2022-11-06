#include <iostream>
#include <stdio.h>
#include "Graf.h"
#include "Czas.h"
#include "Test.h"
using namespace std;

int main() {
	Graf graf;
	string txt;
	int i, v;
	/*Test test;
	test.testowanie();
	graf.losowoMST(10, 100);
	graf.stworzListe();*/
	graf.wyswietl();
	do {
		cout << "1. Otworz z pliku" << endl;
		cout << "2. Utworz losowo" << endl;
		cout << "5. Koniec" << endl;
		cout << "Wybor: ";
		cin >> i;
		switch (i)
		{
		case 1:
			cout << "1. Prim" << endl;
			cout << "2. Kruskal" << endl;
			cout << "3. Dijkstra" << endl;
			cout << "4. Bellman-Ford" << endl;
			cout << "0. Wyjdz" << endl;
			cout << "Wybor: ";
			cin >> i;
			switch (i)
			{
			case 1:
				cout << "Nazwa pliku: ";
				cin >> txt;
				graf.plikMST(txt);
				graf.stworzMacierz();
				graf.stworzListe();
				graf.wyswietl();
				graf.primM();
				graf.primL();
				break;
			case 2:
				cout << "Nazwa pliku: ";
				cin >> txt;
				graf.plikMST(txt);
				graf.stworzMacierz();
				graf.stworzListe();
				graf.wyswietl();
				graf.kruskalM();
				graf.kruskalL();
				break;
			case 3:
				cout << "Nazwa pliku: ";
				cin >> txt;
				v = graf.plikSK(txt);
				graf.stworzMacierzSK();
				graf.stworzListe();
				graf.wyswietl();
				graf.dijkstraM(v);
				graf.dijkstraL(v);
				break;
			case 4:
				cout << "Nazwa pliku: ";
				cin >> txt;
				v = graf.plikSK(txt);
				graf.stworzMacierzSK();
				graf.stworzListe();
				graf.wyswietl();
				graf.bellmanM(v);
				graf.bellmanL(v);
				break;
			case 0:
				break;
			default:
				break;
			}
			graf.usun();
			break;
		case 2:
			cout << "1. Prim" << endl;
			cout << "2. Kruskal" << endl;
			cout << "3. Dijkstra" << endl;
			cout << "4. Bellman-Ford" << endl;
			cout << "0. Wyjdz" << endl;
			cout << "Wybor: ";
			cin >> i;
		default:
			break;
		}
	} while (i != 5);
	return 0;
}