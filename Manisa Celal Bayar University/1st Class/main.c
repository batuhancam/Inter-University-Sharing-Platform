#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

FILE *bireysel,*ticari,*hesaplar,*rapor,*dekont;

int i=0;
typedef struct{
    int hesap_id;
    float hesap_bakiye;
    float hesap_limit;
    int hesap_zaman;
}hesap_bilgi;
typedef struct{
    hesap_bilgi hesap;
    int musteri_id;
    char musteri_ad_soyad[50];
    int musteri_durum;
}musteri_bilgi;
typedef struct{
    float banka_para;
    float banka_vergi;
    float banka_giden;
}banka_bilgi;
typedef struct{
    int dekont_sirasi;
    int dekont_id;
    int dekont_id_gelen;
    float dekont_cekilen;
    float dekont_yatirilan;
    float dekont_vergi;
    int dekont_durum;
}dekont_bilgi;
musteri_bilgi musteri,*temp_bmusteri,*temp_tmusteri,para_hesabi,*temp_hesap;
banka_bilgi banka;
dekont_bilgi dekontlar,*temp_dekontlar;
// MUSTERI EKLE
void musteri_ekle(){
    time_t t;
    time(&t);
    struct tm *zaman_bilgisi;
    zaman_bilgisi=localtime(&t);
    system("cls");
    printf("******************** MUSTERI EKLE ********************\n");
    i=0;
    fflush(stdin);
    printf("Adinizi giriniz: ");
    scanf(" %s", musteri.musteri_ad_soyad);
    printf("Musteri durumunu giriniz: 1->Bireysel 2->Ticari");
    scanf(" %d", &musteri.musteri_durum);
        /******************** BIREYSEL ********************/
    if(musteri.musteri_durum==1)
    {
    srand(time(NULL));
    musteri.musteri_id=rand()%4999+1;
    musteri.hesap.hesap_bakiye=0;
    musteri.hesap.hesap_limit=750;
    musteri.hesap.hesap_zaman=zaman_bilgisi->tm_mday;
    fseek(bireysel, (musteri.musteri_id-1)*sizeof(musteri_bilgi), SEEK_SET);
    fwrite(&musteri, sizeof(musteri), 1, bireysel);
    printf("Bankamiza hosgeldiniz.\nMusteri ID'niz: %d\nLutfen Musteri ID'nizi kaybetmeyiniz.\n",musteri.musteri_id);
    printf("Bireysel musteri eklemeniz basariyla tamamlanmistir..!\n");
    }
        /******************** TICARI ********************/
    else if(musteri.musteri_durum==2)
    {
    srand(time(NULL));
    musteri.musteri_id=rand()%5000+5000;
    musteri.hesap.hesap_bakiye=0;
    musteri.hesap.hesap_limit=1500;
    musteri.hesap.hesap_zaman=zaman_bilgisi->tm_mday;
    fseek(ticari, (musteri.musteri_id-5000)*sizeof(musteri_bilgi), SEEK_SET);
    fwrite(&musteri, sizeof(musteri), 1, ticari);
    printf("Bankamiza hosgeldiniz.\nMusteri ID'niz: %d\nLutfen Musteri ID'nizi kaybetmeyiniz.\n",musteri.musteri_id);
    printf("Ticari musteri eklemeniz basariyla tamamlanmistir..!\n");
    }

}
void hesap_ac(){
    int id,bmusteri_sayisi=0,tmusteri_sayisi=0,kontrol=0,bhesap_no,thesap_no;
    i=0;
    system("cls");
    printf("******************** HESAP AC ********************\n");
    printf("Musteri ID'nizi giriniz:");
    scanf("%d",&id);

    rewind(bireysel); rewind(ticari);
    while(!feof(bireysel))
    {
        temp_bmusteri=realloc(temp_bmusteri,sizeof(musteri_bilgi)*(bmusteri_sayisi+1));
        fread(&temp_bmusteri[bmusteri_sayisi],sizeof(musteri_bilgi),1,bireysel);
        if(temp_bmusteri[bmusteri_sayisi].musteri_id!=0)
        {
            bmusteri_sayisi++;
        }
    }
    while(!feof(ticari))
    {
        temp_tmusteri=realloc(temp_tmusteri,sizeof(musteri_bilgi)*(tmusteri_sayisi+1));
        fread(&temp_tmusteri[tmusteri_sayisi],sizeof(musteri_bilgi),1,ticari);
        if(temp_tmusteri[tmusteri_sayisi].musteri_id!=0)
        {
            tmusteri_sayisi++;
        }
    }
    i=0;
    while(i<(bmusteri_sayisi-1))
    {
        if(temp_bmusteri[i].musteri_id==id)
        {
            kontrol=1;
            break;
        }
        i++;
    }
    bhesap_no=i;
    i=0;
    while(i<(tmusteri_sayisi-1))
    {
        if(temp_tmusteri[i].musteri_id==id)
        {
            kontrol=2;
            break;
        }
        i++;
    }
    thesap_no=i;
    if(kontrol==1)
    {
        rewind(bireysel); rewind(ticari);
        srand(time(NULL));
        temp_bmusteri[bhesap_no].hesap.hesap_id=rand()%10000+10000;
        fseek(hesaplar,sizeof(musteri_bilgi)*(temp_bmusteri[bhesap_no].hesap.hesap_id-10000),SEEK_SET);
        fwrite(&temp_bmusteri[bhesap_no],sizeof(musteri),1,hesaplar);
        printf("Bireysel hesabiniz aktiflestirildi.\nHesap numaraniz:%d\n",temp_bmusteri[bhesap_no].hesap.hesap_id);
    }
    else if(kontrol==2)
    {
        rewind(bireysel); rewind(ticari);
        srand(time(NULL));
        temp_tmusteri[thesap_no].hesap.hesap_id=rand()%10000+10000;
        fseek(hesaplar,sizeof(musteri_bilgi)*(temp_tmusteri[thesap_no].hesap.hesap_id-10000),SEEK_SET);
        fwrite(&temp_tmusteri[thesap_no],sizeof(musteri),1,hesaplar);
        printf("Ticari hesabiniz aktiflestirildi.\nHesap numaraniz:%d\n",temp_tmusteri[thesap_no].hesap.hesap_id);
    }
    else{
        printf("Girdiginiz musteri numarasina ait bir musteri bulunamadi lutfen tekrar deneyiniz.\n");
    }
}

