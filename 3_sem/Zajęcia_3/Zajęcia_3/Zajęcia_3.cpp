// Zajęcia_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Pojazd {

protected:
    double moc, pojemnosc, masa, R, S, N;
    int predkosc, liczba_kol;

public:
    virtual void oblicz_predkosc() {
        predkosc = 0;
    }

    void ustaw_moc(double a) {
        moc = a;
        oblicz_predkosc();
    }

    void ustaw_mase(double a) {
        masa = a;
        oblicz_predkosc();
    }
    void oblicz_pojemnosc() {
        pojemnosc = (R * R * S * N) / 1000;
    }

    double return_moc() {
        return moc;
    }
    double return_pojemnosc() {
        return pojemnosc;
    }
    double return_masa() {
        return masa;
    }
    double return_R() {
        return R;
    }
    double return_S() {
        return S;
    }
    double return_N() {
        return N;
    }
    int return_predkosc() {
        return predkosc;
    }
    int return_kola() {
        return liczba_kol;
    }

};

class Samochod : public Pojazd {

public:

    void oblicz_predkosc() {
        predkosc = moc * pojemnosc / (4 * masa);
    }
    void wyswietl() {
        cout << "Samochod o mocy: " << moc << " , pojemnosci: " << pojemnosc << " , masie: " << masa << " , prędkości maksymalnej: " << predkosc << endl;
    }

    Samochod() {
        masa = rand() % 1500 + 1000;
        moc = rand() % 300 + 300;
        R = rand() % 10 + 70;
        S = rand() % 20 + 100;
        N = 2 * rand() % 3 + 4;
        liczba_kol = 4;
        oblicz_pojemnosc();
        oblicz_predkosc();

    }

    Samochod( const Samochod& a) {          //nie wiem czemu tu musi być const ale musi.  można zmienne wywoływać tylko tak jak poniżej nie można poprzez funkcje return
        masa = a.masa;
        moc = a.moc;
        R = a.R;
        S = a.S;
        N = a.N;
        liczba_kol = 4;
        oblicz_pojemnosc();
        oblicz_predkosc();

        cout << "jestem konstruktorem kopiującym klasy Samochod" << endl;

    }

    Samochod operator+ (Samochod& b) {
        return Samochod();
    }
};

class Motor : public Pojazd {
public:

    void oblicz_predkosc() {
        predkosc = (moc * pojemnosc) / (3.5 * masa);
    }

    void wyswietl() {
        cout << " Motor o mocy: " << moc << " pojemnosci: " << pojemnosc << " masie: " << masa << " oraz prędkości maksymalnej: " << predkosc << endl;
    }

    Motor() {
        masa = rand() % 120 + 110;
        moc = rand() % 70 + 100;
        R = rand() % 10 + 70;
        S = rand() % 20 + 100;
        N = rand() % 2 + 1;
        liczba_kol = 2;
        oblicz_pojemnosc();
        oblicz_predkosc();

    }

    Motor(const Motor& a) {
        masa = a.masa;
        moc = a.moc;
        R = a.R;
        S = a.S;
        N = a.N;
        liczba_kol = 2;
        oblicz_pojemnosc();
        oblicz_predkosc();

        cout << "jestem konstruktorem kopiującym klasy Motor" << endl;

    }
    Motor(double a, double b) {
        masa = a;
        moc = b;
        R = rand() % 10 + 70;
        S = rand() % 20 + 100;
        N = rand() % 2 + 1;
        liczba_kol = 2;
        oblicz_pojemnosc();
        oblicz_predkosc();
    }

    Motor operator+ (Motor& a) {
        return Motor((masa + a.masa) / 2, (moc + a.moc) / 2);
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
