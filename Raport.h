#pragma once
#include <iostream>
#include <string>

using namespace std;

class raport
{
	string tresc;
	int numer;
	zgloszenie z;
public:
	int Generuj_id()
	{
		time_t czas;
		struct tm wzgledne;
		wzgledne.tm_year = 124;
		wzgledne.tm_mon = 0;
		wzgledne.tm_min = 0;
		wzgledne.tm_hour = 0;
		wzgledne.tm_sec = 0;
		wzgledne.tm_mday = 8;
		time(&czas);
		int id = difftime(czas, mktime(&wzgledne));
		return id;
	};
	raport()
	{
		tresc = "0";
		numer = -1;
		z = zgloszenie();
	};
	raport(string t, zgloszenie z1) :tresc(t), z(z1) { numer = Generuj_id(); cout << "Utworzono raport ID: " << numer << endl;};
	raport(string t, zgloszenie z1, int id) :tresc(t), z(z1), numer(id) {};
	string get_tresc() { return tresc; };
	int get_numer() { return numer; };
	zgloszenie get_zgloszenie() { return z; };
};