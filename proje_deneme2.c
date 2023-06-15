#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct kayitlar {
    int no;
    char name[20];
    char departman[20];
    struct kayitlar *next;
};
typedef struct kayitlar node;
node *head,*tail,*temp;

node* yeni_ekleme(node *head);
node* silme(node *head);
void i_yazdirma(node *head);
void yazdirma(node * head);



void main(){
    int sayi,secenek,i;
    printf("Kac tane ogrenci gireceksiniz : ");
    scanf("%d",&sayi);
    for (i=0; i<sayi; i++){
        if (i==0){
            head = (node *)malloc(sizeof(node));
            tail=head;
        }else{
            tail->next = (node *)malloc(sizeof(node)); 
            tail = tail->next;
        }
        printf("%d. ogrencini numarasini girin : ",i+1);
        scanf("%d",&tail->no);
        printf("%d. ogrencini adini girin : ",i+1);
        scanf("%s",tail->name);
        printf("%d. ogrencini bolumunu girin : ",i+1);
        scanf("%s",tail->departman);
        printf("\n");
    }
    tail->next = NULL;
    tail = head;

    while(secenek != 5){
        printf("\n");
        printf("Menu :\n1-Yeni kisi ekleme.\n2-Var olan kisiyi silme.\n3-Istenilen kisiyi yazdirma.\n4-Hepsini yazdirma.\n5-Bİtti.\nSeceneginiz : ");
        scanf("%d",&secenek);
        switch (secenek){
            case 1:
                head = yeni_ekleme(head);
                break;
            case 2:
                head = silme(head);
                break;
            case 3:
                i_yazdirma(head);
                break;
            case 4:
                yazdirma(head);
                break;
        }
        tail = head;
    }
}

node* yeni_ekleme(node *head){
    int stdNo;
    node *yeni = (node*)malloc(sizeof(node));
    printf("En sona eklemek için numaraya 0 yazini.\n");
    printf("Tam olarak kimden once ekleyeceksiniz : ");
    scanf("%d",&stdNo);
    printf("Sira ile yeni eklenecek kisinin numarasini, adini ve bolumunu giriniz :\n");
    scanf("%d%s%s",&yeni->no,yeni->name,yeni->departman);
    if (tail->no == stdNo){
        yeni->next = tail;
        head = yeni;
    }else{
        while (tail->no != stdNo && tail->next != NULL){
            temp = tail;      //yerini buluyor
            tail = tail->next;
        }
        if (tail->no == stdNo){// Ortalara eklemek için
            temp->next = yeni;
            yeni->next = tail;
        }else if(tail->next == NULL){ // Sona eklemek için
            tail->next = yeni;
            yeni->next = NULL;
        }
    }
    return head;
}

node* silme(node *head){
    int stdNo;
    printf("Silmek istediginiz kisinin numarasini giriniz : ");
    scanf("%d",&stdNo);

    if (tail->no == stdNo){
        head = tail->next;
        free(tail);
    }else{
        while (tail->next != NULL && tail->no != stdNo){
            temp = tail;
            tail = tail->next;
        }
        if (tail->no == stdNo){
            temp->next = tail->next;
            free(tail);
        }else if (tail->next == NULL){
            printf("Error : Aradıgınız kisi bulunamadı.");
        }
    }
    return head;
}

void i_yazdirma(node *head){
    int istenen;
    printf("Yazdirmak istediğiniz kisini numarasini girin : ");
    scanf("%d",&istenen);
    while (tail->next != NULL && tail->no != istenen){
        tail = tail->next;
    }
    if(tail->no == istenen){
        printf("No\tIsim\tBolum\n");
        printf("%d\t%s\t%s\n",tail->no,tail->name,tail->departman);
    }else{
        printf("Error : Yazdiginiz numarada bir kisi bulunamadı.");
    }
    tail = head;
}

void yazdirma(node *head){
    printf("No\tIsim\tBolum\n");
    while (tail != NULL){
        printf("%d\t%s\t%s\n",tail->no,tail->name,tail->departman);
        tail = tail->next;
    }
    tail = head;
}
// yeni öğrenci ekeleme;;öğrenci silme;;isteniler kişinin bilgilerini yazdır;;Hepsini yazdır;;Bitti
