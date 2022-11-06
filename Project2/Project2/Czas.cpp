#include "Czas.h"

void Czas::czasStart() {
	start = high_resolution_clock::now();
}

void Czas::czasStop(){
	koniec = high_resolution_clock::now();
}

long Czas::czasTrwania() {
	return duration_cast<microseconds>(koniec - start).count();
}