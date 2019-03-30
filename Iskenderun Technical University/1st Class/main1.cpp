#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) 
{
	setlocale(LC_ALL,"Turkish");
	//x ler küçük olan deðerler, y ler büyük olan deðerler.
	int xilk,yilk,xson,yson,temp,etemp;
	cout<<"Ýlk kümenin 1. aralýk deðerini giriniz:";cin>>xilk;
	cout<<"Ýlk kümenin 2. aralýk deðerini giriniz:";cin>>yilk;
	if(xilk>=yilk)
	{
		temp=yilk;
		yilk=xilk;
		xilk=temp;
	}
	cout<<"Ýkinci kümenin 1. aralýk deðerini giriniz:";cin>>xson;
	cout<<"Ýkinci kümenin 2. aralýk deðerini giriniz:";cin>>yson;
	if(xson>=yson)
	{
		temp=yson;
		yson=xson;
		xson=temp;
	}
	cout<<"Ç.K = {";
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
