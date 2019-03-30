#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) 
{
	setlocale(LC_ALL,"Turkish");
	int n,temp=1,etemp=1,itemp=1;
	cout<<"Kaç fibo deðeri gösterilsin? : ";cin>>n;
	if(n>=2)
	{

	cout<<etemp<<","<<itemp<<",";
	for(int i=1;i<n-1;i++)
	{
		temp=etemp+itemp;
		cout<<temp<<",";
		etemp=itemp;
		itemp=temp;
		
		
	}
	}
	return 0;
}
