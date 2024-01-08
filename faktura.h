#pragma once
#include <string>
#include <iostream>

using namespace std;

class faktura
{
	double cena;
	int vat;
	string wystawiajacy, nabywca, usluga;
public:
	faktura() = default;
	faktura(int v, double c, string w, string n, string u) :vat(v), wystawiajacy(w), nabywca(n), usluga(u), cena(c) {};
	string get_wystawiajacy() { return wystawiajacy; };
	string get_nabywca() { return nabywca; };
	string get_usluga() { return usluga; };
	double suma() { return cena * vat * 0.01 + cena; };
};