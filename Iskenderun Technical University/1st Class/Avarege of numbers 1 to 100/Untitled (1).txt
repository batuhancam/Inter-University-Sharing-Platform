//++ operatörünün aşırı yüklenmesi örneği
#include <iostream>
using namespace std;
class testSinif {
    public:
    int x,y;
    testSinif () {x=0;y=0;}
    testSinif (int ,int);
    testSinif operator++ ();
    void oku (int &d1,int &d2){
        d1 = x;
        d2 = y;
    }
};
testSinif::testSinif (int a,int b){
    x = a;
    y = b;
}
//++ operatörü aşırı yükleniyor
testSinif testSinif::operator++ (){
    x++;
    y++;
    return *this; // nesne yerine this kullandık
}
int main (){
    testSinif ts (5,7);
    int k1,k2;
    ++ts;
    ts.oku (k1,k2);
    cout << "(" << k1 << "," << k2 << ")";
    cout << "\n";
    return 0;
}