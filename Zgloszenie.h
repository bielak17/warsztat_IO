#pragma once
#include<iostream>
#include<string>
#include <fstream>

using namespace std;

class zgloszenie
{
	int id;
	string typ;
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
		wzgledne.tm_mday = 6;
		time(&czas);
		int id = difftime(czas, mktime(&wzgledne));
		return id;
	};
	zgloszenie()
	{
		id = 0;
		typ = "0";
	};
	zgloszenie(string t)
	{
		typ = t;
		id = Generuj_id();
		cout << "Utworzono zgloszenie ID: " << id << endl;
	};
	zgloszenie(string t, int i) :id(i), typ(t) {};
	int get_id() { return id; };
	string get_typ() { return typ; };
	friend ostream& operator<<(ostream& wyj, const zgloszenie& z)
	{
		wyj << z.id<<" "<<z.typ;
		return wyj;
	};
};