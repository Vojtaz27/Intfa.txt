// infa_zajecia4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

class Produkt {

private:
    int cena, numer;

public:
    Produkt* prev, * next;

    Produkt(int a) {

        cena = rand() % 100 + 1;
        numer = a;
        prev = NULL;
        next = NULL;


    }
    ~Produkt() {
        cout << "Usuwam: " << cena << " " << numer;
    }

    void wstaw(Produkt* nowa) {

        if (next != NULL) next->wstaw(nowa);
        else {
            next = nowa;
            nowa->prev = this;
        }

    }

    void wstaw2(Produkt* nowa) {

        if (this->cena < nowa->cena) {
            if (next == NULL) {
                next = nowa;
                nowa->prev = this;

            }
            else {
                if (next->cena < nowa->cena)next->wstaw2(nowa);
                else {
                    nowa->next = next;
                    nowa->prev = this;
                    next->prev = nowa;
                    next = nowa;
                }
            }
        }
        else {
            if (prev == NULL) {
                prev = nowa;
                nowa->next = this;
            }
            else {
                if (nowa->cena < prev->cena) prev->wstaw2(nowa);
                else {
                    nowa->next = prev;
                    nowa->next = this;
                    prev->next = nowa;
                    prev = nowa;
                }

            }



        }
    }
};
int main() {
    return 0;
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
