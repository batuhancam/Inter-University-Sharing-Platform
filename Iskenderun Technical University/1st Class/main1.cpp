#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) 
{
	setlocale(LC_ALL,"Turkish");
	//x ler k���k olan de�erler, y ler b�y�k olan de�erler.
	int xilk,yilk,xson,yson,temp,etemp;
	cout<<"�lk k�menin 1. aral�k de�erini giriniz:";cin>>xilk;
	cout<<"�lk k�menin 2. aral�k de�erini giriniz:";cin>>yilk;
	if(xilk>=yilk)
	{
		temp=yilk;
		yilk=xilk;
		xilk=temp;
	}
	cout<<"�kinci k�menin 1. aral�k de�erini giriniz:";cin>>xson;
	cout<<"�kinci k�menin 2. aral�k de�erini giriniz:";cin>>yson;
	if(xson>=yson)
	{
		temp=yson;
		yson=xson;
		xson=temp;
	}
	cout<<"�.K = {";
	if(xilk>=xson)	temp=xilk;else temp=xson;
	if(yilk<=yson) etemp=yilk; else etemp=yson;
	
	if(xson>=xilk && yson<=yilk)
		for(int i=xson;i<=yson;i++)
		cout<<i<<",";
		
	else if(xilk>=xson && yilk<=yson)
		for(int i=xilk;i<=yilk;i++)
		cout<<i<<",";
		
	else if(yilk>=xson && xilk<=yson)
		for(int i=temp;i<=etemp;i++)
			cout<<i<<",";
			
	else if(yson>=xilk && xson<=yilk)
			for(int i=temp;i<=etemp;i++)
			cout<<i<<",";
			
	else cout<<"ORTAK ELAMANI BULUNMAMAKTADIR.";
	cout<<"}";
	
	return 0;
}
