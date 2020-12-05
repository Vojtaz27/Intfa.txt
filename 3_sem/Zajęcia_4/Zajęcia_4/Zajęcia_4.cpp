// Zajęcia_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Miasto {

private:

    int ludzie;
    Miasto* next;

public:

    Miasto() {
        ludzie = rand() % 1100 + 100;
        next = NULL;
    }
    ~Miasto() {
    //if(next!=NULL) 
        cout << "jestem destruktorem miasta, usuwam miasto o liczbie: " << ludzie;
        //delete this;
    }

    void wstaw(Miasto* a) {
        if (next == NULL) next = a;
        else next->wstaw(a);
    }
    void wyswietl() {
        cout << ludzie << endl;
        if (next != NULL) next->wyswietl();
    }
    /*
    int max(int m=-1){
        if (m == -1) m = ludzie;
        if (m < next->ludzie) m = next->ludzie;
        if (next != NULL) next->max(m);
        else return m;
    }
    int max_ite(int count=0) {
        if (max() != ludzie) {
            count++;
            next->max_ite(count);
            //count++; 
        }
        else return count;
    }
    */
    
    int max()
    {
        Miasto* licznik = this;                              //wskaźnik pomocniczy wskazujący na przeważnie przyszły element i na początku podajemy wartość m
        int m = licznik->ludzie;                            //w pierwszym elemencie maxim równy ludziom w 1 mieście
        while (licznik->next != NULL){                      //sprawdzamy czy istnieje kolejny niepusty el
            if (m < licznik->next->ludzie) {                //sprawdzamy, czy liczba ludzi w nexcie jest wieksze od tego poczatkowego
                m = licznik->next->ludzie;
            }
            licznik = licznik->next;
        }
        return m;
    }
/*
    int max_ite()
    {

        Miasto* licznik = this; //wskaźnik pomocniczy

        int nr_pozycji = 0;
        int maksymalny_nr_pozycji;

        int maxim = licznik->ludzie; //w pierwszym elemencie maxim równy ludziom w 1 mieście

        while (licznik->next != NULL) //sprawdzamy czy istnieje kolejny niepusty el

        {

            nr_pozycji++;

            if (maxim < licznik->next->ludzie) //sprawdzamy, czy liczba ludzi w nexcie jest wieksze od tego poczatkowego

            {
                maksymalny_nr_pozycji = nr_pozycji;
                maxim = licznik->next->ludzie;

            }

            licznik = licznik->next;

        }
        return maksymalny_nr_pozycji;

    }*/

    int max_ite() {
        int  counter = 0;
        Miasto* licznik = this;                            //wsyaźnik robi to samo co w poprzedniej finkcji
        Miasto* pom = this;                                //ten wskaźnik służy temu żebym mógł wywołać fukncję max zawsze z tego samego miejsca 
        while (licznik->next != NULL){                      //to samo co poprzednio 
            if (pom->max() > licznik->ludzie){             //jeżeli wartość z funkcji wyzęj jest wiekszy od liczby ludzie (czyli nie jest równy) to wziększamy licznik 
                counter++;
            }
            else break;
            licznik = licznik->next;                        //wskaźnik pomocniczy staje się nextem przez co przechodzimy po każdym kolejnym elemencie listy 
        }
        return counter;

    }
    



};

int main()
{
    Miasto* mr = new Miasto();
    for (int i = 0; i < 14; i++) {
        Miasto* m = new Miasto();
        mr->wstaw(m);
    }
    mr->wyswietl();
    cout << endl;
    cout <<mr->max() << endl;
    cout <<mr->max_ite() << endl;
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
