#include <stdio.h>
#include <string.h>

typedef struct{
    float diemTB;
    char tenSV[50];
}SINHVIEN;

SINHVIEN nhapSV(int i){
    SINHVIEN sv;
    printf("Nhap thong tin sinh vien thu: %d\n",i+1);
    fflush(stdin);
    printf("Nhap ho va ten sinh vien: ");    
    gets(sv.tenSV);
    printf("Nhap diem trung binh: ");
    scanf("%f",&sv.diemTB);
    return sv;
}

void inSV(SINHVIEN sv, int i){
    printf("\nThong tin sinh vien thu: %d\n",i+1);
    printf("Ho va Ten: ");    puts(sv.tenSV);
    printf("Diem Trung Binh: %.2f",sv.diemTB);
    printf("\n");
}

void trenTB(SINHVIEN sv[], int n){
    int cnt = 0;
    for (int i = 0; i < n; ++i){
        if (sv[i].diemTB > 5.0)
            cnt++;
    }
    printf("SO SINH VIEN TREN TRUNG BINH: %d\n", cnt);
    printf(" -- DANH SACH SINH VIEN TREN TRUNG BINH -- \n");
    for (int j = 0; j < n; ++j)
    {
        if (sv[j].diemTB > 5.0)
            inSV(sv[j], j);
    }
}

int main(){

	SINHVIEN dssv[10000];
	int n, m, input;
  
    bool exit = false;
    while (!exit){
    	printf("-------------------------------------------\n");
    	printf("1. Nhap diem TB cho cac SV\n");
    	printf("2. So sv co diem tren TB va thong tin \n");
    	printf("3. Them sv va diem TB cho sv do \n");
    	printf("4. In danh sach sinh vien moi\n");
    	printf("5. Thoat chuong trinh\n");
    	printf("Chon 1 lua chon nao --> ");
    	scanf("%d", &input);
    	switch (input){
	    	case 1:
	    		printf("Nhap so sinh vien can nhap thong tin: ");    
    			scanf("%d",&n);
	    		for(int i=0; i < n; i++)
	        		dssv[i]=nhapSV(i);
	        	break;
	        case 2:
	        	trenTB(dssv,(n+m));
	        	break;
	        case 3: 
	        	printf("\nNhap so luong sv muon them vao: ");
	    		scanf("%d",&m);
	    		for(int i = n; i < (m + n); i++)
	        		dssv[i]=nhapSV(i);
	        	break;
	        case 4:
	        	printf("---------Danh sach sinh vien:---------\n");
	            for(int i = 0; i< (m + n); i++)
	                inSV(dssv[i],i);
	        	break;
	        case 5:
	        	exit = true;
	        	break;
	        default:
	        	printf("Incorrect input\n");
	        	break;
	    }
	}
    // printf("\n");
    // printf("---------Danh sach %d sinh vien:---------\n",n);
    // for(int i=0;i<n;i++)
    //     inSV(dssv[i],i);


    }