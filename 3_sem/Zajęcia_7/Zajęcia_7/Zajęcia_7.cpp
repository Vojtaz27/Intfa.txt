// Zajęcia_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

class Produkt {
	private:
		int cena, numer;
public:
	Produkt* prev;
	Produkt* next;

	Produkt(int a) {
		cena = rand() % 100 + 1;
		numer = a;
		prev = NULL;
		next = NULL;
	}

	~Produkt() {
		cout << "Usuwam: " << cena <<" (" << numer << "). " << endl;
	}

	void wstaw(Produkt* a) {
		if (next) next->wstaw(a);
		else {
			a->prev = this;
			next = a;
			
		} 
	}

	/*void wstaw2(Produkt* a) {
		if (next = NULL) next = a;
		a->next = this->next;
		this->next->prev = a;
		this->next = a;
		a->prev = this;
		if (cena < a->cena) {
			if (next == NULL) {
				next = a;
				//a->prev = this;
			}
			else next->wstaw2(a);
		}
		else if (cena > a->cena) {
			if (prev == NULL) {
				prev = a;
				a->next = this;
			}
			else prev->wstaw(a);
		}
	}
	*/
	
	
	/*
	void wstaw2(Produkt* a) //tworzenie tablicy dwukierunkowej 
	{
		if (cena > a->cena)
		{
			if (prev == NULL)
			{
				prev = a;
				a->next = this;
			}
			else if (prev->cena < a->cena)
			{
				a->next = this;
				a->prev = this->prev;
				this->prev->next = a;
				prev = a; //this->left=a;
			}
			else
			{
				prev->wstaw2(a);
			}
		}
		else
		{
			if (next == NULL)
			{
				next = a;
				a->prev = this;
			}

			else if (next->cena > a->cena)
			{
				a->next = this->next;
				a->prev = this;
				this->next->prev = a;
				next = a;
			}

			else
			{
				next->wstaw2(a);
			}

		}
	}
	*/

	void wstaw2(Produkt* a) {
		if (cena < a->cena) {

			if (next == NULL) {
				next = a;
				a->prev = this;
			}
			else if (next->cena > a->cena) {
				a->next = this->next;
				this->next = a;
				this->next->prev = a;
				a->prev = this;
			}
			else next->wstaw2(a);
		}
		else {
			if (prev == NULL) {
				prev = a;
				a->next = this;
			}
			else if (prev->cena < a->cena)
			{
				a->prev = this->prev;
				this->prev->next = a;
				this->prev = a;
				a->next = this;
				
			}
			else prev->wstaw2(a);
		
		}
	
	}

	void wyswietl() {
		if (prev) {
			prev->wyswietl();
		}
		else this->wys();
	}

	void wys() {
		cout << cena << " (" << numer << "). " << endl;
		if (next) next->wys();
	
	}

	int return_cena() {
		return cena;
	}

	void ustaw_cene(int a) {
		cena = a;
	}
};

int main()
{
	Produkt* p1 = new Produkt(0);
	p1->ustaw_cene(45);
	for (int i = 1; i <= 10; i++)
	{
		Produkt* pk = new Produkt(i);
		p1->wstaw2(pk);
	}
	Produkt * pk = new Produkt(11);
	Produkt* pt = new Produkt(12);
	pk->ustaw_cene(110);
	pt->ustaw_cene(50);
	p1->wstaw(pk);
	p1->wstaw(pt);
	pk->wyswietl();
	Produkt* test = new Produkt(0);
	test->ustaw_cene(1);
	p1->wstaw2(test);
	//p1->ustaw_cene(7);
	Produkt* p = test;
	//test->wstaw(p);
	//test->wyswietl();
	while (p) { 
		if ((p->return_cena()) % 2 == 0) {
			if (p->next) p->next->prev = p->prev;
			if (p->prev) p->prev->next = p->next;
			Produkt* supp = p;
			p = p->next;
			delete supp;
		}
		else p = p->next;
	}
	test->wyswietl();
	
   
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