void para_yatir()
{
    int id;
    float yatirilan_para;
    system("cls");
    printf("******************** PARA YATIR ********************\n");
    printf("Hesap ID'nizi giriniz:");
    scanf("%d",&id);
    rewind(hesaplar);
    fseek(hesaplar,sizeof(musteri_bilgi)*(id-10000),SEEK_SET);
    fread(&para_hesabi,sizeof(musteri_bilgi),1,hesaplar);
    if(para_hesabi.hesap.hesap_id==id)
    {
        printf("Adiniz-Soyadiniz: %s\nBakiyeniz: %.2f\n",para_hesabi.musteri_ad_soyad,para_hesabi.hesap.hesap_bakiye);
        printf("Yatirmak istediginiz tutari giriniz: ");
        scanf("%f",&yatirilan_para);
        rewind(hesaplar);
        para_hesabi.hesap.hesap_bakiye+=yatirilan_para;
        fseek(hesaplar,sizeof(musteri_bilgi)*(id-10000),SEEK_SET);
        fwrite(&para_hesabi,sizeof(musteri_bilgi),1,hesaplar);
        rewind(hesaplar);rewind(rapor);
        fread(&banka,sizeof(banka),1,rapor);
        rewind(rapor);
        banka.banka_para+=yatirilan_para;
        fwrite(&banka,sizeof(banka),1,rapor);
            fseek(dekont,(-1)*sizeof(dekont_bilgi),SEEK_END);
            fread(&dekontlar,sizeof(dekont_bilgi),1,dekont);
            rewind(dekont);
            if(dekontlar.dekont_sirasi>0)
                dekontlar.dekont_sirasi++;
            else if(dekontlar.dekont_sirasi==0)
                dekontlar.dekont_sirasi=1;
            dekontlar.dekont_id=id;
            dekontlar.dekont_yatirilan=yatirilan_para;
            dekontlar.dekont_durum=1;
            fseek(dekont,sizeof(dekont_bilgi)*(dekontlar.dekont_sirasi-1),SEEK_SET);
            fwrite(&dekontlar,sizeof(dekont_bilgi),1,dekont);
            rewind(dekont);
        printf("Hesabiniza %.2f TL yatirildi.\n",yatirilan_para);
    }
    else{
        printf("Yanlis bir Hesap numarasi girdiniz.\n");
    }
}

