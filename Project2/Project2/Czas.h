#pragma once
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Czas
{
public:
	high_resolution_clock::time_point start;
	high_resolution_clock::time_point koniec;

	void czasStart(); 

	void czasStop();

	long czasTrwania();
};

