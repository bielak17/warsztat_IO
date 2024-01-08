#pragma once
#include<string>
#include <iostream>
#include <fstream>

using namespace std;

class Auto
{
	string marka;
	string model;
	string rejestracja;
public:
	Auto() = default;
	Auto(string ma, string mo, string r) :marka(ma), model(mo), rejestracja(r) {};
	friend ostream& operator<<(ostream& wyj, const Auto& a)
	{
		wyj << "Samochod: " << a.marka << ", " << a.model << " o rejestracji: " << a.rejestracja;
		return wyj;
	};
};