#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;




class Por�wnywanie 
{
public:

	string * dok1;
	string * dok1p;
	string fraza;
	int iterator[9];
	int prawda;
	bool potwierdzenie;
	bool potwierdzenie1;
	Por�wnywanie ();
	~Por�wnywanie();
	void Pobranie_fazy();
	void odczyt();
	void tablica_jednorodna();


private:

};




Por�wnywanie ::Por�wnywanie ()
{
	potwierdzenie = false;
	potwierdzenie1 = false;
	
	
}

Por�wnywanie::~Por�wnywanie()
{
	delete[] dok1;
}

void Por�wnywanie::Pobranie_fazy()
{
	cout << "Podaj wyrazy do por�wnania w dokumencie " << endl;
	cin >> fraza;

	cout << "Wyrazy do por�wnania" << fraza << endl;






}

void Por�wnywanie::odczyt()
{
	iterator[0] = 0;
	fstream plik1;

	plik1.open("dokument1.txt", ios::in);
	if (plik1.good() == false) {
		cout << "B��d otwarcia pliku 1" << endl;
		exit(0);
	}
	string pomoc1;
	while (getline(plik1, pomoc1, ' ')) {
		iterator[0]++;
	}
	cout << "ilosc slow = " << iterator[0] << endl;
	dok1 = new string[iterator[0]+1];
	
	plik1.close();
	plik1.open("dokument1.txt", ios::in);
	if (plik1.good() == false) {
		cout << "B��d otwarcia pliku 1" << endl;
		exit(0);
	}
	int i = 0;
	while (getline(plik1, dok1[i], ' '))
	{
		cout << dok1[i] << endl;
		i++;
	}

	


plik1.close();



}

void Por�wnywanie::tablica_jednorodna()
{
	dok1p = new string[iterator[0] + 1];
	int liczydlo = 1;
	int i = 1;
	dok1p[0] = dok1[0];
	for (i; i <= iterator[0]; i++) {
		prawda = 0;
		for (int j = i-1; j >= 0; j--) {
			
			cout << dok1[i] << " :: " << dok1p[j] << endl;
			if (dok1[i] != dok1p[j]) {
				
				prawda -= 1;
			}
			else
			{
				prawda += iterator[0];
			}
			
				
		}if (prawda<=0) {
			cout << "zapis  :: " << dok1[i] << endl;
			dok1p[liczydlo] = dok1[i];
			liczydlo++;
			
		}
		}
	

	for (int i = 0; i < iterator[0];i++) {
		cout << dok1p[i] << endl;
	}
}




int main()
{
	Por�wnywanie obiekt;
	obiekt.odczyt();
	obiekt.tablica_jednorodna();
	
	
    return 0;
	
}

