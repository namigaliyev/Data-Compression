#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>
using namespace std;

class Dugum{
	public:
		char karakter;
		int frekans;	// Dosyada kaç kez tekrarlandığı
		string kod; 	// 01 kod karşılığı
		Dugum* sol;
		Dugum* sag;
		Dugum(char kr,int frek, Dugum* sl=NULL,Dugum *sg=NULL);
		bool Yaprakmi() const;
		bool operator==(Dugum&);
		bool operator!=(Dugum&);
		bool operator>(Dugum&);
};


#endif
