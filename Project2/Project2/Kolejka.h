#pragma once
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <set>
#include "Krawedz.h"

class Kolejka
{
	Krawedz* wskaznik;
	int rozmiar;

	void push(Krawedz j);

	Krawedz pop();

	void doGory();

	void doDolu();
};

