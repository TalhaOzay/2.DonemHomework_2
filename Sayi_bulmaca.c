#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    printf("Welcome to the finding number game!\n");
    srand(time(NULL));
    int r=rand()%20,sum=0,num=-1;
    printf("Please enter a number between 0 and 20 : ");
    for(r;r!=num;sum++){
        scanf("%d",&num);
        if(r<num){
            printf("Please enter smaller number : ");
        }else if(num<r){
            printf("Please enter larger number : ");
        }
    }
    printf("Congratulations!!!\nYou have successfully found the number in your %d. try.\n",sum);
    printf("Correct number was %d.\n",r);
}