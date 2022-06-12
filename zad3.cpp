#include<iostream>
#include<string>
using namespace std;

string alfabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alf    ="abcdefghijklmnopqrstuvwxyz";//angielski alfabet

int pozycjaAlfabet(char znak){

	for(int i=0;i<alfabet.size();i++){

		if (alfabet[i]==znak||alf[i]==znak) {
			return i;
		}
	}

	return -1;//error

}

void szyfruj(string tekst,string klucz){

	string wynik;

	for(int i=0;i<tekst.size();i++){

		int pozycjaLiteryKlucza = pozycjaAlfabet( klucz[i % klucz.size()] );

		int pozycjaLiteryTekstu = pozycjaAlfabet( tekst[i] );

		wynik+=alfabet[ (pozycjaLiteryTekstu+pozycjaLiteryKlucza) % alfabet.size()];

	}

	cout<<"Wynik szyfrowania: \n"<<wynik;

}



int main(){

	string klucz,tekst;

	cout<<"Wprowadz tekst do zaszyfrowania:"<<endl;
	cin>>tekst;

	cout<<"Wprowadz slowo kluczowe:"<<endl;
	cin>>klucz;

	szyfruj(tekst,klucz);

	return 0;
}
