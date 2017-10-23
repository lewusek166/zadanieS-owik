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
	string fraza;
	int iterator[9];
	int prawda;
	Porównywanie ();
	~Porównywanie();
	void Pobranie_fazy();
	void odczyt();
	void tablica_jednorodna();


private:

};




Porównywanie ::Porównywanie ()
{
	
	
	
}

Porównywanie::~Porównywanie()
{
	delete[] dok1;
}

void Porównywanie::Pobranie_fazy()
{
	cout << "Podaj wyrazy do porównania w dokumencie " << endl;
	cin >> fraza;

	cout << "Wyrazy do porównania" << fraza << endl;






}

void Porównywanie::odczyt()
{
	iterator[0] = 0;
	fstream plik1;

	plik1.open("dokument1.txt", ios::in);
	if (plik1.good() == false) {
		cout << "B³¹d otwarcia pliku 1" << endl;
		exit(0);
	}
	string pomoc1;
	while (getline(plik1, pomoc1, ' ')) {
		iterator[0]++;
	}
	
	dok1 = new string[iterator[0]+1];
	
	plik1.close();
	plik1.open("dokument1.txt", ios::in);
	if (plik1.good() == false) {
		cout << "B³¹d otwarcia pliku 1" << endl;
		exit(0);
	}
	int i = 0;
	while (getline(plik1, dok1[i], ' '))
	{
		
		i++;
	}

	


plik1.close();



}

void Porównywanie::tablica_jednorodna()
{
	dok1p = new string[iterator[0] + 1];
	int liczydlo = 1;
	int i = 1;
	dok1p[0] = dok1[0];
	for (i; i <= iterator[0]; i++) {
		prawda = 0;
		for (int j = i-1; j >= 0; j--) {
			
			
			if (dok1[i] != dok1p[j]) {
				
				prawda -= 1;
			}
			else
			{
				prawda += iterator[0];
			}
			
				
		}if (prawda<=0) {
			
			dok1p[liczydlo] = dok1[i];
			liczydlo++;
			
		}
		}
	


}




int main()
{
	Porównywanie obiekt;
	obiekt.odczyt();
	obiekt.tablica_jednorodna();
	
	
    return 0;
	
}

