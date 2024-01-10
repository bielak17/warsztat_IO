#include <iostream>
#include "interfejs.h"

void ClientCode(interfejs i)
{
	int pom;
	cout << "\nWybierz opcje:" << endl;
	cout<<"1.Dodaj nowe zgloszenie.\t" << "2.Stworz Raport.\t" << "3.Wystaw Fakture\t"<<"4.Wyswietl zgloszenia\t" <<"5.Zamknij program"<<endl;
	while (1)
	{
		cin >> pom;
		if (pom == 1 || pom == 2 || pom == 3 || pom==4 || pom==5)
			break;
		else
			cout << "Podano niepoprawna opcje sprobuj ponownie!" << endl;
	}
	switch (pom)
	{
	case 1:
		i.Utworz_zgloszenie();
		break;
	case 2:
		i.utworz_raport();
		break;
	case 3:
		i.wycen_i_faktura();
		break;
	case 4:
		i.wyswietl_zgloszenia();
		break;
	case 5:
		return;
	}

}

int main()
{
	Baza_danych Baza("klienci.txt", "zlecenia.txt", "raporty.txt");
	kontroler k(Baza);
	interfejs I(k);
	int pom;
	do
	{
		ClientCode(I);
		cout << "\nJesli chcesz przerwac wcisnij 0 jesli nie to cokolwiek innego: ";
		cin >> pom;
	} while (pom);
	return 0;
}
