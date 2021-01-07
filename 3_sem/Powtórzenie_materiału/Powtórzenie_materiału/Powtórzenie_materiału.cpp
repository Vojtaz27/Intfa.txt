// Powtórzenie_materiału.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdlib>
#include <iostream>
using namespace std;

class Samochod {
private:
	int wiek, cena, predkosc;

public:
	Samochod* left;
	Samochod* right;
	Samochod* next;

	Samochod() {
		wiek = rand() % 21;
		predkosc = rand() % 150 + 150;
		cena = rand() % 65 + 35;
		left = NULL;
		right = NULL;
		next = NULL;
	}
	void wstaw_l(Samochod* a) {								//jakoś zapamiętać schemat wstawiania w listę bo operacje na wskaźnikach to jendo ale kolejność działań jest ważna i to ze porównujemy się do nexta
		if (next == NULL) next = a;
		else if (next->wiek < a->wiek) next->wstaw_l(a);
		else {
			a->next = this->next;
			this->next = a;
		}
			
		

	}
	void wstaw_d(Samochod* a) {
		if (cena < a->cena) {
			if (right == NULL)right = a;
			else right->wstaw_d(a);
		}
		else {
			if (left == NULL) left = a;
			else left->wstaw_d(a);
		}
	}
	void wyswietl_l() {
		cout << "Wiek: " << wiek << " Cena: " << cena <<  endl;
		if (next) next->wyswietl_l();
	}
	void wyswietl_d() {
		if (left) left->wyswietl_d();
		cout << "Wiek: " << wiek << " Cena: " << cena << endl;
		if (right) right->wyswietl_d();
	}
	int return_cena() {
		return cena;
	}
	int return_wiek() {
		return wiek;
	}
	int return_pedosc() {
		return predkosc;
	}
	int ilosc_l(int counter = 1) {
		if (next) counter = next->ilosc_l(++counter);
		return counter;
	}
	int ilosc_d(int counter = 1) {
		if (right) counter = right->ilosc_d(++counter);
		if (left) counter = left->ilosc_d(++counter);
		return counter;
	}
	int ile_sz_l(int a, int counter = 1) {
		if (a < predkosc and next) counter = next->ile_sz_l(a, counter);
		else if (a > predkosc) {
			++counter;
			if (next) {
				counter = next->ile_sz_l(a, counter);
			}
		}
		return counter;
	}
	int suma_c_l(int sum = 0) {
		sum = cena;
		if (next) sum += next -> suma_c_l();
		return sum;
	}
	int srednia_c_l() {
		int ile = this->ilosc_l();
		int sum = this->suma_c_l();
		return sum / ile;
	}
	int najd_d() {
		if (right) right->najd_d();
		else return cena;
	}
	int najm_d(int a = 30) {						// udało się zrobić szukanie wartości najmniejszejw  drzewie posegregowanego względem innego argumentu // prostrze niż myślałem
		if (a > wiek) a = wiek;
			if (left) a = left->najm_d(a);
		    if (right) a = right->najm_d(a);
		else return a;
	}
	int ile_d_d(int a, int counter=0) {
		if (cena > a) {
			++counter;
			if (left) counter = left->ile_d_d(a, counter);
			if (right) counter = right->ile_d_d(a, counter);	
		}
		else {
			if (left) counter = left->ile_d_d(a, counter);
			if (right) counter = right->ile_d_d(a, counter);
		}
		return counter;
	}
	int suma_c_d(int sum=0) {
		sum = cena;
		if (right) sum += right->suma_c_d();
		if (left) sum += left->suma_c_d();
		return sum;
	}
								// TUTAJ TRZEBA NAPISAĆ METODA NA WYSOKOŚĆ LISTY
};

int main() {

	Samochod* rl = new Samochod();
	//Samochod* rd = new Samochod();
	for (int i = 0; i < 10; i++) {
		Samochod* p = new Samochod();
		rl->wstaw_l(p);
	}
	rl->wyswietl_l();
	cout << endl << endl;
	Samochod *rd = NULL;
	if (rl->return_cena() > 65) {				
		rd = rl;
		rl = rl->next;
		rd->next = NULL;
		if (rl and rd ){
			while (rl->next and rl->return_cena() > 65) {
				Samochod* supp = rl;
				rl = rl->next;
				supp->next = NULL;
				rd->wstaw_d(supp);			//	NIGDY WIĘCEJ NIE KOPIOWAĆ KODU BO ZAPOMINAM DOSTOSOWAĆ ZMIENNE I PROGRAM NIE DZIAŁA 
			}								//  TERAZ NIE DOPISAŁEM 2 DO WSKAŹNIKA SUPP I PROGRAM WSTAWIA ZŁĄ ZMIENNĄ DO DRZEWA A RESZTA DZIAŁAŁA DOBRZE OD RAZU
		}
		if (rd) {
			Samochod* supp = rl;
			while (supp->next) {
				//Samochod* supp = rl;
				if (supp->next->return_cena() > 65) {
					Samochod* supp2 = supp->next;
					supp->next = supp2->next;
					supp = supp->next;
					supp2->next = NULL;
					rd->wstaw_d(supp2);
				}
				else supp = supp->next;
			}
		}
	}
	else {
		Samochod* supp = rl;
		 if(!rd) {
			while (!rd and supp->next) {
				if (supp->next->return_cena() > 65) {
					rd = supp->next;
					supp->next = rd->next;
					supp = supp->next;
					rd->next = NULL;
					
				}
				else supp = supp->next;
			}
		}
		if (rd) {
			while (supp->next) {
				if (supp->next->return_cena() > 65) {
					Samochod* supp2 = supp->next;
					supp->next = supp2->next;
					supp = supp->next;
					supp2->next = NULL;
					rd->wstaw_d(supp2);
				}
				else supp = supp->next;
			}
		}
	}
	rl->wyswietl_l();
	cout << endl;
	rd->wyswietl_d();

	/*
	for (int i = 0; i < 10; i++) {
		Samochod* p = new Samochod();
		rd->wstaw_d(p);
	}

	rl->wyswietl_l();
	cout << endl << endl;
	rd->wyswietl_d();
	*/
	cout << rl->ilosc_l() <<  endl;
	cout << rd->ilosc_d() << endl;
	cout << rl->ile_sz_l(200) << endl;
	cout << rl->suma_c_l() << endl;
	cout << rl->srednia_c_l() << endl;
	cout << rd->najm_d() << endl;
	cout << rd->ile_d_d(60) << endl;
	cout << rd->suma_c_d() << endl;

	

										// zostaje tylko wykonać zadania z przenoszeniem i taki algorytm napisać, no i sprawdzanie wysokości drzewa zostało
										// wyrzej sprawdzone są wszystkie funkcje no poza wysokością drzewa i wszystkie działają

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
