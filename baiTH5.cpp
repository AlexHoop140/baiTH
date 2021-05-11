#include <stdio.h>
#include <malloc.h>
#include <string.h>


typedef struct 
{	
	char mssv[9];
	char hoten[30];
	char lop[7];
	int tctl;
	float tbtl;
	int hang;
	char xl[10];
} sinhvien;

sinhvien nhapSV(int i){
    sinhvien sv;
    printf("Nhap thong tin sinh vien thu: %d\n",i+1);
    fflush(stdin);
    printf("Nhap ho va ten sinh vien: ");    
    gets(sv.hoten);
    fflush(stdin);
    printf("Nhap ma so sinh vien: ");    
    gets(sv.mssv);
    fflush(stdin);
    printf("Nhap ten lop: ");    
    gets(sv.lop);
    printf("Nhap so TC tich luy: ");
    scanf("%d",&sv.tctl);
    printf("Nhap diem trung binh: ");
    scanf("%f",&sv.tbtl);
    return sv;
}

void InTTsv(sinhvien h1, int i){

	printf("-------- THONG TIN SINH VIEN THU %d---------\n", i+1);
	printf("MSSV: "); puts(h1.mssv);
	printf("Ho va Ten: "); puts(h1.hoten); 
	printf("Lop: "); puts(h1.lop);
	printf("Tin chi tich luy: %d\n", h1.tctl);
	printf("Diem TBTL: %.2f\n", h1.tbtl);
	printf("Hang: %d\n", h1.hang);
	printf("Xep loai: "); puts(h1.xl);
}

void swap(sinhvien *x, sinhvien *y){
	sinhvien tmp = *x;
	*x = *y;
	*y = tmp;
}
//sap xep theo thu tu lon den be
void sapxep(sinhvien h1[], int n){ 
	for (int i = 0; i <= n-2; i++){
		for (int j = n - 1; j >= i+1; j--){
			if (((h1[j].tbtl > h1[j-1].tbtl))){
				swap(&h1[j], &h1[j-1]);
			}
		}
	}
}

void xephang(sinhvien h1[], int n){
	h1[0].hang = 1;
	for (int i = 1; i < n; i++){
		if (h1[i].tbtl == h1[i-1].tbtl)
			h1[i].hang = h1[i-1].hang;
		else
			h1[i].hang = i + 1;
	}
}
void diemTBLN(sinhvien h1[], int n){
	printf("\n--- SINH VIEN CO DIEM SO CAO NHAT ---\n");
	InTTsv(h1[0], 0);
	for (int i = 1; i < n; i++){
		if (h1[i].tbtl == h1[i-1].tbtl)
			InTTsv(h1[i], i);
		else break;
		}
}

void diemTBNN(sinhvien h1[], int n){
	printf("\n--- SINH VIEN CO DIEM SO THAP NHAT ---\n");
	InTTsv(h1[n-1], 0);
	for (int i = n-2; i > 0; i--){
		if (h1[i].tbtl == h1[i+1].tbtl)
			InTTsv(h1[i], i);
		else break;
		}
}

void xeploai(sinhvien sv[], int n) {
	for(int i=0;i<n;i++){
		if(sv[i].tbtl < 5.0)
			strcpy(sv[i].xl, "Yeu"); 
		else if(sv[i].tbtl < 7.0)
			strcpy(sv[i].xl, "Trung binh");
		else if(sv[i].tbtl < 9.0)
			strcpy(sv[i].xl, "Kha");
	 	else if(sv[i].tbtl <= 10)
			strcpy(sv[i].xl, "Gioi");
	}
}

int main(){
	int n, m = 0, input, k;
	sinhvien *dssv;
	printf("\n*******CHUONG TRINH QUAN LY SINH VIEN******");
	printf("\n-----------------------------------------------------\n");
	printf("Nhap vao so luong sinh vien\n");
	scanf("%d", &n);	
	dssv = (sinhvien*) malloc (n*sizeof(sinhvien));
	printf("Nhap Thong Tin Cho Cac Sinh Vien\n");
	for(int i=0; i < n; i++)
		dssv[i] = nhapSV(i);

	bool exit = false;
	while(exit == false){
		printf("\n-------------------------------------------\n");

    	printf("1. Sinh vien co so diem cao nhat va thap nhat \n");
    	printf("2. Them sinh vien moi \n");
    	printf("3. In danh sach sinh vien va xep hang\n");
    	printf("4. Thoat chuong trinh\n");
    	printf("Chon 1 lua chon nao --> ");
    	scanf("%d", &input);
    	switch (input){
    		case 1:
    			sapxep(dssv, (n));
				xephang(dssv, (n));
				xeploai(dssv, (n));
				diemTBLN(dssv, (n));
				diemTBNN(dssv, (n));
    			break;
    		case 2:
	    		{
					printf("So sinh vien can them: ");
					scanf("%d", &m);
					sinhvien *temp_dssv = dssv;
					dssv = (sinhvien*) malloc ((n+m)*sizeof(sinhvien));
					for (int i = 0; i < (n); ++i)
					{
						dssv[i] = temp_dssv[i];
					}
					for (int i = n; i < (n+m); ++i)
					{
						dssv[i] = nhapSV(i);
					};

					free(temp_dssv);
					n+=m; // n = n + m;
					break;
				}
			case 3:
				{
					sapxep(dssv, (n));
					xephang(dssv, (n));
					xeploai(dssv, (n));
					printf("---------Danh sach sinh vien:---------\n");
		        	for(int i = 0; i< (n); i++)
		            	InTTsv(dssv[i], i);
		        	break;
	        	}
			case 4:
				exit = true;
		        break;	
	        default:
	        	printf("Nhap sai roi! Moi nhap lai\n");
	        	break;
    	};
    	//n = n + m;
	}

	free(dssv);
	return 0;
}
