#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	float diemTB;
	char ten[255];
}SV;

SV nhap1sv(int i){
	SV dssv;
	printf("Nhap thong tin SV thu %d\n",i+1);
	fflush(stdin);
	printf("Ten sv: ");	gets(dssv.ten);
	printf("Diem: ");	scanf("%f",&dssv.diemTB);
	return dssv;
}

void insv(SV dssv[],int n){
	printf("DANH SACH SINH VIEN\n");
	for(int i=0;i<n;i++){
		printf("%s\t %f\n",dssv[i].ten,dssv[i].diemTB);
	}
}

void trenTB(SV dssv[],int n){
	int cnt=0;
	for(int i=0; i<n; i++){
		if(dssv[i].diemTB > 5.0)
			cnt++;
			
	}
	printf("DANH SACH %d SINH VIEN CO DIEM TREN TB\n",cnt);
	for(int i=0; i<n; i++){
		if(dssv[i].diemTB>5.0)
			printf("%s\t %.2f\n",dssv[i].ten,dssv[i].diemTB);
	}
}
int main(){
	SV *dssv;
	int n, input;
	int m = 0; 
	printf("\n*******CHUONG TRINH NHAP DIEM CHO CAC SINH VIEN******");
	printf("\n-----------------------------------------------------\n");
	printf("Nhap so luong SV: ");	
	scanf("%d",&n);
	dssv = (SV*) malloc(n*sizeof(SV));
	printf("NHAP DIEM TRUNG BINH CHO CAC SINH VIEN\n");
	for (int i = 0; i < n; i++)
		dssv[i] = nhap1sv(i);
	
	bool exit = false;
    while (exit==false){
    	printf("\n-------------------------------------------\n");
    	printf("1. So sv co diem tren TB va thong tin \n");
    	printf("2. Them sv va diem TB cho sv do \n");
    	printf("3. In danh sach sinh vien moi\n");
    	printf("4. Thoat chuong trinh\n");
    	printf("Chon 1 chuc nang --> ");
    	scanf("%d", &input);
		switch(input){
			case 1: 
				trenTB(dssv,(n));
				break;
			case 2:	{
					printf("So sinh vien can them: \n");
					scanf("%d", &m);
					SV *temp_dssv = dssv;
					dssv = (SV*) malloc ((n+m)*sizeof(SV));
					for (int i = 0; i < (n); ++i)
					{
						dssv[i] = temp_dssv[i];
					}
					for (int i = n; i < (m+n); ++i)
					{
						dssv[i] = nhap1sv(i);
					};
					n=n+m;
					free(temp_dssv);
				break;
				}
			case 3: 
				printf("DANH SACH TAT CA SINH VIEN\n");
				insv(dssv,n);
				break;
			case 4:
				{
					exit = true;
					break;
				}
			default:
				{
					printf("Incorrect input\n");
					break;
				}
				
			}
	}
	free(dssv);
}
