#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;




class Porównywanie 
{
public:

	string * dok1;
	string * dok1p;
	string * tabf;
	string fraza;
	int iterator[9];
	int prawda;
	Porównywanie ();
	~Porównywanie();
	void Pobranie_fazy(string * frazy);
	void odczyt(string * dok, string * dokp, string nazwa_pliku);
	void wszystkie_fun();

private:

};




Porównywanie ::Porównywanie ()
{
	
	
	
}

Porównywanie::~Porównywanie()
{
	//delete[] dok1;
//	delete[] dok1p;
}

void Porównywanie::Pobranie_fazy(string * frazy)
{	
	string pomoc;
	cout << "Podaj wyrazy do porównania w dokumencie " << endl;
while (getline(cin, pomoc, ' ')) {
		iterator[1]++;

	}

	cout << "Wyrazy do porównania" << pomoc << endl;
	
	frazy = new string[iterator[1] + 1];






}

void Porównywanie::odczyt(string * dok, string * dokp, string nazwa_pliku)
{
	iterator[0] = 0;
	fstream plik1;

	plik1.open(nazwa_pliku, ios::in);
	if (plik1.good() == false) {
		cout << "B³¹d otwarcia pliku : "<< nazwa_pliku<< endl;
		exit(0);
	}
	string pomoc1;
	while (getline(plik1, pomoc1, ' ')) {
		iterator[0]++;
	}
	
	dok = new string[iterator[0]+1];
	
	plik1.close();
	plik1.open(nazwa_pliku, ios::in);
	if (plik1.good() == false) {
		cout << "B³¹d otwarcia pliku : " << nazwa_pliku << endl;
		exit(0);
	}
	int z = 0;
	while (getline(plik1, dok[z], ' '))
	{
		
		z++;
	}
	plik1.close();


	/////tablica jednorodna
	dokp = new string[iterator[0] + 1];
	int liczydlo = 1;
	int i = 1;
	dokp[0] = dok[0];
	for (i; i <= iterator[0]; i++) {
		prawda = 0;
		for (int j = i-1; j >= 0; j--) {
			
			
			if (dok[i] != dokp[j]) {
				
				prawda -= 1;
			}
			else
			{
				prawda += iterator[0];
			}
			
				
		}if (prawda<=0) {
			
			dokp[liczydlo] = dok[i];
			liczydlo++;
			
		}
		}

}

void Porównywanie::wszystkie_fun()
{
	odczyt(dok1, dok1p, "dokument1.txt");
}




int main()
{
	Porównywanie obiekt;
	obiekt.wszystkie_fun();
	
	
	
    return 0;
	
}

