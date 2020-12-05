// Zajęcia_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Ksiazka {

private:
    int strony;

public:
   Ksiazka *next;

   Ksiazka() {
       strony = rand() % 199 + 100;
       next = NULL;
   }
   Ksiazka(int a) {
       strony = a;
       next = NULL;
   }
   ~Ksiazka() {
       cout << "Jestem destruktorem, usuwam książkę o liczbie stron: " << strony << endl;
   }
   void wstaw(Ksiazka *a) {
       if (next != NULL) next = a;                      //jeżeli next to NULL to wskaźnik next = wstaźnik a
       else next->wstaw(a);                             //w przeciwnym przypadku wywołaj funkcję wstaw a dla nexta
   }
   void wstaw_r(Ksiazka* a) {
   
       //Ksiazka* pom = this;
       if (next == NULL) next = a;
       else if (a->strony > next->strony) {
           a->next = this->next;                                //przejmujemy nexta wskaźnika na którym jesteśmy  (bierzemy namiary na somsiada)
           this->next = a;                                      //dajemy wskaźnikowi na którym stoimy namiary na siebie 
       }
       else next->wstaw_r(a);
   }

   void wyswietl_k() {
       cout << strony << endl;
       if (next != NULL) next->wyswietl_k();
   }

   int return_strony() {
       return strony;
   }
   void delete_list() {
       if (next != NULL) next->delete_list();
       delete this;
   }
};

int main()
{
    Ksiazka* k1 = new Ksiazka(300);
    for (int i = 0; i < 50; i++)
    {
        Ksiazka* n = new Ksiazka();
        k1->wstaw_r(n);
    }
    k1->wyswietl_k();
    Ksiazka* k1l = new Ksiazka(301);                    //nie wiem jak to kurwa zrobić 
   /* Ksiazka* pom = k1;
    while (pom->next != NULL){
        if ((pom->return_strony()) % 2 == 1) {
        
            
            k1l->next->wstaw(pom);
            pom = pom->next;
        }
       else pom = pom->next;
    }




    Ksiazka* p = k1; //p wskazuje na pierwszy element 
    while (p->next != NULL) //do póki next nie jest rówy 0
    {
        if (p->next->return_strony() % 2 == 1) //jeśli drugiego elemntu(nexta) ilosc stron nie jest podielna przez 2
            if (p->next->next != NULL) //i jeśli next nexta jest równy od0
            {
                Ksiazka* p2 = p->next; //obiekt za p
                p->next = p2->next;    //next p2 zostaje neztem p
                p2->next = NULL;       //p2 ma nexta równego 0, żeby odłączył się od tamtego 
                k1l->wstaw(p2);      //wstawiamy do nowej tablicy 
            }
            else //wykonuje sie jesli nie spełnia drugiego ifa
            {
                Ksiazka* p2 = p->next; //p2 za p
                p->next = NULL; //jeśli za p2 niczego nie ma to ustawiamy next na 0
                k1l->wstaw(p2);
            }
        else //wykonuje sie kiedy nie wchodzi do pierwszego ifa
        {
            p = p->next;
        }
    }
    
    k1l->wyswietl_k();
    */
    k1->delete_list();
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
