//Ho Va Ten: Pham Van Giang
//MSSV: 6251071025
//CNTT K62
#include<stdio.h>
int main(){
	int i,n;
	float S;
	S = 0;
	i = 1;
	printf("Vui long nhap so n = ");
	scanf("%d",&n);
	if(n <= 0){
		printf("So ban nhap khong dung voi yeu cau\nVui long nhap lai!");
	} else{
		while (i <= n){
		S = S + 1.0 / i;
		i++;		
	}
	printf("Tong cua day 1 + 1/2 +...+ 1/%d = %0.3f",n,S);
	printf("\nCAM ON BAN DA HOC CODE CUNG CHUNG TOI!\nGood bye See you again!");
	}
	
	return 0;
}

