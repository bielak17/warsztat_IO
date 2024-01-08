#pragma once
#include <string>
#include <iostream>
#include "Klient.h"
#include "Zgloszenie.h"
#include "Raport.h"
#include "faktura.h"

using namespace std;

class Baza_danych
{
	string baza_klientow;
	string baza_zgloszen;
	string baza_raportow;
public:
	Baza_danych() = default;
	Baza_danych(string k, string z, string r) :baza_klientow(k), baza_raportow(r), baza_zgloszen(z) {};
	void Dodaj_klienta(Klient K)
	{
		ofstream plik;
		plik.open(baza_klientow, ios::app);
		plik << K.get_id() << " " << K.get_imie() << " " << K.get_nazwisko() << " " << K.get_samochod() << endl;
		plik.close();
		return;
	};
	void Dodaj_zgloszenie(zgloszenie Z)
	{
		ofstream plik;
		plik.open(baza_zgloszen, ios::app);
		plik << Z << endl;
		plik.close();
		return;
	};
	void Dodaj_raport(raport R)
	{
		ofstream plik;
		plik.open(baza_raportow, ios::app);
		plik << "Raport nr: " << R.get_numer() << " ze zgloszenia " << R.get_zgloszenie() << " o tresci:" << R.get_tresc() << endl;
		plik.close();
		return;
	};
	bool Znajdz_w_danych(Klient& K)
	{
		ifstream plik;
		plik.open(baza_klientow);
		int i;
		string im, buf;
		while (!plik.eof())
		{
			plik >> i;
			plik >> im;
			getline(plik, buf);
			if (i == K.get_id() && im == K.get_imie())
			{
				cout << "Mamy juz tego klienta w bazie." << endl;
				return true;
			}
		}
		return false;
	};
	bool Znajdz_zgloszenie(int id)
	{
		ifstream plik;
		plik.open(baza_zgloszen);
		int i;
		string buf;
		while (!plik.eof())
		{
			plik >> i;
			getline(plik, buf);
			if (i == id)
				return true;
		}
		return false;
	};
	bool Znajdz_raport(int id)
	{
		ifstream plik;
		plik.open(baza_raportow);
		int i;
		string buf;
		string nr = to_string(id);
		while (!plik.eof())
		{
			getline(plik, buf);
			if (buf.find("Raport nr: " + nr) != string::npos)
				return true;
		}
		return false;
	};
	raport Zwroc_raport(string id)
	{
		ifstream plik;
		plik.open(baza_raportow);
		string buf;
		while (!plik.eof())
		{
			getline(plik, buf);
			if (buf.find("Raport nr: " + id) != string::npos)
			{
				cout << "Szukany raport to: " << endl;
				string tresc;
				getline(plik, tresc);
				cout <<buf<<"\n"<< tresc << endl;
				int nr = stoi(id);
				string p;
				size_t pos1 = buf.find("zgloszenia");
				buf = buf.substr(pos1);
				buf = buf.erase(0, 11);
				size_t pos2 = buf.find(" ");
				p = buf.substr(0,pos2);
				zgloszenie z;
				int p2 = stoi(p);
				z=Zwroc_zgloszenie(p2);
				raport r(tresc,z,nr);
				return r;
			}
		}
		cout << "Nie znaleziono takiego raportu." << endl;
	};
	zgloszenie Zwroc_zgloszenie(int id)
	{
		ifstream plik;
		plik.open(baza_zgloszen);
		int i;
		string typ;
		while (!plik.eof())
		{
			plik >> i;
			plik >> typ;
			if (i==id)
			{
				cout << "Szukane zgloszenie to: " << endl;
				cout << i << " " << typ << endl;
				zgloszenie z(typ,i);
				return z;
			}
		}
		cout << "Nie znaleziono takiego zgloszenia." << endl;
	};
	void Zapisz_fakture(faktura f,string wyj)
	{
		ofstream plik;
		plik.open(wyj, ios::app);
		plik << "Fakture wystawia: " << f.get_wystawiajacy() << " dla " << f.get_nabywca() << " za " << f.get_usluga() << " na kwote " << f.suma() << endl;
		plik.close();
		return;
	};
};

