/*EMRE KAAN ALVAR-ELEKTRİKÇİ OTOMASYONU*/
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;
struct bilgi
{
	char ad[80];
	char isim;
	int fiyat;
	float sayi;
};
int main()
{
	setlocale (LC_ALL,"Turkish");
	cout<<"* * * * *ELEKTRİKÇİ DÜKKANI* * * * *"<<endl;
	time_t rawtime;
	time(&rawtime);
	cout <<"tarih:"<<ctime (&rawtime);
	
	char secim;
	bilgi urun;
{

   ofstream dosya("urun.dat" , ios::binary);
   do
   {
   	cout<<" \n Kaydetmek istediğiniz ürünün adı:";
   	cin>>urun.ad;
   	cout<<"\n Kaydetmek  istediğiniz ürünün fiyatı:";
   	cin>>urun.fiyat; 
	cout<< "\n Kaydetmek  istediğiniz ürünün sayısı:";
	cin>>urun.sayi;
	
   dosya.write(reinterpret_cast<char*>(&urun),sizeof(urun))	;
   cout<<"\n Başka Kayıt Yapmak İstiyor Musunuz?  [E/H] "  ;secim=getche();  
   }
   
   while (secim=='e' || secim=='E');
   dosya.close();
}
   ifstream dosya("urun.dat",ios::binary) ;
   dosya.seekg(0,ios::end);
   int kayitsayisi= dosya.tellg()/sizeof(urun);
   cout<<"\n \n Dosyadaki Kayıt Sayısı:"<<kayitsayisi;
   dosya.close();
  {
 
   ifstream dosya;
   dosya.open("urun.dat" , ios::binary);
   
   cout<<"\n Dosyada"<<kayitsayisi<<"Tane Kayıtlı Ürün Bulunmaktadır.\n";
   if(kayitsayisi>0)
   {
   	for(int j=0;j<kayitsayisi;j++)
   	{
   		cout<<endl<<j+1<<".Ürün"<<endl;
   		dosya.seekg(j*sizeof(urun));
   		dosya.read(reinterpret_cast<char*>(&urun),sizeof(urun))	;
   		cout<<endl;
   		cout<<"Ürünün adı:"<<urun.ad<<endl;
   		cout<<"Ürünün fiyatı:"<<urun.fiyat<<endl;
   		cout<<"Ürünün sayısı:"<<urun.sayi<<endl;
	}
   }
else
{
	cout<<"\n Dosyada Hiç Kayıt Yok"<<endl;
dosya.close();
}
{
	char isim[80];
	bool var;
	ifstream dosya;
	dosya.open("urun.dat",ios::binary);
	cout << "Kaydını bulmak istediğiniz Ürünün adını giriniz:";
	cin>>isim;
	for(int j=0;j<kayitsayisi;j++)
	{
		dosya.seekg(j*sizeof(urun));
		dosya.read(reinterpret_cast<char*>(&urun),sizeof(urun));
		if(strcmp(urun.ad,isim)==0)
		{
			cout<<endl<<j+1<<"Kayıtta bulundu"<<endl;
			var=true;
			cout<<endl;
			cout<<"Ürünün adı:"<<urun.ad<<endl;
			cout<<"Ürünün fiyatı:"<<urun.fiyat<<endl;
			cout<<"Ürünün sayısı:"<<urun.sayi<<endl;
		}
	}
	if (0)
	cout<<"kayıt bulunamadı."<<endl;
	dosya.close();
}
{
	char isim[80];
	char secim=' ';
	bool var=false;
	ifstream dosya;
	dosya.open("urun.dat",ios::binary);
	cout<< "Kaydını Düzelteceğiniz Ürünün Adını Girin:";
	cin>>isim;
	for(int j=0;j<kayitsayisi;j++)
	{
		dosya.seekg(j*sizeof(urun));
		dosya.read(reinterpret_cast<char*>(&urun),sizeof(urun));
		if(strcmp(urun.ad,isim)==0)
		{
			var=true;
			cout<<endl;
			cout<<"Ürünün adı"<<urun.ad<<endl;
   		    cout<<"Ürünün fiyatı:"<<urun.fiyat<<endl;
   		    cout<<"Ürünün sayısı:"<<urun.sayi<<endl;
   		    cout<<"Düzeltmek istediğiniz kayıt bu mu?:";
   		    secim=getche();
   		    if(secim=='H' || secim=='h')
   		    {
   		       bilgi y_urun;
				  ofstream y_dosya;
				  y_dosya.open("YEDEK.DAT",ios::app|ios::binary);
				  
				  strcpy(y_urun.ad,urun.ad);
				  y_urun.fiyat=urun.fiyat;
				  y_urun.sayi=urun.sayi;
				  
				  y_dosya.write(reinterpret_cast<char*>(&y_urun),sizeof(y_urun));
				  y_dosya.close();
				  
			}
			else if(secim=='E'|| secim=='e')
			{
				ofstream dosya;
				dosya.open("YEDEK.DAT",ios::app|ios::binary);
				cout<<endl;
				cout<<"Ürünün adı:";
				cin>>urun.ad;
				cout<<"Ürünün fiyatı:";
				cin>>urun.fiyat;
				cout<<endl;
				cout<<"Ürünün adeti:";
				cin>>urun.sayi;
				cout<<endl;
				dosya.write(reinterpret_cast<char*>(&urun),sizeof(urun));
				dosya.close();			}
		}
		else 
		{
			bilgi y_urun;
			ofstream y_dosya;
			y_dosya.open("YEDEK.DAT",ios::app|ios::binary);
			strcpy(y_urun.ad,urun.ad)	;
			y_urun.fiyat=urun.fiyat;
			y_dosya.write(reinterpret_cast<char*>(&y_urun),sizeof(y_urun));
			y_dosya.close();
		}
	}
}
dosya.close();

if(1)//if var
{
	remove("urun.dat");
	rename("YEDEK.DAT","urun.dat");
	cout<<"\n Kayıt düzeltildi."<<endl;
	
}
else 
{
	remove("YEDEK.DAT");
	cout<<"\n Kayıt Bulunamadı."<<endl;
}
}
getche();
return 0;
}
