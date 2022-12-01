#ifndef _SEZNAM_H_
#define _SEZNAM_H

using T = int;

struct Prvek
{
	T data;
	Prvek* dalsi;
};

struct Seznam
{
	Prvek* hlava;
	Prvek* zarazka;
};


void vytvorSeznam(Seznam& s);
bool jePrazdny(Seznam& s);
void vlozNaZacatek(Seznam& s, T data);
void vypisSeznam(Seznam& s);
void odstranPrvni(Seznam& s);
void vyprazdni(Seznam& s);
void zrus(Seznam& s);
void vlozNaKonec(Seznam& s, T data);
Prvek* najdi(Seznam& s, T data);
void odstranZa(Seznam& s, Prvek* za);
void odstran(Seznam& s, Prvek* mazany);
Prvek* najdiNejmensi(Seznam& s);
void prohodSeznamy(Seznam& s, Seznam& z);
void serad(Seznam& s);

void vlozZa(Seznam& s,Prvek* za, T data); //DOm�c� �kol
void odstranPosledni(Seznam& s);	//Dom�c� �kol

void bubbleRazeni(Seznam& s);		//Hv�zdi�kov� dom�c� �kol
#endif
