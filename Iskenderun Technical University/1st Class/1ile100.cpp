#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) 
{
	int sayac=1,toplam=0;
	setlocale(LC_ALL,"Turkish");
	while(sayac!=101)
	{
		toplam+=sayac;
		sayac++;
	}

	cout<<toplam/100;
	return 0;
}
