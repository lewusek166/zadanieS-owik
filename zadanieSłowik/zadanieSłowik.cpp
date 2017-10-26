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

	
	
	vector < string > dane;
	string fraza;
	int** tablica_znacznikow;
	int iterator[9];
	int prawda;
	Porównywanie ();
	~Porównywanie();
	void Pobranie_fazy(vector < string > dane);
	void odczyt(int iterator,string * dok, string * dokp, string nazwa_pliku);
	void wszystkie_fun();
	void tablice_znkow_logicznych(string dok, string dokp, vector< string> dane);
	void usuwanie_tablicString(string * dok, string * dokp);
private:
	string * dok1;
	string * dok1p;
	string * dok2;
	string * dok2p;
	string * dok3;
	string * dok3p;
	string * dok4;
	string * dok4p;
	string * dok5;
	string * dok5p;
	string * dok6;
	string * dok6p;
	string * dok7;
	string * dok7p;
	string * dok8;
	string * dok8p;
	
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
	iterator[8] = 1;
	cout << "Podaj wyrazy do por\243wnania w dokumencie " << endl;
	getline(cin, fraza);

	cout << "Wyrazy do porównania" << fraza << endl;
	
	


	char_separator<char> separator(" ");
	tokenizer<char_separator<char>> slowa(fraza, separator);
	for (const auto& t : slowa) {
		dane.push_back(t);
		iterator[8]++;
	}


}

void Porównywanie::odczyt(int iterator,string * dok, string * dokp, string nazwa_pliku)
{
	iterator = 0;
	fstream plik;

	plik.open(nazwa_pliku, ios::in);
	if (plik.good() == false) {
		cout << "B³¹d otwarcia pliku : "<< nazwa_pliku<< endl;
		exit(0);
	}
	string pomoc1;
	while (getline(plik, pomoc1, ' ')) {
		iterator++;
	}
	
	dok = new string[iterator +1];
	
	plik.close();
	plik.open(nazwa_pliku, ios::in);
	if (plik.good() == false) {
		cout << "B³¹d otwarcia pliku : " << nazwa_pliku << endl;
		exit(0);
	}
	int z = 0;
	while (getline(plik, dok[z], ' '))
	{
		
		z++;
	}
	plik.close();


	/////tablica jednorodna
	dokp = new string[iterator + 1];
	int liczydlo = 1;
	int i = 1;
	dokp[0] = dok[0];
	for (i; i <= iterator; i++) {
		prawda = 0;
		for (int j = i-1; j >= 0; j--) {
					
			if (dok[i] != dokp[j]) {
				
				prawda -= 1;
			}
			else
			{
				prawda += iterator;
			}
				
		}if (prawda<=0) {
			
			dokp[liczydlo] = dok[i];
			liczydlo++;
			
		}
		}

}

void Porównywanie::wszystkie_fun()
{
	
	odczyt(iterator[0], dok1, dok1p, "dokumenty/dokument1.txt");
	odczyt(iterator[1], dok2, dok2p, "dokumenty/dokument2.txt");
	odczyt(iterator[2], dok3, dok3p, "dokumenty/dokument3.txt");
	odczyt(iterator[3], dok4, dok4p, "dokumenty/dokument4.txt");
	odczyt(iterator[4], dok5, dok5p, "dokumenty/dokument5.txt");
	odczyt(iterator[5], dok6, dok6p, "dokumenty/dokument6.txt");
	odczyt(iterator[6], dok7, dok7p, "dokumenty/dokument7.txt");
	odczyt(iterator[7], dok8, dok8p, "dokumenty/dokument8.txt");
	Pobranie_fazy(dane);
}

void Porównywanie::tablice_znkow_logicznych(string dok, string dokp, vector<string> dane)
{
	
	tablica_znacznikow = new int*[iterator[8]];
	for (int i = 0; i < 8; i++) {
		tablica_znacznikow[i] = new int[8];
	}
	string pomoc;
	int rozmiar = (int)dane.size();

	///sprawdzenie frazy w dokach 

	for (int i = 0; i <(int)dane.size(); i++) {

		for (int j = 0; j < iterator[0]; j++) {
			pomoc = dokp[j];
			if (pomoc == dane[i]) {

				tablica_znacznikow[i][0] = 1;
			}

		}



	}




}

void Porównywanie::usuwanie_tablicString(string * dok, string * dokp)
{
	delete[] dok;
	delete[] dokp;
}






int main()
{
	Porównywanie obiekt;
	
	obiekt.wszystkie_fun();
	
	
	
    return 0;
	
}

