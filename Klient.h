#pragma once
#include <string>
#include <time.h>
#include "auto.h"

using namespace std;

class Klient
{
	string imie;
	string nazwisko;
	Auto samochod;
	int id;
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
		wzgledne.tm_mday = 1;
		time(&czas);
		int id = difftime(czas, mktime(&wzgledne));
		return id;
	};
	Klient() = default;
	Klient(string i, string n, Auto s) :imie(i), nazwisko(n), samochod(s)
	{
		int id1 = Generuj_id();
		id = id1;
		cout << "Utworzono Konto Klienta ID: " << id1 << " Imie i naziwsko: " << i << " " << n << endl;
	};
	int get_id() { return id; };
	string get_imie() { return imie; };
	string get_nazwisko() { return nazwisko; };
	Auto get_samochod() { return samochod; };
};