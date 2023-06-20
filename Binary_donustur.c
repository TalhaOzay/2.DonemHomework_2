#include <stdio.h>
#include <math.h>

void binary(int num);
int temp[100];
int *f = temp;
int main(){
	int number;
	printf("Enter number : ");
	scanf("%d",&number);
	binary(number);

}

void binary(int num){
	int sum,one=0;
	static int i = 1;
	sum = num%2;
	num = num/2;
	f[100-i] =sum;
	if (num > 1){
		i++;
		return binary(num);
	}else{
		i++;
		f[100-i]=1;
		for (int i=0; i<100;i++){
			if (f[i] == 1){
				while (i < 100){
					printf("%d ",f[i]);
					if(f[i] == 1){
						one++;
					}
					i++;
				}
				printf("\n1 olan bitlerin sayısı : %d",one);
			}
			
		}
	}
}