void para_cek(){
    int id,ilk_zaman,simdiki_zaman;
    float cekilen_para,limit;

    time_t t2;
    time(&t2);
    struct tm *zaman_bilgisi2;
    zaman_bilgisi2=localtime(&t2);

    system("cls");
    printf("******************** PARA CEK ********************\n");
    printf("Hesap ID'nizi giriniz:");
    scanf("%d",&id);
    rewind(hesaplar);
    fseek(hesaplar,sizeof(musteri_bilgi)*(id-10000),SEEK_SET);
    fread(&para_hesabi,sizeof(musteri_bilgi),1,hesaplar);
    ilk_zaman=para_hesabi.hesap.hesap_zaman;
    simdiki_zaman=zaman_bilgisi2->tm_mday;
        if(simdiki_zaman-ilk_zaman>0)
        {
            if(para_hesabi.musteri_durum==1)
            limit=750;
            else if(para_hesabi.musteri_durum==2)
            limit=1500;
        }
        else
        {
            limit=para_hesabi.hesap.hesap_limit;
        }
    if(para_hesabi.hesap.hesap_id==id)
    {
        printf("Adiniz-Soyadiniz: %s\nBakiyeniz: %.2f TL\nLimit: %.2f TL\n",para_hesabi.musteri_ad_soyad,para_hesabi.hesap.hesap_bakiye,limit);
        printf("Cekmek istediginiz tutari giriniz: ");
        scanf("%f",&cekilen_para);
        if(cekilen_para>limit)
        {
            printf("Gunluk para cekme limitinin ustunde para cekmeyi deniyorsunuz.\nKalan gunluk para cekme limitiniz: %.2f TL\n",limit);
        }
        else
        {
            rewind(hesaplar);
            if(para_hesabi.hesap.hesap_bakiye<cekilen_para)
            {
                printf("Hesabinizda olan paradan daha fazla para cekemezsiniz..!\n");
            }
            else
            {
                para_hesabi.hesap.hesap_bakiye-=cekilen_para;
                limit-=cekilen_para;
                printf("Hesap bakiye:%.2f TL\nHesap Limit:%.2f TL",para_hesabi.hesap.hesap_bakiye,limit);
                para_hesabi.hesap.hesap_zaman=simdiki_zaman;
                para_hesabi.hesap.hesap_limit=limit;
                rewind(hesaplar);
                fseek(hesaplar,sizeof(musteri_bilgi)*(id-10000),SEEK_SET);
                fwrite(&para_hesabi,sizeof(musteri_bilgi),1,hesaplar);
                rewind(hesaplar);rewind(rapor);
                fread(&banka,sizeof(banka),1,rapor);
                rewind(rapor);
                banka.banka_giden+=cekilen_para;
                fwrite(&banka,sizeof(banka),1,rapor);
                    fseek(dekont,(-1)*sizeof(dekont_bilgi),SEEK_END);
                    fread(&dekontlar,sizeof(dekont_bilgi),1,dekont);
                    rewind(dekont);
                    if(dekontlar.dekont_sirasi>0)
                        dekontlar.dekont_sirasi++;
                    else if(dekontlar.dekont_sirasi==0)
                        dekontlar.dekont_sirasi=1;
                    dekontlar.dekont_id=id;
                    dekontlar.dekont_cekilen=cekilen_para;
                    dekontlar.dekont_durum=2;
                    fseek(dekont,sizeof(dekont_bilgi)*(dekontlar.dekont_sirasi-1),SEEK_SET);
                    fwrite(&dekontlar,sizeof(dekont_bilgi),1,dekont);
                    rewind(dekont);
                printf("\nHesabinizdan %.2f TL cekildi.\n",cekilen_para);
            }
        }
    }
    else{
        printf("Yanlis bir Hesap numarasi girdiniz.\n");
    }

}

