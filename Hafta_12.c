#include <stdio.h>

struct bilgi{
    int TC;
    char name[20];
    char surname[20];
    int age;
    char disease[20];
};

FILE *Hasta;

void createfile(void);
void add(void);
void delete(void);
void edit(void);
void finder(void);
void listAll(void);


void main(){
    int choice;
    while (choice != 7){
        printf("1- Create a file\n");
        printf("2- Add new record\n");
        printf("3- Delete record\n");
        printf("4- Edit record\n");
        printf("5- Search record by TC\n");
        printf("6- List all records\n");       
        printf("7- Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                createfile();
                break;
            case 2:
                add();
                break;
            case 3:
                delete();
                break;
            case 4:
                edit();
                break;
            case 5:
                finder();
                break;
            case 6:
                listAll();
                break;
        }
    }
}


void createfile(void){
    int i;
    struct bilgi boshasta = {0,"","",0,""};
    if((Hasta = fopen("HastaBilgi.txt","w")) == NULL){
        printf("Error: Cannot create.");
    }else{
        for (i=0 ; i<100; i++){
            fwrite(&boshasta,sizeof(struct bilgi),1,Hasta);
        }
        fclose(Hasta);
        printf("File created.\n\n");
    }
}

void add(void){
    struct bilgi hastabilgi = {0,"","",0,""};
    if ((Hasta = fopen("HastaBilgi.txt", "r+")) == NULL){
        printf("Error: Could not open.");
    }else{
        printf("Enter 0 for stop.\n");
        printf("Enter patient number[1-100] : ");
        scanf("%d",&hastabilgi.TC);
        while (hastabilgi.TC != 0){
            printf("Enter patient name, surname, age and problem : ");
            scanf("%s%s%d%s",hastabilgi.name,hastabilgi.surname,&hastabilgi.age,hastabilgi.disease);
            fseek(Hasta,(hastabilgi.TC-1)*sizeof(struct bilgi),SEEK_SET);
            fwrite(&hastabilgi,sizeof(struct bilgi),1,Hasta);
            printf("\nEnter patient number[1-100] : ");
            scanf("%d",&hastabilgi.TC);
        }
        fclose(Hasta);
        printf("Adding operation completed successfully.\n\n");
    }
}

void delete(void){
    int findNum;
    struct bilgi hastabilgi,boshasta = {0,"","",0,""};
    if ((Hasta = fopen("hastabilgi.txt","r+")) == NULL){
        printf("Error: Could not open.");
    }else{
        printf("Enter patient number[1-100] : ");
        scanf("%d",&findNum);
        fseek(Hasta,(findNum-1)*sizeof(struct bilgi),SEEK_SET);
        fread(&hastabilgi,sizeof(struct bilgi),1,Hasta);
        if(hastabilgi.TC == 0){
            printf("Error: Patient not exist.");
        }else{
            fseek(Hasta,(findNum-1)*sizeof(struct bilgi),SEEK_SET);
            fwrite(&boshasta,sizeof(struct bilgi),1,Hasta);
        }
        fclose(Hasta);
        printf("Delete operation completed successfully.\n\n");
    }
}

void edit(void){
    int findNum;
    struct bilgi hastabilgi,yenihasta = {0,"","",0,""};
    if ((Hasta = fopen("hastabilgi.txt","r+")) == NULL){
        printf("Error: Cannot open.");
    }else{
        printf("Enter patient number[1-100] : ");
        scanf("%d",&findNum);
        fseek(Hasta,(findNum-1)*sizeof(struct bilgi),SEEK_SET);
        fread(&hastabilgi,sizeof(struct bilgi),1,Hasta);
        if(hastabilgi.TC == 0){
            printf("Error: Patient not exist.");
        }else{
            yenihasta.TC = hastabilgi.TC;
            printf("Enter new information (name, surname, age, disease) : ");
            scanf("%s%s%d%s",yenihasta.name,yenihasta.surname,&yenihasta.age,yenihasta.disease);
            fseek(Hasta,(findNum-1)*sizeof(struct bilgi),SEEK_SET);
            fwrite(&yenihasta,sizeof(struct bilgi),1,Hasta);
        }
        fclose(Hasta);
        printf("Edit operation completed successfully.\n\n");
    }
}

void finder(void){
    int findNum;
    struct bilgi hastabilgi = {0,"","",0,""};
    if ((Hasta = fopen("hastabilgi.txt","r+")) == NULL){
        printf("Error: Cannot open.");
    }else{
        printf("Enter patient number[1-100] : ");
        scanf("%d",&findNum);
        fseek(Hasta,(findNum-1)*sizeof(struct bilgi),SEEK_SET);
        fread(&hastabilgi,sizeof(struct bilgi),1,Hasta);
        if (hastabilgi.TC == 0){
            printf("Error: Patient not exist.");
        }else{
            printf("%-6s%-12s%-12s%-12s%-12s\n","Number","Name","Surname","Age","Disease");
            printf("%-6d%-12s%-12s%-12d%-12s\n",hastabilgi.TC,hastabilgi.name,hastabilgi.surname,hastabilgi.age,hastabilgi.disease);
        }
        fclose(Hasta);
        printf("Searching operaton completed successfully.\n\n");
    }
}

void listAll(void){
    struct bilgi hastabilgi = {0,"","",0,""};
    if ((Hasta = fopen("hastabilgi.txt","r+")) == NULL){
        printf("Error: Cannot open.\n");
    }else{
        printf("%-6s%-12s%-12s%-12s%-12s\n","Number","Name","Surname","Age","Disease");
        while (!feof(Hasta)){
            fread(&hastabilgi,sizeof(struct bilgi),1,Hasta);
            if (hastabilgi.TC != 0){
                printf("%-6d%-12s%-12s%-12d%-12s\n",hastabilgi.TC,hastabilgi.name,hastabilgi.surname,hastabilgi.age,hastabilgi.disease);
            }
        }
        fclose(Hasta);
        printf("Listing operation complete successfully.\n\n");
    }
}