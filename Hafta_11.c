#include <stdio.h>

int number;
char name[20];
char surname[20];

FILE * test_file;
void createfile(void);
void listAll(void);
void finder(void);

void main(){
    int choice;
    while (choice != 4){
        printf("1- Create a file\n");
        printf("2- List all records\n");
        printf("3- Search record by number\n");
        printf("4- Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                createfile();
                break;
            case 2:
                listAll();
                break;
            case 3:
                finder();
                break;
        }
    }
}

void createfile(void){
    if ((test_file = fopen("ogrencibil.txt","w")) == NULL){
        printf("Error: Cannot create.");
    }else{
        printf("Enter EOF for stop input.\n");
        printf("Enter number , name , surname : ");
        printf("\n-");
        scanf("%d%s%s",&number,name,surname);        
        while(!feof(stdin)){
            fprintf(test_file,"%d%s%s\n",number,name,surname);
            printf("\n-");
            scanf("%d%s%s",&number,name,surname);
        }
        fclose(test_file);
    }
}

void listAll(void){
    if ((test_file = fopen("ogrencibil.txt","r")) == NULL){
        printf("Error: Cannot open.");
    }else{
        printf("%-10s%-14s%-20s\n","No","Name","Surname");
        while(!feof(test_file)){
            fscanf(test_file,"%d%s%s",&number,name,surname);
            printf("%-10d%-14s%-20s\n",number,name,surname);
        }
        fclose(test_file);
    }
}

void finder(void){
    int find;
    if ((test_file = fopen("ogrencibil.txt","r")) == NULL){
        printf("Error: Cannot open.");
    }else{
        printf("Enter number for search : ");
        scanf("%d",&find);
        while (!feof(test_file)){
            fscanf(test_file,"%d%s%s",&number,name,surname);
            if (find == number){
                printf("%-10s%-14s%-20s\n","No","Name","Surname");
                printf("%-10d%-14s%-20s\n",number,name,surname);
                return;
            }
        }
        printf("Can't found.");
    }
}