void havale_yap()
{
    int id1,id2,hesap_sayisi=0,kontrol=0,hesap1_no,hesap2_no;
    float yatirilacak_tutar;
    char kabul;
    system("cls");
    printf("******************** HAVALE YAP ********************\n");
    printf("Kendi Hesabinin ID'sini giriniz:");
    scanf("%d",&id1);
    printf("Havale yapmak istedigin Hesabin ID'sini giriniz:");
    scanf("%d",&id2);
    if(id1!=id2)
    {
        rewind(hesaplar);
        while(!feof(hesaplar))
        {
            temp_hesap=realloc(temp_hesap,sizeof(musteri_bilgi)*(hesap_sayisi+1));
            fread(&temp_hesap[hesap_sayisi],sizeof(musteri_bilgi),1,hesaplar);
            if(temp_hesap[hesap_sayisi].musteri_id!=0)
            {
                hesap_sayisi++;
            }
        }
        i=0;

        while(i<hesap_sayisi)
        {
            if(temp_hesap[i].hesap.hesap_id==id1)
            {
                kontrol++;
                hesap1_no=i;
            }
            if(temp_hesap[i].hesap.hesap_id==id2)
            {
                kontrol++;
                hesap2_no=i;
            }
            i++;
        }
            if(kontrol==2)
            {
                printf("Havale yapmak istediginiz tutari giriniz: ");
                scanf("%f",&yatirilacak_tutar);
                if(temp_hesap[hesap1_no].hesap.hesap_bakiye>=yatirilacak_tutar)
                {
                    if(temp_hesap[hesap1_no].musteri_durum==1)
                    {
                        printf("Yatirmak istediginiz tutar: %.2f TL\n",yatirilacak_tutar);
                        printf("%d Nolu Hesaba gececek tutar: %.2f TL\n",id2,yatirilacak_tutar-(yatirilacak_tutar*0.02));
                        printf("Vergi: %.2f TL\n",yatirilacak_tutar*0.02);
                        fflush(stdin);
                        printf("Para yatirmayi kabul ediyor musunuz? (E veya H): ");
                        scanf("%c",&kabul);
                        toupper(kabul);
                        if(kabul=='E')
                        {
                            temp_hesap[hesap1_no].hesap.hesap_bakiye-=yatirilacak_tutar;
                            temp_hesap[hesap2_no].hesap.hesap_bakiye+=(yatirilacak_tutar-(yatirilacak_tutar*0.02));
                            rewind(hesaplar);
                            fseek(hesaplar,sizeof(musteri_bilgi)*(id1-10000),SEEK_SET);
                            fwrite(&temp_hesap[hesap1_no],sizeof(musteri_bilgi),1,hesaplar);
                            rewind(hesaplar);
                            fseek(hesaplar,sizeof(musteri_bilgi)*(id2-10000),SEEK_SET);
                            fwrite(&temp_hesap[hesap2_no],sizeof(musteri_bilgi),1,hesaplar);

                            rewind(hesaplar);rewind(rapor);
                            fread(&banka,sizeof(banka),1,rapor);
                            rewind(rapor);
                            banka.banka_vergi+=(yatirilacak_tutar*0.02);
                            fwrite(&banka,sizeof(banka),1,rapor);
                            /****************DENEME*****************/
                            fseek(dekont,(-1)*sizeof(dekont_bilgi),SEEK_END);
                            fread(&dekontlar,sizeof(dekont_bilgi),1,dekont);
                            rewind(dekont);
                            if(dekontlar.dekont_sirasi>0)
                                dekontlar.dekont_sirasi++;
                            else if(dekontlar.dekont_sirasi==0)
                                dekontlar.dekont_sirasi=1;
                            dekontlar.dekont_id=id1;
                            dekontlar.dekont_id_gelen=id2;
                            dekontlar.dekont_yatirilan=yatirilacak_tutar;
                            dekontlar.dekont_vergi=yatirilacak_tutar*0.02;
                            dekontlar.dekont_durum=3;
                            fseek(dekont,sizeof(dekont_bilgi)*(dekontlar.dekont_sirasi-1),SEEK_SET);
                            fwrite(&dekontlar,sizeof(dekont_bilgi),1,dekont);
                            rewind(dekont);
                            /****************DENEME*****************/
                            printf("Havale isleminiz basariyle gerceklestirildi..!\n");
                        }
                    }
                    else if(temp_hesap[hesap1_no].musteri_durum==2)
                    {
                        printf("Yatirmak istediginiz tutar: %.2f\n",yatirilacak_tutar);
                        printf("%d Nolu Hesaba gececek tutar: %.2f TL\n",id2,yatirilacak_tutar);
                        printf("Vergi: 0 TL\n");
                        fflush(stdin);
                        printf("Para yatirmayi kabul ediyor musunuz? (E veya H)");
                        scanf("%c",&kabul);
                        toupper(kabul);
                        if(kabul=='E')
                        {
                            temp_hesap[hesap1_no].hesap.hesap_bakiye-=yatirilacak_tutar;
                            temp_hesap[hesap2_no].hesap.hesap_bakiye+=yatirilacak_tutar;
                            rewind(hesaplar);
                            fseek(hesaplar,sizeof(musteri_bilgi)*(id1-10000),SEEK_SET);
                            fwrite(&temp_hesap[hesap1_no],sizeof(musteri_bilgi),1,hesaplar);
                            rewind(hesaplar);
                            fseek(hesaplar,sizeof(musteri_bilgi)*(id2-10000),SEEK_SET);
                            fwrite(&temp_hesap[hesap2_no],sizeof(musteri_bilgi),1,hesaplar);
                            /****************DENEME*****************/
                            fseek(dekont,(-1)*sizeof(dekont_bilgi),SEEK_END);
                            fread(&dekontlar,sizeof(dekont_bilgi),1,dekont);
                            rewind(dekont);
                            if(dekontlar.dekont_sirasi>0)
                                dekontlar.dekont_sirasi++;
                            else if(dekontlar.dekont_sirasi==0)
                                dekontlar.dekont_sirasi=1;
                            dekontlar.dekont_id=id1;
                            dekontlar.dekont_id_gelen=id2;
                            dekontlar.dekont_yatirilan=yatirilacak_tutar;
                            dekontlar.dekont_vergi=0;
                            dekontlar.dekont_durum=3;
                            fseek(dekont,sizeof(dekont_bilgi)*(dekontlar.dekont_sirasi-1),SEEK_SET);
                            fwrite(&dekontlar,sizeof(dekont_bilgi),1,dekont);
                            rewind(dekont);
                            /****************DENEME*****************/
                            printf("Havale isleminiz basariyle gerceklestirildi..!");
                        }
                    }
                }
                else
                printf("Hesabinizda yeterli para yok.\n");
            }

    }
    else{
        printf("Hesap ID'leri ayni olamaz..!\n");
    }
}

