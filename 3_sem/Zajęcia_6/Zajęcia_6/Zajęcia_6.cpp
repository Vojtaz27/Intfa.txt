// Zajęcia_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Film {

private:
    int cena, numer, ocena, typ;
public:
    Film* down;
    Film* next;

    Film( int a) {
        numer = a;
        cena = rand() % 99 + 1;
        ocena = rand() % 99 + 1;
        typ = rand() % 5 + 1;
        down = NULL;
        next = NULL;
    }

    Film(int a , int b) {
        numer = a;
        cena = b;
        ocena = rand() % 99 + 1;
        typ = rand() % 5 + 1;
        down = NULL;
        next = NULL;
    }

    ~Film(){
        cout << "Usuwam film o cenie: " << cena << ",numerze: " << numer << ",ocenie: " << ocena << endl;
    }

    void wstaw(Film* a) {
        if (next == NULL) next = a;
        else {
            if (next->cena < a->cena) next->wstaw(a);
            else {
                a->next = this->next;
                this->next = a;
            }
        }
    }

    void wstaw2(Film * a) {
        Film* licz = this;
        if (licz->next == NULL) next = a;
        else {
            licz = licz->next;
            licz->wstaw2(a);
        }
    }
    /*void  wstaw3(Film* a) {
        //Film* licz = this;
        if (down == NULL) a = down;
        else if {
            this = this->down;
            this->wstaw2(a);
        }
        if (a->cena < down->cena) down->wstaw3(a);
        else next->wstaw2(a);
    }*/
    void wstaw3(Film* a) {
        if (next == NULL) next = a;
        else {
            if (a->cena >next->cena) next->wstaw3(a);
            else {
                a->next = next;
                next = a;
            }
        }
    }

    void wyswietl() {
        cout << "C: " << cena << "N: " << numer << "O: " << ocena << "T: " << typ << endl;
    }

    void wyswietl2() {
        Film* licz = this;
        Film* eee = this;
        while (next) {
            cout <<"ocena "<< licz->ocena << " " << "typ " << licz->typ << " "<< endl;
            if (licz ->next== NULL) break;
            licz = licz->next;
        }
        cout << endl;
        if (down!=NULL) eee->down->wyswietl2();
    }

    int return_cena() {
        return cena;
    }

    int return_numer() {
        return numer;
    }

    int return_typ() {
        return typ;
    }

    int return_ocena() {
        return ocena;
    }

    int max() {
        Film* supp = this;
        //Film* m = a;
        while (down) {
            supp = down;
        }
        Film* m = supp;
        while (supp->next)
        {
            if (supp->ocena > m->ocena)
            {
                m->ocena = supp->ocena;
            }
            supp = supp->next;
        
        }

        return m->ocena;

    }

    int ile_t(int a,int count=0)
    {
        if (a == typ) count++;
        if (next) count = next->ile_t(a, count);
        return count;
    }

    void usun_liste() {
        if (down) down->usun_liste();
        if (next) next->usun_liste();
        if (numer == 0);
        else delete this;
    }
};

int main()
{
    Film* k = new Film(0, 0);

    for (int i = 0; i < 50; i++)
    {
        Film* kf = new Film(i);
        k->wstaw(kf);
    }
    k->wyswietl2();
    cout << endl;
    cout <<k->max();
    cout << k->ile_t(1);
    k->usun_liste();
    k->wyswietl();
    k->wyswietl();
    for (int i = 0; i < 9; i++){
        Film* kf = new Film(0, i * 10);
        k->wstaw3(kf);
    }
    k->wyswietl2();
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
