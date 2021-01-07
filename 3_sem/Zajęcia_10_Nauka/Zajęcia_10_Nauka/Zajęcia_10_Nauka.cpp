// Zajęcia_10_Nauka.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cstdlib>
#include <iostream>
using namespace std;


class Produkt {
private:
	int cena, numer;

public:
	Produkt* left;
	Produkt* right;
	Produkt* next;

	Produkt() {
		cena = rand() % 1000 + 1;
		numer = rand() % 200 + 100;
		left = NULL;
		right = NULL;
		next = NULL;
	}
	void wstaw_l(Produkt* a) {
		if (next == NULL) next = a;
		else if (next->numer < a->numer)  next->wstaw_l(a);
		else {
			a->next = this->next;
			this->next = a;
		}

	}
	void wstaw_d(Produkt* a) {
	
		if (cena < a->cena) {
			if (right == NULL) right = a;
			else  right->wstaw_d(a);
		}
		else {
			if (left == NULL) left = a;
			else left->wstaw_d(a);
		}
	}
	void wyswietl_d () {
		if (left) left->wyswietl_d();
		cout << "Ceana: " << cena  << endl;
		if (right) right->wyswietl_d();
	
	}
	void wyswietl_l() {
		cout << " Cena: " << cena << " numer: " << numer << endl;
		if (next) next->wyswietl_l();
	
	}
	int return_cena() {
		return cena;
	}

	int return_numer() {
		return numer;
	}
	int ile_l(int a=1) {
		if (next) a = next->ile_l(++a);
		return a;
	}
	int ile_d(int a = 1) {
		if (right) a = right->ile_d(++a);
		if (left) a = left->ile_d(++a);
		return a;
	}

};


int main() {

	Produkt* rl = new Produkt();
	for (int i = 0; i < 49; i++) {
		Produkt* pk = new Produkt();
		if (rl->return_numer() > pk->return_numer()) {
			pk->next = rl;
			rl = pk;
		}
		else rl->wstaw_l(pk);
	}

	rl->wyswietl_l();
	cout << rl->ile_l();
	cout << endl << endl;


	//  PRZENOSZENIE CAŁEJ LISTY DO DRZEWA   //DZIAŁĄ
	/*

	Produkt* rd = rl;
	rl = rl->next;
	rd->next = NULL;
	while (rl) {
		Produkt* supp = rl;
		rl = rl->next;
		supp->next = NULL;
		rd->wstaw_d(supp);
	}
	rd->wyswietl_d();

	*/


	// PRZENOSZENIE Z LISTY DO DZEWA BEZ PIERWSZEGO ELEMENTU		// RACZEJ DZIAŁA

	/*
	Produkt* rd = NULL;
	Produkt* supp = rl;

		while(!rd and  supp->next){
			if ((supp->next->return_cena()) % 2 == 0) {
				rd = supp->next;
				supp->next = rd->next;
				rd->next = NULL;
			}
			else supp = supp->next;
		}
		while (supp->next) {
			if ((supp->next->return_cena()) % 2 == 0) {
				Produkt* supp2 = supp->next;
				supp->next = supp2->next;
				supp2->next = NULL;
				rd->wstaw_d(supp2);
			}
			else supp = supp->next;
		
		}

		*/

	//PRZENOSZENIE Z LISTY DO SRZEWAZ UWZGLĘDNIENIEM PIERWSZEGO ELEMENTU

	Produkt *rd = NULL;

	if ((rl->return_cena()) % 2 == 0) {
	
		rd = rl;
		rl = rl->next;
		rd ->next = NULL;
		if (rl) {
			while ((rl->return_cena()) % 2 == 0) {
				Produkt* supp = rl;
				rl = rl->next;
				supp->next = NULL;
				rd->wstaw_d(supp);
				if (!rl) break;
			}
		}
		if (rl and rd) {
			Produkt* supp = rl;
			while (supp->next) {								// chyba coś ze mną nie tak bo zapomniałem o pętlach i dziwię sie czemu wypluwa 
				if ((supp->next->return_cena()) % 2 == 0) {		// 3 wyrazy z drzewie a w liście 1 
					Produkt* supp2 = supp->next;				//	PAMIĘTAJ O WHILE !!!!!
					supp->next = supp2->next;
					supp2->next = NULL;
					rd->wstaw_d(supp2);


				}
				else supp = supp->next;
			}
		}
	}
	else {
		Produkt* supp = rl;
		while (!rd and supp->next) {
			if ((supp->next->return_cena()) % 2 == 0) {
				rd = supp->next;
				supp->next = rd->next;
				rd->next = NULL;
			}
			else supp = supp->next;
		}
		if (rd) {
			while (supp->next) {
				if ((supp->next->return_cena()) % 2 == 0) {
					Produkt* supp2 = supp->next;
					supp->next = supp2->next;
					supp2->next = NULL;
					rd->wstaw_d(supp2);


				}
				else supp = supp->next;
			}
		}
	}
	
	rd->wyswietl_d();
	cout << endl << endl;
	cout << rd->ile_d() << endl;
	cout << rl->ile_l() << endl;





}





	/*
	Produkt* d = new Produkt();

	cout << endl;
	for (int i = 0; i < 10; i++) {
		Produkt* supp = new Produkt();
		d->wstaw_d(supp);
	}

	d->wyswietl_d();
	*/



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
