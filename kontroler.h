#pragma once
#include<iostream>
#include<string>
#include "Baza_danych.h"

using namespace std;

class kontroler
{
	Baza_danych Baza;
public:
	kontroler() = default;
	kontroler(Baza_danych b) :Baza(b) {};
	void Sprawdz_dane_klienta(Klient& k)
	{
		if (!(Baza.Znajdz_w_danych(k)))
		{
			cout << "Nowy klient dodaje do bazy." << endl;
			Baza.Dodaj_klienta(k);
		}
		return;
	}
	void Przekaz_zgloszenie(zgloszenie& z)
	{
		Baza.Dodaj_zgloszenie(z);
		return;
	}
	void Przekaz_raport(raport& r)
	{
		Baza.Dodaj_raport(r);
		return;
	}
	void Przekaz_dane(faktura& f,string plik)
	{
		Baza.Zapisz_fakture(f,plik);
		return;
	}
	zgloszenie Zwroc_zgloszenie(int id)
	{
		if (Baza.Znajdz_zgloszenie(id))
		{
			zgloszenie z;
			z=Baza.Zwroc_zgloszenie(id);
			return z;
		}
		else
		{
			cout << "Nie znaleziono zgloszenia. Zwracam puste zgloszenie." << endl;
			return zgloszenie();
		}
	}
	raport Zwroc_raport(int id)
	{

		if (Baza.Znajdz_raport(id))
		{
			raport r;
			r=Baza.Zwroc_raport(to_string(id));
			return r;
		}
		else
		{
			cout << "Nie znaleziono raportu. Zwracam pusty raport." << endl;
			return raport();
		}
	}
	void wyswietl_zgloszenia()
	{
		Baza.wyswietlaj_zgloszenia();
		return;
	}
};