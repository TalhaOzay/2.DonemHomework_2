#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a struct to be read and written
struct student {
	int no;
	char name[20];
	char dept[20];
};

FILE * file;
int studentN, i;
struct student s;
char name[20];

void createFile()
{
	file = fopen("student.dat", "w");
	if (file == NULL) {
		printf("\nError opened file\n");
		exit(1);
	}
	fclose(file);
}

void addRecords()
{
	file = fopen("student.dat", "a+");
	if (file == NULL) {
		printf("\nError opened file\n");
		exit(1);
	}
	
	printf("\nNumber of students: ");
	scanf("%d", &studentN);
	for(i=0; i < studentN; i++)
	{
        printf("\nEnter the student no: ");
        scanf("%d", &s.no);
        
        printf("Enter the student name: ");
        scanf("%s", s.name);
        
        printf("Enter the student dept: ");
        scanf("%s", s.dept);
		
        fprintf(file,"%d %s %s\n",s.no,s.name,s.dept);
		
	}
	printf("\nStudents are added to a file successfully!\n\n");
	fclose(file);
}
void display()
{
    file = fopen("student.dat","r");
    
    fscanf(file,"%d%s%s",&s.no,s.name,s.dept);
    
	printf("%-10s%-13s%-13s\n","Studentno","Name","Department");
    while(!feof(file))
    {
        printf("%-10d%-13s%-13s\n",s.no,s.name,s.dept);
    	fscanf(file,"%d%s%s",&s.no,s.name,s.dept);
    }
	printf("\n");
    fclose(file);
}

void search(char name[])
{
	int found = 0;
    file = fopen("student.dat","r");
    fscanf(file,"%d%s%s",&s.no,s.name,s.dept);

    while(!feof(file))
    {
    	if(strcmp(s.name, name) == 0){
    		printf("%-10s%-13s%-13s\n","Studentno","Name","Department");
	        printf("%-10d%-13s%-13s\n\n",s.no,s.name,s.dept);
	        found = 1;
	        break;
		}
    	fscanf(file,"%d%s%s",&s.no,s.name,s.dept);
    }
    if(!found)
    	printf("There is no such student\n\n");
    fclose(file);
}

int main()
{	
  int studentNo, i, choice = 0, list=0, m1, m2, f1, f2;
  
  while(choice!=5)
  {
  	printf("1- Create a file\n");
  	printf("2- List all records\n");
  	printf("3- Search record by name\n");
  	printf("4- List all records\n");
  	printf("5- Exit\n");
  	printf("\nEnter Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            createFile();
            break;
        case 2:
            printf("Add a arecord\n: ");
            addRecords();
            break;
        case 3:
            printf("Enter the student name to search: ");
            scanf("%s", name);
            search(name);
            break;
        case 4:
        	display();
            break;
        case 5:
        	//file = fopen("student.dat", "w");
			fclose(file);
        	exit(0);
            break;
    }
    
  }
  free(file);

	return 0;
}