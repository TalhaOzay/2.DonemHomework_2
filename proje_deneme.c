#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct fiyat{
    char name[50];
    double maaliyet;
    double iscilik;
    double yuzdelik_kar;
    double satis_fiyat;
};
struct fiyat *point;

void maaliyet_hesap(int sayi,int extra){
    int i=0;
    if (extra == 0){
        for(i; i<sayi ; i++){
            printf("%d. urunun adini giriniz : ",i+1);
            scanf("%s",(point+i)->name);
            printf("%d. urunun maaliyetini giriniz : ",i+1);
            scanf("%lf",&(point+i)->maaliyet);
            printf("%d. urunun isciligini giriniz : ",i+1);
            scanf("%lf",&(point+i)->iscilik);
            printf("%d. urunun satis fiyatini giriniz : ",i+1);
            scanf("%lf",&(point+i)->satis_fiyat);
            (point+i)->yuzdelik_kar = ((point+i)->satis_fiyat - (point+i)->maaliyet - (point+i)->iscilik) / (point+i)->satis_fiyat;
            printf("\n***************************************************\n");
        }
    }else{
        i+=sayi;
        for(i; i<(sayi+extra) ; i++){
            printf("%d. urunun adini giriniz : ",i+1);
            scanf("%s",(point+i)->name);
            printf("%d. urunun maaliyetini giriniz : ",i+1);
            scanf("%lf",&(point+i)->maaliyet);
            printf("%d. urunun isciligini giriniz : ",i+1);
            scanf("%lf",&(point+i)->iscilik);
            printf("%d. urunun satis fiyatini giriniz : ",i+1);
            scanf("%lf",&(point+i)->satis_fiyat);
            (point+i)->yuzdelik_kar = ((point+i)->satis_fiyat - (point+i)->maaliyet - (point+i)->iscilik) / (point+i)->satis_fiyat;
            printf("\n***************************************************\n");
        }
    }
}

void main(){
    int sayi,secenek,extra;
    printf("Kac tane urun gireceksiniz : ");
    scanf("%d",&sayi);
    point = (struct fiyat*)malloc(sayi*sizeof(struct fiyat));
    maaliyet_hesap(sayi,0);
    while(1){
        printf("1.Yeni bilgi ekle.\n2.İstenilen modelin bilgilerini yazdir.\n3.Hepsini yazdir.\n4.Bitir.\n");
        printf("Cevap : ");
        scanf("%d",&secenek);
        if (secenek == 1){
            printf("Kac tane deger ekleyeceksiniz : ");
            scanf("%d",&extra);
            point = realloc(point, (sayi + extra) * sizeof(struct fiyat));
            maaliyet_hesap(sayi,extra);
            sayi+=extra;
        }else if(secenek == 2){
            char model[50];
            printf("Istenilen modeli giriniz : ");
            scanf("%s",model);
            int sonuc=0;
            for (int i=0; i<sayi; i++){
                if (strcmp(((point+i)->name),model) == 0){
                    printf("Urun adi\t Maaliyet\t Iscilik\t Satis fiyati\t Yuzdelik kar\n");
                    printf("%s\t\t  %.3lf\t  %.3lf\t %.3lf\t  %.3lf\n",(point+i)->name,(point+i)->maaliyet,(point+i)->iscilik,(point+i)->satis_fiyat,(point+i)->yuzdelik_kar);
                    sonuc=1;
                }
            }
            if (sonuc == 0){
                printf("Istediginiz deger bulunamadi. Lutfen girdiginiz degeri kontrol ediniz.\n");
            }
        }else if(secenek == 3){
            printf("Urun adi\t Maaliyet\t Iscilik\t Satis fiyati\t Yuzdelik kar\n");
            for (int i = 0; i <sayi; i++){
            printf("%s\t\t  %.3lf\t  %.3lf\t  %.3lf\t  %.3lf\n",(point+i)->name,(point+i)->maaliyet,(point+i)->iscilik,(point+i)->satis_fiyat,(point+i)->yuzdelik_kar);
            printf("\n");
            }
        }else if(secenek == 4){
            break;
        }else{
            printf("Yanlis secenek girdiniz !!!");
        }
    }
}

//yeni değer ekleme // bitirme // yazdır // istenilen değerin bilgilerini aç