#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) 
{
	int n,eb=0,adet=0;
	cin>>n;
	while(n<100 && n>1)
	{
		if(n>eb)
		{
			adet=0;
			eb=n;
		}
		if(n==eb)
		{
			adet++;
		}
		cin>>n;
		
	}
	cout<<adet;
	return 0;
}
