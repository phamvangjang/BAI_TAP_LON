//Ho va ten: Pham Van Giang
//MSSV: 6251071025
//Lop: CNTT K62
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
typedef struct SinhVien{
	char ThiSinh[50];
	float Diem;
	char MST[10];
}SV;
void NhapSV(SV &sv)
{
	printf("\n\tNHap ho ten: ");
	fflush(stdin);
	gets(sv.ThiSinh);
	do
	{
	printf("\n\tNhap diem: ");
	scanf("%f",&sv.Diem);
	if(sv.Diem < 0 || sv.Diem > 10){
		printf("\n\tNhap so diem khong hop le!");
	}
	}while(sv.Diem < 0 || sv.Diem > 10);
	printf("\n\tNhap ma truong cua sinh vien: ");
	fflush(stdin);
	gets(sv.MST);
}
void Nhap_n_SinhVien(SV a[], int *n)
{
	do
	{
	printf("\n\tNhap so luong sinh vien tham gia thi UTC2-Techwar: ");
	scanf("%d",n);
	}while(*n < 0 || *n > 100);
	for(int i=0;i<*n;i++){
	printf("\n\tNhap sinh vien thu %d",i+1);
	NhapSV(a[i]);
	}
}
void XuatSV(SV &sv)
{
	printf("\n\tHo va ten: %s",sv.ThiSinh);
	printf("\n\tDiem sinh vien: %0.2f",sv.Diem);
	printf("\n\tMa truong: %s",sv.MST);
}
void Xuat_n_SinhVien(SV a[],int n)
{
	int i;
	printf("\n\tDa xuat thong tin sinh vien vao file!");
//	printf("\nThong tin sinh vien tham gia thi UTC2-Techwar:");
//	for (i=0;i<n;i++)
//	{
//		printf("\nSinh vien thu %d",i+1);
//		XuatSV(a[i]);
//	}
FILE *file;
//file = fopen("E:/HOC_KI_II(2021_2022)/KI_THUAT_LAP_TRINH/BaitapDeadline19-4-2022/ON_TAP_Pham_Van_Giang.txt","w"); dia chi tuyet doi
file = fopen("./ON_TAP_Pham_Van_Giang.txt","w"); //dia chi tuong doi
if (file == NULL)
{
	printf("\nerror! loi mo file!");
	exit(1);
}
 for(i=0;i<n;i++)
 {
 	fprintf(file,"So thu tu: %d\n",i+1);
 	fprintf(file,"Ho va ten: %s\n",a[i].ThiSinh);
 	fprintf(file,"Diem sinh vien: %0.2f\n",a[i].Diem);
 	fprintf(file,"Ma truong: %s\n",a[i].MST);
 	fprintf(file,"\n_________________________________________\n");
 }
 fclose(file);
}
void TinhDiemSinhVien(SV a[], int n)
{
	float sum =0;
	int t =0;
	char mst[10];
	printf("\n\tNhap vao ma truong cua sinh vien: ");
    scanf("%s",&mst);
    for(int i=0;i<n;i++)
    {
    	if(strcmp(mst,a[i].MST)==0)
    	{
    		sum = sum + a[i].Diem;
    		t++;
		}
	}
	if(sum == 0){
		printf("\n\tKhong tim thay sinh vien!");
	}else{
		printf("\n\tTong diem: %0.2f",sum);
	    printf("\n\tTrung binh cong so diem cua sinh vien truong do:%0.2f",sum/t);
	}
	
} 
void MENU()
{
	system("cls");
	printf("\n\t1.  NHAP THONG TIN SINH VIEN");
	printf("\n\t2.  XUAT THONG TIN SINH VIEN RA TEP VAN BAN");
	printf("\n\t3.  TINH DIEM CAC SINH VIEN CUNG TRUONG");
	printf("\n\t4.  THOAT CHUONG TRINH");
}
int main()
{
	int n;
	SV a[n];
	int option;

	while(1)
	{
		MENU();
		do
		{
			printf("\n\tMoi ban nhap lua chon: ");
			scanf("%d",&option);
		}while(option <= 0 || option > 4);
		switch(option)
		{
			case 1: 
			Nhap_n_SinhVien(a,&n);
			break;
			case 2: 
			Xuat_n_SinhVien(a,n);
			break;
			case 3: 
			TinhDiemSinhVien(a,n);
			break;
			case 4: 
			return 0;
			break;
		}
		printf("\n");
		system("pause");
	}
	return 0;
}
