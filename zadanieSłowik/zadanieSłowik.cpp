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
	string * tabf;
	string fraza;
	int iterator[9];
	int prawda;
	Por�wnywanie ();
	~Por�wnywanie();
	void Pobranie_fazy(string * frazy);
	void odczyt(string * dok, string * dokp, string nazwa_pliku);
	void wszystkie_fun();

private:

};




Por�wnywanie ::Por�wnywanie ()
{
	
	
	
}

Por�wnywanie::~Por�wnywanie()
{
	//delete[] dok1;
//	delete[] dok1p;
}

void Por�wnywanie::Pobranie_fazy(string * frazy)
{	
	string pomoc;
	cout << "Podaj wyrazy do por�wnania w dokumencie " << endl;
while (getline(cin, pomoc, ' ')) {
		iterator[1]++;

	}

	cout << "Wyrazy do por�wnania" << pomoc << endl;
	
	frazy = new string[iterator[1] + 1];






}

void Por�wnywanie::odczyt(string * dok, string * dokp, string nazwa_pliku)
{
	iterator[0] = 0;
	fstream plik1;

	plik1.open(nazwa_pliku, ios::in);
	if (plik1.good() == false) {
		cout << "B��d otwarcia pliku : "<< nazwa_pliku<< endl;
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
		cout << "B��d otwarcia pliku : " << nazwa_pliku << endl;
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

void Por�wnywanie::wszystkie_fun()
{
	odczyt(dok1, dok1p, "dokument1.txt");
}




int main()
{
	Por�wnywanie obiekt;
	obiekt.wszystkie_fun();
	
	
	
    return 0;
	
}

