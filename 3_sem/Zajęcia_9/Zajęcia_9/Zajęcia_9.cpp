// Zajęcia_9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

class Prezent {
private:
	int cena, numer, liczba;
	public:
		Prezent* left;
		Prezent* right;
		Prezent* down;

		Prezent() {
			cena = rand() % 70 + 50;
			numer = rand() % 30 + 1;
			liczba = 0;
			left = NULL;
			right = NULL;
			down = NULL;
			cout << "Prezent dla: " << numer << " o cenie: " << cena << endl;
		}
		void wstaw(Prezent * a) {
			//++liczba;
			if (numer == a->numer) {
				++liczba;
				if (down) down->wstaw(a);
				else {
					down = a;
					//liczba=0;
				}
			}
			else if (numer < a->numer) {
				if (right) right->wstaw(a);
				else {
					//left ->liczba++;
					right = a;
				}
			}
			else {
				if (left) left->wstaw(a);
				else { 
					//left->liczba++;
					left = a; 
				}
			}
		}
		void wyswietl() {
			if (left) left->wyswietl();
			cout << cena << "  " << numer << endl;
			if (right) right->wyswietl();
		}
		void wyswietl2() {
			if (left) left->wyswietl2();						// left musi być pierwszy jeżeli chcemy od początku, za nim cout i reszta 
			cout << cena << " " << numer << " " << liczba << endl;
			if (down) down->wyswietl2();						// dwon musi byc nad right inaczej się źle wyświetla, no w sumie logiczne 
			if (right) right->wyswietl2();
			
		}
		int ilosc(int counter = 1) {                            // według wyświetlania pierwszego działa bo nie ma dwóch numerów po drodze a reszta niby powinna być w indeksie down
			if (right) counter = right->ilosc(++counter);
			if (left) counter = left->ilosc(++counter);
			return counter;
		}
		int ilosc2(int counter = 1) {							// no to nie działa jakby down nie widziało, działa jak funkcja wyżej
			if (down) counter = down->ilosc2(++counter);
			if (right) counter = right->ilosc2(++counter);
			if (left) counter = left->ilosc2(++counter);
			return counter;
		}
		int min(int minim=130) {								//  tutaj daje wartość z poza zakresu jak ostartową żeby na pewno zadziałało
			if (cena < minim) minim = cena;
			if (right) minim = right->min(minim);
			if (left) minim = left->min(minim);
			return minim;
		}
		int max(int maxim=0) {
			if (cena > maxim) maxim = cena;
			if (right) maxim = right->max(maxim);
		    if (left) maxim = left->max(maxim);
		    return maxim;

		}
		int ile_drozszych(int a, int counter =0) {						//nie można zwiększac countera przy wysyłąniu go do funkcji bo nie wiemy w tym przypadku co będzie następne, 
			if (cena > a) ++counter;									//[ lepiej sprawdzać na początku potem wysyłać dalej ]
			if (down) counter = down->ile_drozszych(a, counter);		// jak zakomentuje tą linię to będzie działało bez down
			if (right) counter= right->ile_drozszych(a, counter);
			if (left) counter =left->ile_drozszych(a, counter);
			return counter;
		
		}

		// trzeba napisać program zwracający który numer otrzymał najwięcej prezentów;

		int h() {
			if (!left and !right)return 0;
			else {
				int l = 0;
				int r = 0;
				if (left) l += left->h();
				if (right) r += right->h();
				return l > r ? (l + 1) : (r + 1);
			}
		}
};
 
int main()
{
	Prezent* k = new Prezent();
	for (int i = 0; i < 54; i++) {
		Prezent* pk = new Prezent();
		k->wstaw(pk);
	}
	k->wyswietl();
	cout << k->ilosc2() << endl;
	cout << k->max() << endl;
	cout << k->min() << endl;
	//cout << k->ile() << endl;
	cout <<k->ile_drozszych(100);
	cout << k->h();
   
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
