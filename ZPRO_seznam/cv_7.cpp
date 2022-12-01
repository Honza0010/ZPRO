#include <iostream>
#include "Seznam.h"

using namespace std;


void test()
{
    Seznam s;
    vytvorSeznam(s);
    vlozNaZacatek(s, 1);
    vlozNaZacatek(s, 2);
    vlozNaZacatek(s, 3);
    vlozNaKonec(s, 4);
    vlozNaKonec(s, 5);
    vlozNaKonec(s, 6);
    vypisSeznam(s);

    Prvek* pom = najdi(s, 4);
    if (pom != nullptr)
    {
        cout << pom->data << endl;
    }
    else
        cout << "Zadana hodnota neni v seznamu" << endl;
    odstran(s, pom);

    vypisSeznam(s);

    pom = najdiNejmensi(s);
    if (pom != nullptr)
    {
        cout << pom->data << endl;
    }

    serad(s);
    vypisSeznam(s);

    zrus(s);
}

int main()
{
    test();
}

