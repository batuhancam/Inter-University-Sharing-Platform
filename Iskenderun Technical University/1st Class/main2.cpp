#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) 
{
	
	setlocale(LC_ALL,"Turkish");
	int n;
	cout<<"Aþama sayisini giriniz:";cin>>n;
	system("cls");
	cout<<"5 aþamalý yarim pramit."<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++) cout<<"*";
		cout<<endl;
	}
	return 0;
}
