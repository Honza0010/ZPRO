#pragma once


#include <fstream>
#include <algorithm>
#include <cassert>
#include <initializer_list>

//using T = int;

struct Comparator;

template<typename T>
class ChytrePole
{
	T* pole = nullptr;
	int k = 0;		//Celkovy pocet prvku v poli
	int n = 0;		//Celková kapacita pole

public:
	ChytrePole();
	ChytrePole(const ChytrePole<T>& src);
	ChytrePole(std::initializer_list<T> list);
	~ChytrePole();
	void inicializace(int k, int n);
	void zrus();
	void pridejNaKonec(T data);		//Vlozi data na pozici za posledni prvek, konkretne this->k



	T& operator[](int i) const;
	ChytrePole<T>& operator=(const ChytrePole<T>& x);
	ChytrePole<T> operator+(const ChytrePole<T>& src);


	void smazPrvek(int i);


	class ChytrePole_Iterator
	{
		const ChytrePole<T>* a;
		int current = -1;
	public:
		ChytrePole_Iterator(const ChytrePole<T>* a, int current);
		ChytrePole_Iterator& operator++();
		const T& operator*() const;
		bool operator!=(const ChytrePole_Iterator& other) const;

		//friend class ChytrePole<T>;

	};

	ChytrePole_Iterator begin() const;
	ChytrePole_Iterator end() const;
	ChytrePole_Iterator posledni() const;
	void sort(bool (*porovnej)(T i, T j));
	void sort(Comparator porovnej);
	//friend std::ostream& operator<<(std::ostream& os, const ChytrePole<T>& a);
	friend class ChytrePole_Iterator;
};



//template<typename T>
//std::ostream& operator<<(std::ostream& os, const ChytrePole<T>& a);

template<typename T>
ChytrePole<T>::ChytrePole()
{
	inicializace(0, 5);
}

template<typename T>
void ChytrePole<T>::inicializace(int k, int n)
{
	this->k = k;
	this->n = n;
	this->pole = new T[n];
}

template<typename T>
ChytrePole<T>::ChytrePole(const ChytrePole<T>& src)
{
	
	inicializace(src.k, src.n);
	for (int i = 0; i < k; i++)
	{
		this->pole[i] = src.pole[i];
	}
}

template<typename T>
inline ChytrePole<T>::ChytrePole(std::initializer_list<T> list) : ChytrePole()
{
	for (auto i : list)
	{
		pridejNaKonec(i);
	}
}


template<typename T>
ChytrePole<T>::~ChytrePole()
{
	zrus();
}

template<typename T>
void ChytrePole<T>::zrus()
{
	delete[] pole;
	pole = nullptr;
	n = 0;
	k = 0;
}

template<typename T>
void ChytrePole<T>::pridejNaKonec(T data)
{
	if (n == k)
	{
		this->n *= 2;
		T* pom = new T[this->n];
		for (int i = 0; i < k; i++)
		{
			pom[i] = this->pole[i];
		}
		//Zvetsim kapacitu 2x;
		delete[] pole;
		pole = pom;

	}
	this->pole[k] = data;
	this->k++;

}

template<typename T>
void ChytrePole<T>::smazPrvek(int i)
{
	if (i <= 0 || i > k)
	{
		assert(!(i < 0 || i >= k), "Out of interval");
		return;
	}
	for (int j = i; j < k; j++)
	{
		pole[j - 1] = pole[j];
	}
	k--;
}
//#define assertm(exp, msg) assert(((void)msg, exp))
template<typename T>
T& ChytrePole<T>::operator[](int i) const
{
	assert(!(i < 0 || i >= k), "Out of interval");
	return this->pole[i];
}

template<typename T>
ChytrePole<T>& ChytrePole<T>::operator=(const ChytrePole<T>& x)
{

	for (int i = 0; i < k && i < x.k; i++)
	{
		pole[i] = x.pole[i];
	}
	if (x.k > k)
	{
		for (int i = k; i < x.k; i++)
		{
			pridejNaKonec(x.pole[i]);

		}
	}
	return *this;
}

template<typename T>
ChytrePole<T> ChytrePole<T>::operator+(const ChytrePole<T>& src)
{
	ChytrePole vysledek(*this);

	for (int i = 0; i < src.k; i++)
	{
		vysledek.pridejNaKonec(src.pole[i]);
	}
	return vysledek;
}

template<typename T>
ChytrePole<T>::ChytrePole_Iterator::ChytrePole_Iterator(const ChytrePole<T>* a, int current)
{
	this->a = a;
	this->current = current;
}

template<typename T>
typename ChytrePole<T>::ChytrePole_Iterator& ChytrePole<T>::ChytrePole_Iterator::operator++()
{
	++current;
	return *this;
}

template<typename T>
typename ChytrePole<T>::ChytrePole_Iterator ChytrePole<T>::begin() const
{
	return ChytrePole<T>::ChytrePole_Iterator{ this, 0 };
}

template<typename T>
typename ChytrePole<T>::ChytrePole_Iterator ChytrePole<T>::end() const
{
	return ChytrePole<T>::ChytrePole_Iterator{ this, this->k };
}

template<typename T>
typename ChytrePole<T>::ChytrePole_Iterator ChytrePole<T>::posledni() const
{
	return ChytrePole<T>::ChytrePole_Iterator{ this, this->k - 1 };
}

template<typename T>
void ChytrePole<T>::sort(bool(*porovnej)(T i, T j))
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k-1; j++)
		{
			if (porovnej(pole[j], pole[j + 1]))
			{
				/*T pom = pole[j];
				pole[j] = pole[j + 1];
				pole[j + 1] = pom;*/
				std::swap(pole[j], pole[j + 1]);
			}
		}
	}
}

template<typename T>
inline void ChytrePole<T>::sort(Comparator porovnej)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k - 1; j++)
		{
			if (porovnej(pole[j], pole[j + 1]))
			{
				/*T pom = pole[j];
				pole[j] = pole[j + 1];
				pole[j + 1] = pom;*/
				std::swap(pole[j], pole[j + 1]);
			}
		}
	}
}

template<typename T>
const T& ChytrePole<T>::ChytrePole_Iterator::operator*() const
{
	//return a->pole[current];
	return a->operator[](current);
}

template<typename T>
bool ChytrePole<T>::ChytrePole_Iterator::operator!=(const ChytrePole_Iterator& other) const
{
	return (a != other.a) || (current != other.current);
}


