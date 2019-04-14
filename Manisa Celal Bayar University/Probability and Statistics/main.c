#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Karekök hesabi yapabilmek icin
void aritmetikOrtalama(float x[],int a)
{
    float ortalama=0;
    int i=0;
    for(i=0;i<a;i++)
    {
        ortalama+=x[i];
    }
    ortalama=ortalama/a;
   printf("Aritmetik Ortalama: %.2f",ortalama);

}
void tepeDegeri(float x[],int a)
{
    int i,j;
    float frekans=0,mod;
    for (i = 0; i < a; ++i)
    {
            int sayi = 0;
        for (j = 0; j < a; ++j)
                if (x[j] == x[i])
                    ++sayi;
        if (sayi > frekans)
        {
            frekans = sayi;
            mod = x[i];
        }
    }
 printf("\nMod degeri: %.2f - Frekansi: %.0f",mod,frekans);
}
void ortanca(float x[], int a)
{
    int i,j,sira[2];
    float temp,medyan;
    // Siralama Algoritmasi
     for(int i=0; i<a-1;i++){
        for(int j=i+1; j<a; j++){
            if(x[i] > x[j]){
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }

    if(a%2==1)
    {
        sira[0]=(a+1)/2; // Tek elemanli dizinin medyan degerinin sirasinin hesaplanmasi
        printf("\nMedyan: %.2f", x[sira[0]-1]); // Dizinin elemanlari 0'dan basladigi icin sirayi 1 geri aliyoruz.
    }
    if(a%2==0)
    {
        sira[0]=a/2; // Cift elemanli dizinin medyan degerinin sirasinin hesaplanmasi
        sira[1]=sira[0]+1; // Cift elemanli dizinin medyan degerinin sirasinin hesaplanmasi
        printf("\nMedyan: %.2f - %.2f", x[sira[0]-1],x[sira[1]-1]); // Dizinin elemanlari 0'dan basladigi icin siralari 1 geri aliyoruz.
    }

}
void standartSapma(float x[],int a)
{
    int i;
    float ortalama=0,fark[a],toplam=0,karekok;
    for(i=0;i<a;i++)
    {
        ortalama+=x[i];
    }
    ortalama=ortalama/a; // Sayilarin aritmetik ortalamasini bulunur

    for(i=0;i<a;i++){
        fark[i]=x[i]-ortalama; // Her bir sayinin aritmetik ortalamadan farki bulunur
        fark[i]*=fark[i]; // Bulunan farklarin kareleri hesaplanir
        toplam+=fark[i]; // Farklarin kareleri toplanir
    }
    toplam/=(a-1); // Elde edilen toplam, serinin eleman sayisinin 1 eksigine bölünür
    karekok=sqrt(toplam); // Bulunan sayinin karesi alinir
    printf("\nStandart Sapma: %.2f",karekok);
}
int main()
{/*
     Dizi sayisi girilicek
     Elemanlari disaridan alicak
     Aritmetik Ortalama
     Mod(Tepe Degeri)
     Ortanca(Medyan)
     Standart Sapma -> Hesaplanacak */

        int diziEleman,i;
        printf("Dizinin eleman sayisini giriniz: ");
        scanf("%d",&diziEleman);
        float dizi[diziEleman];
        for(i=0;i<diziEleman;i++)
        {
            printf("Dizinin %d. Elemanini giriniz: ",(i+1));
            scanf("%f",&dizi[i]);
        }
        system("cls");
        printf("Dizi: ");
        for(i=0;i<diziEleman;i++)
        {
            if(i==(diziEleman-1))
            printf("%.2f\n", dizi[i]);
            else
            printf("%.2f, ",dizi[i]);
        }
        aritmetikOrtalama(dizi,diziEleman);
        tepeDegeri(dizi,diziEleman);
        ortanca(dizi,diziEleman);
        standartSapma(dizi,diziEleman);
    return 0;
}
