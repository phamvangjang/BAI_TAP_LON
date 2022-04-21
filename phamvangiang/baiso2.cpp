//Ho Va Ten: Pham Van Giang
//MSSV: 6251071025
//CNTT K62
#include<stdio.h>
int main(){
	int n,i;
	long S;
	i = 1;
	S = 0;
	printf("Vui long nhap so n = ");
	scanf("%d",&n);
	while(i <= n){
		S = S + i * i;
		i++;
	}
	printf("Tong cua day 1^2 + 2^2 +...+ %d^2 = %d", n,S);
	printf("\nCAM ON BAN DA HOC CODE CUNG CHUNG TOI!\nGood bye See you again!");
	return 0;
}

