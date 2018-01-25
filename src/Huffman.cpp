#include "Huffman.hpp"

Huffman::Huffman(string dosyaYolu)throw(string){
      bchar=new bitChar();

			harfler = 256;
			girdi="";
			try{
				DosyaOku(dosyaYolu);
			}
			catch(string ex){
				throw ex;
			}
			root=NULL;
		}
void Huffman::DosyaOku(string dosyaYolu)throw(string){
	string satir;
	ifstream dosya(dosyaYolu.c_str());
	if (dosya.is_open())
	{
		while (getline(dosya,satir))
		{
			girdi+=satir;
			girdi+='\n';
		}
		dosya.close();
	}
	else throw "Dosya acilamadi";
}
void Huffman::Kodla(){
	char karakterler[girdi.size()-1];

	strcpy(karakterler, girdi.c_str());

	//Frekansları say
	int frek[harfler];
	// frekansları sıfırla
	for(int i=0;i<harfler;i++)frek[i] = 0;

	for (int i = 0; i < girdi.size()-1; i++)
		frek[karakterler[i]]++;

	// Huffman ağacını oluştur
	root = AgacOlustur(frek);

	// 01 kodlar oluşturuluyor
	KodOlustur(root, "");
}

void Huffman::CevirerekDosyayaYaz()
{

  ofstream outf("Bit.dat",ios::binary);
  for(int i=0;i<girdi.size();i++)
  {
    for(int j=0;j<sayac;j++)
    {
      if(girdi[i]==harflerst[j])
      {
        harf+=harflerrk[j];//harflerin rakam karsiliklari ataniyor
      }
    }
  }

  bchar->setBITS(harf);
  bchar->insertBits(outf);
}

string Huffman::CevirerekDosyadanOku()
{

  ifstream inf("Bit.dat",ios::binary);
  gelenbit=bchar->readByBits(inf);


	for(int i=0;i<gelenbit.size();i++)
	{
		bit+=gelenbit[i];
		for(int j=0;j<sayac;j++)
		{
			if(bit==harflerrk[j])
			{
        kelimeler+=harflerst[j];
				bit="";
			}
		}
	}
	return kelimeler;
}

Dugum* Huffman::AgacOlustur(int frek[]){
	// dosyada var olan karakterler için düğüm oluştur.
	Dugum* dugumler[harfler];
	for(int i=0;i<harfler;i++){
		if(frek[i]>0){
			dugumler[i] = new Dugum((char)i,frek[i]);
		}
		else{
			dugumler[i] = NULL;
		}
	}
	while(true){
		int ilkIndeks = MinDugumIndeks(dugumler);
		Dugum *min1 = dugumler[ilkIndeks];
		dugumler[ilkIndeks] = NULL;
		int ikinciIndeks = MinDugumIndeks(dugumler);
		if(ikinciIndeks == -1){
			return min1;
		}
		Dugum *min2 = dugumler[ikinciIndeks];
		dugumler[ikinciIndeks] = NULL;
		dugumler[ilkIndeks] = new Dugum(0,min1->frekans+min2->frekans,min1,min2);
	}

}
int Huffman::MinDugumIndeks(Dugum* dugumler[]){
	Dugum* min;
	int minIndeks=-1;

	// ilk null olmayan düğümü min al
	for(int i=0;i<harfler;i++){
		if(dugumler[i] != NULL){
			min = dugumler[i];
			minIndeks = i;
			break;
		}
	}

	for(int i=0;i<harfler;i++)
	{
		if(dugumler[i] == NULL) continue;

		if(*min > *(dugumler[i])) {
			min = dugumler[i];
			minIndeks = i;
		}
	}
	return minIndeks;
}

void Huffman::KodOlustur(Dugum* alt_dugum,string kod){
	if(!alt_dugum->Yaprakmi()){
		KodOlustur(alt_dugum->sol,kod+'0');
		KodOlustur(alt_dugum->sag,kod+'1');
	}
	else{
		alt_dugum->kod = kod;
	}
}

ostream& operator<<(ostream& ekran,Huffman& sag){
	ekran<<"Huffman Agacindaki Karakterler ve Kodlari:"<<endl;
	sag.inorder(sag.root);
	return ekran;
}
void Huffman::inorder(Dugum* alt_dugum){
  remove("table.txt");
  fstream dosya;
	string gelen1;
	string gelen2;
	string toplam;
  dosya.open("table.txt",ios::out|ios::app);
	if(alt_dugum != NULL){
		inorder(alt_dugum->sol);
		if(alt_dugum->Yaprakmi())
    {
			gelen1=alt_dugum->karakter;
			gelen2=alt_dugum->kod;

			harflerst+=gelen1;
      harflerrk[sayac]=gelen2;
      toplam+=gelen1+":"+gelen2;
			dosya<<toplam;
      dosya<<endl;

      sayac++;
    }
		inorder(alt_dugum->sag);
	}
  dosya.close();
}
void Huffman::SilDugum(Dugum* alt_dugum){
	if(alt_dugum == NULL) return;
	SilDugum(alt_dugum->sol);
	SilDugum(alt_dugum->sag);
	delete alt_dugum;
	alt_dugum = NULL;
}
Huffman::~Huffman(){
	// Çöp oluşmaması için ağaç temizleniyor.
  delete bchar;
	SilDugum(root);
}
