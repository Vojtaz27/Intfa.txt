// Zajęcia_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

class Produkt {

private:
    int cena;
public:
    Produkt* left;
    Produkt* right;
    Produkt() {
        cena = rand() % 200 + 100;
        left = NULL;
        right = NULL;
        cout << "P " << cena << endl;
    }
    ~Produkt() {
        if (right) delete right;
        if (left) delete left; 
        cout << "~ P " << cena <<  endl;
    }
    void wstaw(Produkt * a) {
        if (cena < a->cena){
            if (right) right->wstaw(a);
            else right = a;
        }
        else {
            if (left) left->wstaw(a);
            else left = a;
        }
    }
    void wyswietl() {
        if (left) left->wyswietl();
        cout << cena << endl;
        if (right) right->wyswietl();
    }
    int return_cena() {
        return cena;
    }
    int ilosc(int counter =1) {
        if (right) counter = right->ilosc(++counter);
        if (left) counter = left->ilosc(++counter);
         return counter;
    }
    int ilosc_lewo() {
        if (left) return left->ilosc();
        else return 0;
    }
    int ilosc_prawo() {
        if (right) return right->ilosc();
        else return 0;
    }
    int max(int maxim = 0) {
        if (cena > maxim) maxim = this->cena;
        if (right) maxim = right->max(maxim);
        return maxim;
    }
    int min() {
        if (left) return left->min();
        else return cena;
    
    }
    void ustaw_cene(int a) {
        cena = a;
    }
    void znajdz(int a) {
        if (cena == a) cout << "jest" << endl;
        if (cena < a) {
            if (right) right->znajdz(a);
            else cout << "nie ma" << endl;
        }
        else if (cena > a) {
            if (left) left->znajdz(a);
            else cout << " nie ma" << endl;
        }
    }
    int ile_drozszych(int a, int counter=0) {
        
        if((cena >a) ) {
            if (counter == 0)++ counter;
            if (right) counter =right->ile_drozszych(a,++counter);
            if (left) counter =left->ile_drozszych(a,++counter);
        }
        else  counter =right->ile_drozszych(a);
        return counter;

        
    }


};

int main()
{
    Produkt* p1 = new Produkt();
    p1->ustaw_cene(200);
    for (int i = 0; i < 10; i++) {
        Produkt* pp = new Produkt();
        p1->wstaw(pp);
    }
    p1->wyswietl();
    cout <<p1->ilosc() << endl;
    cout << p1->ilosc_prawo() << endl;
    cout << p1->ilosc_lewo() << endl;
    cout << p1-> max() << endl;
    cout << p1->min() << endl;
    p1->znajdz(224);
   cout << p1->ile_drozszych(200);

    
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
