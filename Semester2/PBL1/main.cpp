#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <winbgim.h>
#define eps 1e-3

//Ham in mau
void setcolor(int backgound_color, int text_color){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

//Ham gioi thieu
void infor(){
 	int i;
 	setcolor(0,9);
 	printf("\n%9c",201);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c",187);
 	printf("\n        %c %86c",4,4);
 	printf("\n        %c                             DO AN LAP TRINH TINH TOAN                                %c",4,4);
 	printf("\n        %c                   DE TAI: Tim nghiem gan dung bang phuong phap chia doi              %c",4,4);
 	printf("\n        %c %86c",4,4);
 	printf("\n        %c       Sinh vien thuc hien:                       Giao vien huong dan:                %c",4,4);
 	printf("\n        %c           %c Nguyen Thanh Hieu                       %c Phan Thanh Tao                 %c",4,45,45,4);
 	printf("\n        %c           %c Tran Duc Duy  %60c",4,45,4);
 	printf("\n        %c %86c",4,4);
 	printf("\n        %c",200);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c\n",188);
}

//Ham menu yeu cau dau vao
void menuin(float &com){
    setcolor(0,14);
 	printf("\n                                  %c   CHON CACH NHAP DU LIEU   %c\n",16,17);
 	printf("\n                                        Nhap 1: Tu ban phim");
	printf("\n                                        Nhap 2: Tu file");
	printf("\n                                    Nhan phim bat ky de Ket thuc");
	printf("\n                                             -------\n");
	setcolor(0,8);
	printf("\n          Nhap yeu cau: ");
	do{
		scanf("%f", &com);
		if(com != 1 && com != 2) printf("\nMoi ban nhap lai: ");
	}while(com != 1 && com != 2);
}

//Ham menu yeu cau file muon nhap
void menuFILE(float &v){
	setcolor(0,2);
 	printf("\n                                  %c   CHON FILE DE LAY DU LIEU    %c\n",16,17);
 	printf("\n                           Nhan 1 : TEST1                 Nhan 2: TEST2 ");
	printf("\n                           Nhan 3 : TEST3                 Nhan 4: TEST4 ");
	printf("\n                           Nhan 5 : TEST5                 Nhan 6: TEST6 ");
	printf("\n                           Nhan 7 : TEST7                 Nhan 8: TEST8 ");
	printf("\n                           Nhan 9 : TEST9                 Nhan 10: TEST10");
	printf("\n                                             -------\n");
	setcolor(0,8);
	printf("\n          Nhap file test (1-10): ");
	do{
		scanf("%f", &v);
		if(v!=1 && v!=2 && v!=3 && v!=4 && v!=5 && v!=6 && v!=7 && v!=8 && v!=9 && v!=10) printf("\nMoi ban nhap lai so thu tu file: ");
	}while(v!=1 && v!=2 && v!=3 && v!=4 && v!=5 && v!=6 && v!=7 && v!=8 && v!=9 && v!=10);
}

//Ham nhap file da chon
void Nhapfile(float *a, int &n, int v){
	FILE *fi;
    if(v==1)fi=fopen("TEST1.txt","r");
    if(v==2)fi=fopen("TEST2.txt","r");
	if(v==3)fi=fopen("TEST3.txt","r");
	if(v==4)fi=fopen("TEST4.txt","r");
	if(v==5)fi=fopen("TEST5.txt","r");
	if(v==6)fi=fopen("TEST6.txt","r");
	if(v==7)fi=fopen("TEST7.txt","r");
	if(v==8)fi=fopen("TEST8.txt","r");
	if(v==9)fi=fopen("TEST9.txt","r");
	if(v==10)fi=fopen("TEST10.txt","r");
    printf("\nBac phuong trinh: ");
    fscanf(fi,"%d", &n);
    printf("%d", n);
    printf("\nCac he so cua phuong trinh bac %d: ", n);
    for(int i = 0 ; i <= n ; i++){
        fscanf(fi,"%f", a+i);
        if(*(a+i)==(int)(*(a+i))){
            printf("%d ",(int)(*(a+i)));
        }else printf("%f ",*(a+i));
    }
}

//Ham nhap he so tu ban phim
void nhap(float *a, int n)
{
    int i;
    for (i=0;i<=n; ++i) scanf("%f", a+i);
}

//Ham tinh gia tri ham so tai x = x0
float f(float *a, int n, float x0)
{
    float p; int i;
    p = a[0];
    for (i=1; i<=n; i++) p = p*x0 + a[i];
    return p;
}

//Ham xuat da thuc
void XuatDaThuc( float A[],int Bac) {
    printf("\n\nDa thuc vua nhap la: \n\n");
    printf("f(x) = ");
    if(A[0]==1){
        printf("x^%d", Bac);
    }else{
        if(A[0]==(int)A[0]){
            printf("%dx^%d", (int)A[0], Bac);
        }else printf("%fx^%d", A[0], Bac);
    }
    for(int i = 1;i<=Bac;i++){
        if(A[i]==0 || (A[i]==0 && (Bac-i)==0)){
            continue;
        }
        if((Bac-i)==0){
            if(A[i]>0){
                if(A[i]==1){
                    printf("+1");
                }else{
                    if(A[i]==(int)A[i]){
                        printf("+%d", (int)A[i]);
                    }else printf("+%f", A[i]);
                }
            }else if(A[i]<0){
                if(A[i]==-1){
                    printf("-1");
                }else{
                    if(A[i]==(int)A[i]){
                        printf("%d", (int)A[i]);
                    }else printf("%f", A[i]);
                }
            }
        }else if((Bac-i)==1){
            if(A[i]>0){
                if(A[i]==1){
                    printf("+x");
                }else{
                    if(A[i]==(int)A[i]){
                        printf("+%dx", (int)A[i]);
                    }else printf("+%fx", A[i]);
                }
            } else if(A[i]<0){
                if(A[i]==-1){
                    printf("-x");
                }else{
                    if(A[i]==(int)A[i]){
                        printf("%dx", (int)A[i]);
                    }else printf("%fx", A[i]);
                }
            }
        }else{
            if(A[i]>0){
                if(A[i]==1){
                    printf("+x^%d", Bac-i);
                }else{
                    if(A[i]==(int)A[i]){
                        printf("+%dx^%d", (int)A[i], Bac-i);
                    }else{
                        printf("+%fx^%d", A[i], Bac-i);
                    }
                }
            }else if(A[i]<0){
                if(A[i]==-1){
                    printf("-x^%d", Bac-i);
                }else{
                    if(A[i]==(int)A[i]){
                        printf("%dx^%d", (int)A[i], Bac-i);
                    }else{
                        printf("%fx^%d", A[i], Bac-i);
                    }
                }
            }
        }
    }
}

//Ham thuc hien phuong phap chia doi
void solve(float d[], int n, float a, float b){
	float c;
	if (f(d,n,a)*f(d,n,b)<0){
        printf("\na\tb\tc\tf(c)\n");
        do{
            c = (a+b)/2;
            printf("%0.3f\t%0.3f\t%0.3f\t%0.3f\n", a, b, c, f(d, n, c));
            if (f(d,n,b)*f(d,n,c)>0) b=c;
            else a=c;
        }while (fabs(a-b) >= 1e-3 && f(d,n,c)!=0);
        printf("\n\nNghiem phtrinh: %.3f", c);
    } else printf("\n\n(%0.3f, %0.3f) khong phai la khoang nghiem", a, b);
}

int main()
{
    float com; float v;
    float a,b; char tt[1];
    char newP[1];
    int n;
    
    
    float A[101]; 
    
    
    infor(); //Gioi thieu
    do{
        menuin(com); //Menu yeu cau dau vao
        if(com==1){ //Nhap tu ban phim
            printf("\nNhap bac phuong trinh: ");
            
            scanf("%d", &n);
            printf("\nNhap cac he so cua phuong trinh bac %d: ", n);
            nhap(A, n);
        }else if(com == 2){ //Nhap tu file
        	menuFILE(v);
            Nhapfile(A, n,v);
        }else if(com!=1 || com != 2){
        	printf("\nMoi ban nhap lai: ");
		}
        XuatDaThuc(A, n);
        while (1){
        	printf("\n\nNhap khoang nghiem: ");
            scanf("%f%f", &a, &b);
        	solve(A,n,a,b);
            printf("\n\nBan co muon nhap khoang nghiem khac khong (y/n)? ");
            scanf("%s",tt);
            if (tt[0]!='y') break;
        }
        printf("\n\nBan co muon chon yeu cau khac khong (Neu muon nhap lai thi chon c, con khong muon thi nhap phim bat ki)? ");
        scanf("%s", newP);
    }while(newP[0]=='c');
}
