#pragma once
#include <iostream>
#include <string>
#include "kontroler.h"

class interfejs
{
	kontroler k;
public:
	interfejs() = default;
	interfejs(kontroler ko) :k(ko) {};
	void Utworz_zgloszenie()
	{
		string imie, nazwisko, model, marka,rejestracja;
		cout << "Podaj dane klienta:" << endl;
		cout << "Podaj imie i nazwisko: ";
		cin >> imie >> nazwisko;
		cout << "Podaj marke i model samochodu: ";
		cin >> marka >> model;
		cout << "Podaj rejestracje pojazdu: ";
		cin >> rejestracja;
		Auto pojazd(marka, model, rejestracja);
		Klient K(imie, nazwisko, pojazd);
		k.Sprawdz_dane_klienta(K);
		string usluga;
		cout << "Wybierz jaka praca ma zostac wykonana na pojezdzie (naprawa/przeglad): ";
		while (1)
		{
			cin >> usluga;
			if (usluga == "naprawa" || usluga == "przeglad")
				break;
			else
				cout << "Podano niepoprawna opcje wpisz jeszcze raz." << endl;
		}
		zgloszenie Z(usluga);
		k.Przekaz_zgloszenie(Z);
		cout << "Dodano zgloszenie dziekuje za skorzystanie." << endl;
		return;
	}
	void utworz_raport()
	{
		int id;
		cout << "Podaj ID zgloszenia: ";
		cin >> id;
		zgloszenie pom;
		pom=k.Zwroc_zgloszenie(id);
		if (pom.get_id() == 0)
		{
			cout << "Brak podanego zgloszenia nie tworze zadnego raportu."<<endl;
			return;
		}
		cout << "Podaj tresc raportu (zakoncz kropka): ";
		string tresc;
		char ch = '.';
		getline(cin, tresc,ch);
		raport R(tresc,pom);
		k.Przekaz_raport(R);
		cout << "Dodano raport dziekuje za skorzystanie." << endl;
		return;
	}
	void wycen_i_faktura()
	{
		string plik, wystawiacy, nabywca,usluga;
		double cena;
		int vat,id;
		cout << "Podaj dane do wystawienia faktury: " << endl;
		cout << "Podaj wystawiajacego fakture: ";
		cin >> wystawiacy;
		cout << "Podaj nazwe nabywcy uslugi: ";
		cin >> nabywca;
		cout << "Podaj id raportu na podstawie ktorego wystawia sie fakture: ";
		cin >> id;
		raport pom;
		pom = k.Zwroc_raport(id);
		if (pom.get_numer() == -1)
		{
			cout << "Niepoprawne ID raportu nie wystawie faktury." << endl;
			return;
		}
		zgloszenie pom1;
		pom1 = pom.get_zgloszenie();
		usluga = pom1.get_typ();
		cout << "Podaj VAT i cene uslugi: ";
		cin >> vat >> cena;
		cout << "Podaj nazwe pliku do zapisania faktury: ";
		cin >> plik;
		faktura F(vat, cena, wystawiacy, nabywca, usluga);
		k.Przekaz_dane(F, plik);
		cout << "Faktura zostala zapisana do pliku " << plik << " dziekuje za skorzystanie." << endl;
		return;
	}
	void wyswietl_zgloszenia()
	{
		k.wyswietl_zgloszenia();
		return;
	};
};