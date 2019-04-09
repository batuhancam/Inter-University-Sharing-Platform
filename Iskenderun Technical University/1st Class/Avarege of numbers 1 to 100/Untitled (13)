//operatörlerin aşırı yüklenmesi
#include <iostream>
using namespace std;
class cVector {
    public:
    int x, y;
    cVector () {};
    cVector (int, int);
    cVector operator + (cVector);    
    /* cVector nesnesi döndüren,cVektor parametreli fonksiyon ile 
    + operatörü aşırı yükleniyor */

};
cVector::cVector (int a, int b){
    x=a;
    y=b;
}

//ilki hangi türden döndereceğini söylüyor.nesne döndürüyor
cVector cVector::operator+ (cVector param){
    cVector temp;
    temp.x = x + param.x;
    temp.y = y + param.y;
    return (temp);
}
int main (){
    cVector a (3,1);
    cVector b (1,2);
    cVector c;
    c = a + b;
    cout << c.x << "," << c.y;
    return 0;

    //c = a.operator+ (b); şeklinde de yazılabilir
    // + - * / ++ -- % && || != < > >= >= aşırı yüklenebilir.
}