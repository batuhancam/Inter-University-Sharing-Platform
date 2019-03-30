#include <iostream>
#include<string>
#include<locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
void sifrele(string &yazi)
{
	int sayac=0;
	cout<<"Girdiðiniz cümle:"<<yazi<<endl;
	for(int i=0;i<yazi.size();i++)
	{
		yazi[i] =='a' || yazi[i]=='A' ? yazi[i]='!',sayac++:0;
		yazi[i]=='e' || yazi[i]=='E' ? yazi[i]='?',sayac++:0;
		yazi[i]=='o' || yazi[i]=='O' || yazi[i]=='ö' || yazi[i]=='ö' || yazi[i]=='u' || yazi[i]=='U' || yazi[i]=='ü' || yazi[i]=='Ü' ? yazi[i]='#' , sayac++:0;
		

	}
	
	
	cout<<"Deðiþtirilen harf sayýsý:"<<sayac<<endl;
	cout<<"Deðiþtirilmiyen harf sayýsý:"<<yazi.size()-sayac<<endl;
	yazi=string(yazi.rbegin(),yazi.rend());
	cout<<yazi;
}
int main(int argc, char** argv) 
{
	setlocale(LC_ALL, "Turkish"); 
	
	string yazi;
	cin>>yazi;
    	
	sifrele(yazi);
}


