﻿// Zajęcia_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
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
        numer = rand() % 100 + 100;
        left = NULL;
        right = NULL;
        next = NULL; 
    }
    void wstaw_l(Produkt* a) {
        Produkt* help = this;
        while (help->next != NULL) {
        if (next->numer > a->numer) {
            a->next = next;
            next = a;
        }
        else {
            help = next;
        }
    }
        if (next == NULL) next = a;
    }

};

int main()
{
    
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
