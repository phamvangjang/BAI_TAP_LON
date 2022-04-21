//Ho Va Ten: Pham Van Giang
//MSSV: 6251071025
//CNTT K62
#include<stdio.h>
int main(){
	int i,n;
	long S;
	S = 0;
	i = 1;
	printf("%3cNhap so n = ");
	scanf("%d",&n);
	while(i <= n){
		S = S + i;
		i++;
	}
	printf("Tong cua 1 + 2 +...+ %d = %d", n, S);
	return 0;
}

