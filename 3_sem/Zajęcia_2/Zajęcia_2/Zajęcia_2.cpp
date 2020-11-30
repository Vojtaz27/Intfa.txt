// Zajęcia_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

class Figura {

protected:
    double pole, obwod;

public:

    void show_pole() {
    
        cout << pole << endl;
    }
    void show_obwod() {
    
        cout << obwod << endl;
    }

    double return_pole() {
        return pole;
    }

    double return_obwod() {
        return obwod;

    }

    virtual void wyswietl() {       // przed funkcjami virtualnymi piszemy virual będzie ona nieco nadpisywana klikasz ->
                                    // akak w grze ale to jaki atak wykonasz zależy od tego jaką postać (funkcję albo nie wiem coś takiego) wybrałeś 
        cout << 0 << endl;
    }

    virtual void oblicz_pole() {    
    
        pole = 0;
    }

    virtual void oblicz_obwod() {

        obwod = 0;
    }



};

class Kwadrat : public Figura {     // deklarując klasę która dziedziczyz  drugiej piszemy nową klase i po myslniku to z jakiej klasu i jakiej sekcji dzieczy (co do sekcji nie jestem pewien)

protected:
    double bok;

public:

    void oblicz_pole(){
        pole = bok * bok;
    }

    void oblicz_obwod() {
        obwod = 4 * bok;
    }

    double return_bok() {
        return bok;

    }

    void wyswietl() {
        cout << "Kwadrat o polu: " << pole << " i obwodzie: " << obwod << endl;
    }

    Kwadrat() {
        bok = rand() % 10 + 1;
        oblicz_pole();
        oblicz_obwod();
    }

    Kwadrat(double inp) {
        bok = inp;
        oblicz_pole();
        oblicz_obwod();
    }

    Kwadrat(const Kwadrat& a) {     // nie wiem czelu const. Bierzemy "Z Kawadratu" znaczek referencji i nazwa zmiennej (mało ważna) 
        bok = a.bok;                //dajemy programowi znać ze chcemy z kwadratu który wysłąliśmy do funkcji pobrać konkretne dane czyli np bok
        pole = a.pole;              // albo pole 
        obwod = a.obwod;            //albo obwod 
    
    }

};

class Prostokat : public Kwadrat {

private:
    double wysokosc, szerokosc;

public:
    void oblicz_pole() {
        pole = szerokosc * wysokosc;
    }

    void oblicz_obwod() {
        obwod = (szerokosc + wysokosc) * 2;
    }

    Prostokat() {
        szerokosc = rand() % 10 + 1;
        wysokosc = rand() % 10 + 1;
        Kwadrat :: oblicz_pole();   //to chyba działa tak samo jak funkcja wirtualna w sensie że ją nadpisuje dodatkowo. W każdy razie dziedziczymy z kwadratu te funkcję 
                                    //(chyba chodzi o to że nie dziedziczymy już z funkcji wirtualnej tylko "zadeklarowanej")
        Kwadrat :: oblicz_obwod();  // EDIT to jesnak działą tak że wykonuje się funkcja z kwadrata a nie z prostokata wybieramy a ktorej umiejetnosci chcemy skorzystać 
    }

    Prostokat(double inp) {
        bok = inp;
        szerokosc = inp;
        wysokosc = inp;
        Kwadrat::oblicz_obwod();
        Kwadrat::oblicz_pole();
    }

    Prostokat(double a,double b) {
        bok = a;
        szerokosc = a;
        wysokosc = b;
        Kwadrat ::oblicz_pole(); 
        Kwadrat::oblicz_obwod();

    }

    void wyswietl() {
        cout << "Prostokąt o polu: " << pole << " i obwodzie: " << obwod << endl;
    }


};

class Kolo : public Figura {

private:
    double promien, pi = 3.14;

public:
    Kolo() {
        promien = rand() % 10 + 1;
        oblicz_pole();
        oblicz_obwod();
    }
    Kolo(double r) {
        promien = r;
        oblicz_pole();
        oblicz_obwod();
    }

    void oblicz_pole() {
        pole = pi * promien * promien;
    }

    void oblicz_obwod() {
        obwod = 2 * pi * promien;
    }

    void wyswietl() {
        cout << "Kolo o polu: " << pole << " i obwodzie: " << obwod << endl;
    }

};

int main()
{
    Prostokat pr_1 = Prostokat();
    Prostokat pr_2 = Prostokat(6);
    Prostokat pr_3 = Prostokat(4 , 7);

    Figura * wpr_1 = &pr_1;
    Figura * wpr_2 = &pr_2;
    Figura * wpr_3 = &pr_3;

    cout << wpr_1->return_pole() << endl;
    cout << wpr_2->return_pole() << endl;
    cout << wpr_3->return_pole() << endl;
    
    Kwadrat* w_k_1 = new Kwadrat(7);    // tutaj roumiem ze robimy skrócony zapis i nie deklarujemy zmniennej zapisujemy że pod wskaźniekiem "w_k_1" będzie nowy kwadrat o boku 7 
                                        // tylko nie ma nazwy zmiennej tylko sam wskaźnik
    Kwadrat k_2 = *w_k_1;               // w tym miejscu inicjuję konstruktor kopiujący czyli kwadrat "k_2" równa się to co pod wskaźniekiem "w_k_1" czyli inny kwadrat
    k_2.wyswietl();

    Kolo* w_o_1 = new Kolo();
    Kolo o_1 = Kolo(3);
    Figura* w_o_2 = new Kolo();

    Figura* tablica_1[8];
    tablica_1[0] = wpr_1;
    tablica_1[1] = wpr_2;               // * to miejsce w pamięci // & to to co się w zmiennej znajduje  // -> jest od tego rzeby wywołać daną funkcję dal danego wskaźnika
                                        //w przeciwnieństwie do zmiennej bo wtedy robimy "nazwazmiennej" . "funkcja którą chcemy wywołać"
    tablica_1[2] = wpr_3;
    tablica_1[3] = w_k_1;
    tablica_1[4] = &k_2;
    tablica_1[5] = w_o_1;
    tablica_1[6] = &o_1;
    tablica_1[7] = w_o_2;

    for (int i = 0; i < 8; i++) {
        tablica_1[i]->wyswietl();
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            if (tablica_1[i]->return_pole() > tablica_1[j]->return_pole()) swap(tablica_1[i], tablica_1[j]);
        }
    }

    for (int i = 0; i < 8; i++) {
        tablica_1[i]->wyswietl();
    }
    
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
