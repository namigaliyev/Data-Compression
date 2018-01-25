#include "Huffman.hpp"

int main(){
	Huffman *huffman = new Huffman("text.txt");
	int secim=0;
	huffman->Kodla();
	cout<<*huffman;
	while(true)
	{
		system("cls");
		cout<<"1. Dosyayi Sikistir"<<endl;
		cout<<"2.Sikistirilmis dosyayi ekrana yaz"<<endl;
		cout<<"3.Cikis"<<endl;
		cout<<"Seciminiz : ";
		cin>>secim;

		if(secim==1)
		{
			huffman->CevirerekDosyayaYaz();
			cout<<"Dosya Basariyla Sikistirildi"<<endl;
		}
		if(secim==2)
		{
			cout<<huffman->CevirerekDosyadanOku();
		}
		else if(secim==3)
		{
			cout<<"Cikis yaptiniz"<<endl;
			break;
		}
		system("pause");
	}

	delete huffman;
	return 0;
}
