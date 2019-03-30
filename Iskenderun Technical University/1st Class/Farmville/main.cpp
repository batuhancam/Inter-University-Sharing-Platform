#include <iostream>
#include<fstream>
#include<stdlib.h>
#include <unistd.h>
#include<string>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class userkontrol
{
	
	public:
	string secim;
	string kadi;
	string sifre;
	int kredi;
	bool ukaydet()
	{
		try
		{
		ofstream hesapfile("hesaplar.txt", ios::app);
		hesapfile<<kadi<<endl;
		hesapfile<<sifre<<endl;
		hesapfile<<"500"<<endl;
		return 1;
		}
		catch(int e)
		{
				return 0;
		}
		
	
	}
	bool ugiris()
	{
		   ifstream reader("hesaplar.txt");
		  	string hesaplar[satirbul(reader)];
			string line;
  		    int sayac=0;
		   
		    if(reader.is_open())
		   {
		   	while(getline(reader,line))
		   	{
				hesaplar[sayac]=line;
				sayac++;
			}
			
			for(int i=0;i<=sayac-1;i++)
			{
				if(hesaplar[i]==kadi && hesaplar[i+1]==sifre)
				{
					kredi=atoi(hesaplar[i+2].c_str());
					return 1;
				}
				
				
			
			}
			return 0;
			
		   }
		
  	}
  	void update()
  	{
  		
  		string line;
  		int satir=satirbul("hayvanlar.txt");
  		string animals[satir];
  		ifstream reader("hayvanlar.txt");
  		if(reader.is_open())
  		{
  			while(getline(reader,line))
  			{
  				if(line==kadi+sifre)
  				for(int i=0;i<=satir;i++)
  				{
  					cout<<line;
  					animals[i]=line;
				}
			}
			for(int i=0;i<=satir;i++)
			cout<<animals[i];
		}
		
	}
	
  	int satirbul(ifstream txt)
  	{
  		
  			string line;
  		    int sayac=0;
		    -
		    if(txt.is_open())
		   {
		   	 while (getline(reader,line))
				{
					sayac++;
				} 
			}
			reader.close();
			return sayac;
	}

  


};



class hayvanatbahcesi
{


	private:
	int at=350;
	string secim;
	string irk;
	int yas;
	public:
	userkontrol quest;
	hayvanatbahcesi() {
	}
	
	
	void menu(userkontrol user)
	{ 
	quest=user;
		system("cls");
		cout<<"Çiftlik menusüne hoþgeldiniz.."<<endl;
		cout<<"1-)Hayvan besleme\n";
		cout<<"2-)Hayvan satýn al.\n";
		cout<<"3-)Hayvan çiftleþtir.\n";
		cout<<"4-)Hayvanlarýný açlýk durumunu kontrol et.\n";
		cout<<"Secim:";cin>>secim;
		if(secim=="2")
		hayvan_buy();
	}
	void hayvan_besle()
	{
		
	}
	int hayvan_buy()
	{
		char onay;
		system("cls");
		string buying;
		cout<<"1-)AT 250 KREDI"<<endl;
		cout<<"2-)Vazgeç"<<endl;
		
		do
		{
		cout<<"Seç:";
		cin>>buying;
		if(buying=="2") menu(quest);
		}while(!(buying=="1" || buying=="2" ));
		cout<<"Satýn alýmdan sonraki bakiye:"<<quest.kredi-at<<" onay için 'y' çýkmak için 'n'";	
		cin>>onay;
		if(onay=='y')
		{
			cout<<"sa";
			quest.kredi=quest.kredi-at;
			quest.update();
		}
		else menu(quest);
	}
	
};


int main(int argc, char** argv) 
{
	menu:
	string secim;

	string kadi;
	string sifre;
	
	userkontrol user;
	setlocale(LC_ALL, "Turkish"); 

	system("cls");
	cout<<"1-)Giriþ\n2-)Yeni Üyelik\n3-)Çýkýþ\nSeçim:";
	cin>>secim;
	
		
	
	if(secim=="1") 
	{
		do
		{
		system("cls");
		cout<<"Menüye dönmek için kullanici adina '**' giriþi yapýnýz..\n";
		cout<<"Kullanici adiniz:";cin>>kadi;cout<<endl;
		if(kadi=="**") goto menu;
		cout<<"Þifreniz:";cin>>sifre;cout<<endl;
		user.kadi=kadi;
		user.sifre=sifre;
		}
		while(!user.ugiris());
		oyun:
		
		if(user.ugiris())
		{
			system("cls");	
			cout<<kadi<<" Hoþgeldiniz."<<user.kredi<<" krediniz bulunmaktadir."<<endl;
			hayvanatbahcesi ubahce;
			ubahce.menu(user);
		}
		else cout<<"Giriþ baþarýsýz oldu.";
		

	}
	
	else if(secim=="2")
	{
		
		system("cls");
		cout<<"Kullanici adiniz:";cin>>kadi;cout<<endl;
		cout<<"Þifreniz:";cin>>sifre;cout<<endl;
		
		user.kadi=kadi;
		user.sifre=sifre;
		if(user.ukaydet())
		{
			system("cls");
			cout<<"Kayýt Baþarýlý..\nOyuna geçiyorsunuz..";
			sleep(5);
			goto oyun;
		}
	}		
	else if(secim=="3"){

		system("cls");
		cout<<"Çýkýþ yapýlýyor..";
		sleep(3);
		exit(EXIT_FAILURE);
			}
	else 
		{
		
			system("cls");
			cout<<"Yanlýþ seçim yaptýnýz menüye yönlendiriliyorsunuz..";
		
			sleep(2);
			goto menu;
		}
	}