void hesaplari_listele()
{
    system("cls");
    printf("******************** HESAPLAR ********************\n");
    int hesap_sayisi=0;
    rewind(hesaplar);
    while(!feof(hesaplar))
    {
        temp_hesap=realloc(temp_hesap,sizeof(musteri_bilgi)*(hesap_sayisi+1));
        fread(&temp_hesap[hesap_sayisi],sizeof(musteri_bilgi),1,hesaplar);
        if(temp_hesap[hesap_sayisi].musteri_id!=0)
        {
            hesap_sayisi++;
        }
    }
    i=0;
    while(i<(hesap_sayisi))
    {
        printf("%d\t%d\t%s\t%.2f\t%.2f\t%d\n",temp_hesap[i].musteri_id,temp_hesap[i].hesap.hesap_id,temp_hesap[i].musteri_ad_soyad,temp_hesap[i].hesap.hesap_bakiye,temp_hesap[i].hesap.hesap_limit,temp_hesap[i].hesap.hesap_zaman);
        i++;
    }
}

void hesap_kapat()
{
    system("cls");
    printf("******************** HESAP KAPAT ********************\n");
    int hesap_sayisi=0,id=0,kontrol=0;
    rewind(hesaplar);
    while(!feof(hesaplar))
    {
        temp_hesap=realloc(temp_hesap,sizeof(musteri_bilgi)*(hesap_sayisi+1));
        fread(&temp_hesap[hesap_sayisi],sizeof(musteri_bilgi),1,hesaplar);
        if(temp_hesap[hesap_sayisi].musteri_id!=0)
        {
            hesap_sayisi++;
        }
    }
    printf("Hesap ID gir: ");
    scanf("%d",&id);
    i=0;
    while(i<(hesap_sayisi))
    {
        if(temp_hesap[i].hesap.hesap_id==id)
        {
            kontrol=1;
            break;
        }
        i++;
    }
    if(kontrol==1)
    {
        if(temp_hesap[i].hesap.hesap_bakiye==0)
        {

            temp_hesap[i].hesap.hesap_bakiye=0;
            temp_hesap[i].hesap.hesap_id=0;
            temp_hesap[i].hesap.hesap_limit=0;
            temp_hesap[i].hesap.hesap_zaman=0;
            strcpy(temp_hesap[i].musteri_ad_soyad," ");
            temp_hesap[i].musteri_durum=0;
            temp_hesap[i].musteri_id=0;
            rewind(hesaplar);
            fseek(hesaplar,sizeof(musteri_bilgi)*(id-10000),SEEK_SET);
            fwrite(&temp_hesap[i],sizeof(musteri_bilgi),1,hesaplar);
            printf("Hesap silindi..!\n");
        }
        else printf("Hesabinizdaki bakiyenin 0 olmasi gerekiyor..\n");
    }
    else printf("Hesap bulunamadi..!\n");
}
void rapor_al()
{
     system("cls");
     rewind(hesaplar);rewind(rapor);
     fread(&banka,sizeof(banka),1,rapor);
     printf("******************** BANKA RAPOR ********************");
     printf("\n\nToplam para\tBanka gelen\tBanka giden\tVergi");
     printf("\n%.2f\t%.2f\t%.2f\t%.2f\t\n",banka.banka_para-banka.banka_giden+banka.banka_vergi,banka.banka_para,banka.banka_giden,banka.banka_vergi);

}

