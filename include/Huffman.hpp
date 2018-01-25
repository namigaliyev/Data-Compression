#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <fstream>
#include <cstring>

#include "Dugum.hpp"
#include "bitChar.hpp"
const int MAX=10000;
class Huffman{
	private:
		int harfler;			// harflerin ASCII karşılıkları
    int sayac=0;
		string girdi;			// dosyadan okunan girdi
		Dugum *root;
    string harflerrk[MAX];
    string harflerst;
    string harf;
    bitChar *bchar;
		string gelenbit;
		string bit;
		string kelimeler;

		Dugum* AgacOlustur(int frek[]);
		void KodOlustur(Dugum*,string);
		int MinDugumIndeks(Dugum* dugumler[]);
		void DosyaOku(string)throw(string);
		void inorder(Dugum*);
		void SilDugum(Dugum*);
	public:
		Huffman(string)throw(string);
		void Kodla();
    void CevirerekDosyayaYaz();
    string CevirerekDosyadanOku();
		friend ostream& operator<<(ostream&,Huffman&);
		~Huffman();

};


#endif
