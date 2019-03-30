#include <iostream>
void taban(int iki);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) 
	{
		setlocale(LC_ALL,"Turkish");
		int binary,temp;
		cout<<"Lütfen sayiyi giriniz:";
		cin>>binary;
		taban(binary);
	
	}
	void taban(int iki)
	{
		int temp=iki;
		int uzunluk;
		bool var=0;
		string ikilik,tip,nikilik;
		if(iki<0) 	{ iki=iki*-1; tip="Negatif ";}
		else tip="Pozitif ";
		if(iki%2==0) tip=tip+"ve çifttir.";
		else tip=tip+"ve tektir.";
		while(iki>=2)
			{
				if(iki%2==0) ikilik="0"+ikilik;
				else ikilik="1"+ikilik;
				iki=iki/2;
			}
		if(iki==1) ikilik="1"+ikilik;
		else ikilik="0"+ikilik;
		
		if(temp<=-2)
		{	
		uzunluk=ikilik.length()-1;
		while(uzunluk>=0)
		{
			if(var==1)
			{
				if(ikilik.substr(uzunluk,1)=="1") { nikilik="0"+nikilik;	}
				else nikilik="1"+nikilik;
			}
			else
			{
				if(ikilik.substr(uzunluk,1)=="1") { nikilik="1"+nikilik; var=1;}
				else { nikilik="0"+nikilik;	}
			}
			uzunluk--;
			
		}
		ikilik=nikilik;
		}
		
		cout<<tip<<endl<<"Girilen sayinin binary karşılığı:"<<ikilik;
	}