void hesap_ozet()
{
    system("cls");
    printf("******************** HESAP OZET ********************\n");
    int id,dekont_sayisi=0,sira,adet=0;
    fseek(dekont,(-1)*sizeof(dekont_bilgi),SEEK_END);
    fread(&dekontlar,sizeof(dekont_bilgi),1,dekont);
    dekont_sayisi=dekontlar.dekont_sirasi;
    rewind(dekont);
    temp_dekontlar=calloc(dekont_sayisi,sizeof(dekont_bilgi));
    fread(temp_dekontlar,sizeof(dekont_bilgi),dekont_sayisi,dekont);
    printf("Hesap ID giriniz:");
    scanf("%d",&id);
    for(i=0;i<dekont_sayisi;i++)
    {
        if(temp_dekontlar[i].dekont_id==id && temp_dekontlar[i].dekont_durum==1)
        {
            adet++;
            if(adet==1)printf("Hesap ID\tYatirilan Tutar\n");
            printf("  %d\t\t  %.2f TL\n",temp_dekontlar[i].dekont_id,temp_dekontlar[i].dekont_yatirilan);
        }
    }
    adet=0;
    for(i=0;i<dekont_sayisi;i++)
    {
        if(temp_dekontlar[i].dekont_id==id && temp_dekontlar[i].dekont_durum==2)
        {
            adet++;
            if(adet==1)printf("Hesap ID\tCekilen Tutar\n");
            printf("  %d\t\t  %.2f TL\n",temp_dekontlar[i].dekont_id,temp_dekontlar[i].dekont_cekilen);
        }
    }
adet=0;
    for(i=0;i<dekont_sayisi;i++)
    {
        if(temp_dekontlar[i].dekont_id==id && temp_dekontlar[i].dekont_durum==3)
        {
            adet++;
            if(adet==1)printf("Gonderen ID\tGonderilen ID\tYatirilan Tutar\tVergi\n");
            printf("  %d\t\t  %d \t  %.2f TL\t%.2f TL\n",temp_dekontlar[i].dekont_id,temp_dekontlar[i].dekont_id_gelen,temp_dekontlar[i].dekont_yatirilan,temp_dekontlar[i].dekont_vergi);
        }
    }
    adet=0;
    for(i=0;i<dekont_sayisi;i++)
    {
        if(temp_dekontlar[i].dekont_id_gelen==id && temp_dekontlar[i].dekont_durum==3)
        {
            adet++;
            if(adet==1)printf("Gonderen ID\tGonderilen ID\tYatirilan Tutar\tVergi\n");
                printf("  %d\t\t  %d \t  %.2f TL\t%.2f TL\n",temp_dekontlar[i].dekont_id,temp_dekontlar[i].dekont_id_gelen,temp_dekontlar[i].dekont_yatirilan,temp_dekontlar[i].dekont_vergi);
        }
    }
}
int main()
{
    int secim;
    if(bireysel=fopen("bireysel.txt", "r+")==NULL)
    {
        bireysel=fopen("bireysel.txt","w+");
    }
    else
        bireysel=fopen("bireysel.txt", "r+");
    if(ticari=fopen("ticari.txt","r+")==NULL)
    {
        ticari=fopen("ticari.txt","w+");
    }
    else
        ticari=fopen("ticari.txt", "r+");
    if(hesaplar=fopen("hesaplar.txt","r+")==NULL)
    {
        hesaplar=fopen("hesaplar.txt","w+");
    }
    else
        hesaplar=fopen("hesaplar.txt", "r+");
    if(dekont=fopen("dekont.txt","r+")==NULL)
    {
        dekont=fopen("dekont.txt","w+");
    }
    else
        dekont=fopen("dekont.txt","r+");
    if(rapor=fopen("rapor.txt","r+")==NULL)
    {
        rapor=fopen("dekont.txt","w+");
    }
    else
        rapor=fopen("dekont.txt","r+");

    while(1){
    system("cls");
    printf("******************** MENU ********************");
    printf("\n1.Yeni Musteri Ekle");
    printf("\n2.Yeni Hesap Ac");
    printf("\n3.Para Yatir");
    printf("\n4.Para Cek");
    printf("\n5.Havale Yap");
    printf("\n6.Banka Raporunu Incele");
    printf("\n7.Hesap Ozetini Incele");
    printf("\n8.Hesabimi Kapat");
    printf("\n9.Hesaplari Listele");
    printf("\n0.Programi Sonlandir");
    printf("\nKacinci islemi yapmak istiyorsunuz?(Sadece rakam girebilirsiniz..!): ");
    scanf("%d",&secim);
    if(secim==1)
    {
        musteri_ekle();
        printf("Devam etmek icin herhangi bir tusa basiniz..!\n");
        rewind(bireysel);rewind(ticari);rewind(hesaplar);rewind(rapor);
        getch();
    }
    else if(secim==2)
    {
        hesap_ac();
        printf("Devam etmek icin herhangi bir tusa basiniz..!\n");
        rewind(bireysel);rewind(ticari);rewind(hesaplar);rewind(rapor);
        getch();
    }
    else if(secim==3)
    {
        para_yatir();
        printf("Devam etmek icin herhangi bir tusa basiniz..!\n");
        rewind(bireysel);rewind(ticari);rewind(hesaplar);rewind(rapor);
        getch();
    }
    else if(secim==4)
    {
        para_cek();
        printf("Devam etmek icin herhangi bir tusa basiniz..!\n");
        rewind(bireysel);rewind(ticari);rewind(hesaplar);rewind(rapor);
        getch();
    }
    else if(secim==5)
    {
        havale_yap();
        printf("Devam etmek icin herhangi bir tusa basiniz..!\n");
        rewind(bireysel);rewind(ticari);rewind(hesaplar);rewind(rapor);
        getch();
    }
    else if(secim==6)
    {
        rapor_al();
        printf("Devam etmek icin herhangi bir tusa basiniz..!\n");
        rewind(bireysel);rewind(ticari);rewind(hesaplar);rewind(rapor);
        getch();
    }
    else if(secim==7)
    {
        hesap_ozet();
        printf("Devam etmek icin herhangi bir tusa basiniz..!\n");
        rewind(bireysel);rewind(ticari);rewind(hesaplar);rewind(rapor);
        getch();
    }
    else if(secim==8)
    {
        hesap_kapat();
        printf("Devam etmek icin herhangi bir tusa basiniz..!\n");
        rewind(bireysel);rewind(ticari);rewind(hesaplar);rewind(rapor);
        getch();
    }
    else if(secim==9)
    {
        hesaplari_listele();
        printf("Devam etmek icin herhangi bir tusa basiniz..!\n");
        rewind(bireysel);rewind(ticari);rewind(hesaplar);rewind(rapor);
        getch();
    }
    else if(secim==0)
    {
        printf("Program sonlandi. Gorsumek uzere..!");
        exit(1);
    }
}
}
