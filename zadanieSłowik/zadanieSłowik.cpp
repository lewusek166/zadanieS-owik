#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <boost\tokenizer.hpp>
#include <vector>
using namespace std;
using namespace boost;



class Porównywanie 
{
public:

	string * dok1;
	string * dok1p;
	vector <int> tablica_bool;
	vector < string > dane;
	string fraza;
	int iterator[3];
	int prawda;
	Porównywanie ();
	~Porównywanie();
	void Pobranie_fazy(vector < string > dane);
	void odczyt(int iterator[],string * dok, string * dokp, string nazwa_pliku);
	void wszystkie_fun();
	void tablice_znkow_logicznych(int iterator[],vector <int> tablica_bool, string dok, string dokp, vector< string> dane);
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

void Porównywanie::Pobranie_fazy(vector < string > dane)
{	
	
	cout << "Podaj wyrazy do por\243wnania w dokumencie " << endl;
	getline(cin, fraza);

	cout << "Wyrazy do porównania" << fraza << endl;
	
	


	char_separator<char> separator(" ");
	tokenizer<char_separator<char>> slowa(fraza, separator);
	for (const auto& t : slowa) {
		dane.push_back(t);
	}


}

void Porównywanie::odczyt(int iterator[],string * dok, string * dokp, string nazwa_pliku)
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
	odczyt(iterator ,dok1, dok1p, "dokument1.txt");
	Pobranie_fazy(dane);
}

void Porównywanie::tablice_znkow_logicznych(int iterator[], vector <int> tablica_bool, string dok, string dokp, vector<string> dane)
{
	//tablica_bool[iterator[0]]

}






int main()
{
	Porównywanie obiekt;
	
	obiekt.wszystkie_fun();
	
	
	
    return 0;
	
}

