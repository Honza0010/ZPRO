#include "Seznam.h"
#include <iostream>

using namespace std;


void vytvorSeznam(Seznam& s)
{
	s.hlava = s.zarazka = new Prvek{0, nullptr};
	/*
	s.hlava = s.zarazka = new Prvek;
	s.hlava->data = 0;
	s.hlava->dalsi = nullptr;*/
}

bool jePrazdny(Seznam& s)
{
	return s.hlava == s.zarazka;
	/*
	if(s.hlava == s.zarazka)
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
}

void vlozNaZacatek(Seznam& s, T data)
{
	Prvek* pom = new Prvek;
	pom->data = data;
	pom->dalsi = s.hlava;
	s.hlava = pom;
}

void vypisSeznam(Seznam& s)
{
	Prvek* pom = s.hlava;
	while (pom != s.zarazka)
	{
		cout << pom->data << " ";
		pom = pom->dalsi;
	}
	cout << endl;
}

void odstranPrvni(Seznam& s)
{
	if (jePrazdny(s))
	{
		return;
	}
	Prvek* pom = s.hlava;
	s.hlava = s.hlava->dalsi;
	delete pom;
}

void vyprazdni(Seznam& s)
{
	while (!jePrazdny(s))
	{
		odstranPrvni(s);
	}
}

void zrus(Seznam& s)
{
	vyprazdni(s);
	delete s.hlava;
	s.hlava = s.zarazka = nullptr;
}

void vlozNaKonec(Seznam& s, T data)
{
	s.zarazka->data = data;
	s.zarazka->dalsi = new Prvek{ 0, nullptr };
	/*
	s.zarazka->dalsi = new Prvek;
	s.zarazka->dalsi->data = 0;
	s.zarazka->dalsi->dalsi = nullptr;
	*/
	s.zarazka = s.zarazka->dalsi;
}

Prvek* najdi(Seznam& s, T data)
{
	Prvek* pom = s.hlava;
	while (pom->data != data && pom != s.zarazka)
	{
		pom = pom->dalsi;
	}
	if (pom == s.zarazka)
	{
		return nullptr;
	}
	return pom;
}

void odstranZa(Seznam& s, Prvek* za)
{
	if (za->dalsi == s.zarazka)
	{
		return;
	}
	Prvek* pom = za->dalsi;
	za->dalsi = pom->dalsi;
	delete pom;
}

void odstran(Seznam& s, Prvek* mazany)
{
	if (mazany->dalsi != s.zarazka)
	{
		mazany->data = mazany->dalsi->data;
		odstranZa(s, mazany);
	}
	else //mazany->dalsi == s.zarazka
	{
		delete mazany->dalsi;		//Mažu prázdný prvek, na který ukazuje zarážka
		mazany->dalsi = nullptr;	//Zarážka musí ukazovat furt na nullptr
		s.zarazka = mazany;			//Novì bude zarážkou ten prvek, který jsme chtìli mazat. Tak ho nesmažeme ale udìláme z nìj zarážku a tím jsme ho vlastnì vyøadili ze seznamu
		s.zarazka->data = 0;		//Ukazatelu zarážky pøiøadíme nový prvek na konci
	}
}

Prvek* najdiNejmensi(Seznam& s)
{
	if (jePrazdny(s))
	{
		return nullptr;
	}
	Prvek* nejmensi = s.hlava;
	Prvek* pom = s.hlava;
	while (pom != s.zarazka)
	{
		if (pom->data < nejmensi->data)
		{
			nejmensi = pom;
		}
		pom = pom->dalsi;
	}
	return nejmensi;
}

void prohodSeznamy(Seznam& s, Seznam& z)
{
	Prvek* pom = s.hlava;
	s.hlava = z.hlava;
	z.hlava = pom;

	pom = s.zarazka;
	s.zarazka = z.zarazka;
	z.zarazka = pom;
}

void serad(Seznam& s)
{
	Seznam pomocny;
	vytvorSeznam(pomocny);
	Prvek* nejmensi;
	while (nejmensi = najdiNejmensi(s))
	{
		vlozNaKonec(pomocny, nejmensi->data);
		odstran(s, nejmensi);
	}
	prohodSeznamy(s, pomocny);
	zrus(pomocny);
}