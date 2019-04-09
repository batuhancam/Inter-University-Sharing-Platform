//iki nokta arası mesafeyi operatörlerin aşırı yüklenmesini kullanarak hesaplayan program yazınız
#include <iostream>
#include <cmath>
using namespace std;

class uzaklik {
    public:
    int x, y;
    double mesafe;
    uzaklik () {};
    uzaklik (int a,int b){
        x = a;
        y = b;
    }
    double hesapla (){
        mesafe = sqrt ((x*x)+(y*y)); // iki nokta arası mesafenin formülü
        return mesafe;
    }
uzaklik operator- (uzaklik iki){
    uzaklik temp;
    temp.x = x - iki.x;
    temp.y = y - iki.y;
    return (temp);
    }
    
};

int main (){
    uzaklik a (-2,6);
    uzaklik b (7,-8);
    uzaklik c = a - b;
    cout << c.hesapla () ;
    return 0;
}