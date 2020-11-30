// Zajecia_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
using namespace std;

class Jacht
{
private:
    int pojemnosc, paliwo, dystans;

public:

    Jacht(int poj, int pal){                                                    // nazwy zmiennych które są w funkcji są mało ważne są wykorzystywane tylko w tej funkcji
        cout << "jestem konstruktorem argumentowym"<< endl;
        pojemnosc = poj;
        paliwo = pal;
        //dystans = pojemnosc/ paliwo;

    }

    Jacht(){
        cout << "jestem konstruktorem bez argumentowym"<< endl;
        pojemnosc = rand() % 6000 + 4000;                                       // rand musi mieć te nawiasy bo jest funkcją, wybieamy z ilu liczb ma losować i przedział dolny określamy wartością po plusie
        paliwo = rand() % 699 + 500;
        dystans = pojemnosc / paliwo;
        //dystans = 5;
    }

    void Dodaj_paliwo(int pa) {
        paliwo += pa;
        dystans = 20*paliwo / pojemnosc;
    }

    void Ustaw_paliwo(int pa) {
        if (pa > pojemnosc) paliwo = pojemnosc;
        else paliwo = pa;
        dystans = pojemnosc / paliwo;
    }

    void Ustaw_pojemnosc(int po) {
        pojemnosc = po;
        dystans = paliwo / pojemnosc * 20;
    }

    void Oblicz_dysatns() {
        dystans = paliwo / pojemnosc * 20;
    }

    void wyswietl(){
        cout << "pwaliwo " << paliwo << " pojemnosc " << pojemnosc << " dystans " << dystans <<endl;
    }

    int return_paliwo() {
        //cout << "pwaliwo" << paliwo << endl;
        return paliwo;
    }

    int wyswietl_dystans() {
        //cout << "dystans" << dystans << endl;
        return dystans;
    }

    int wyswietl_pojemnosc() {
        //cout << "pojemnosc" << pojemnosc << endl;
        return pojemnosc;
    }

    Jacht operator+(Jacht& a) {                                                 // ooo tu sie robi ciekawie dutaj w skrócie mówimy jak program ma się zachować kiedy dodajemy dwa jachty
        return Jacht((pojemnosc + a.return_pojemnosc() / 2), paliwo + a.return_paliwo());  // w nawiasie pobieramy zmienną typu jacht i wrucamy ją do funkcji pod nazwą a
    }                                                                                       // przy pomocy "a.return_pojemnosc()" wyciągamy konkretną zmienną z jachtu o nazwie "a"

};

int main()
{
    Jacht jacht_1 = Jacht();
    Jacht jacht_2 = Jacht(5000, 500);

    Jacht* w1 = &jacht_1;
    Jacht* w2 = &jacht_2;
    Jacht jacht_3 = Jacht(0, 0);
    jacht_2.Dodaj_paliwo(500);
    jacht_1.wyswietl();
    jacht_2.wyswietl();
    cout << w1->wyswietl_dystans();
    jacht_3 = jacht_1 + jacht_2;
    jacht_3.wyswietl();

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
