#include<bits/stc++.h>
using namespace std;

//Nhap cau hinh ban dau
void init(); 

//Xuat cau hinh ban dau
void out();

//Kiem tra co phai cau hinh cuoi cung khong
bool islast(int a[], int k, int n);

//Thuat toan thay doi cau hinh
void gen();

//Phuong phap sinh
void method(int a[], int k, int x){
	init();
	out();
	bool stop = islast();
	//Neu cau hinh hien tai khong phai la cau hinh cuoi cung thi tiep tuc thay doi cau hinh
	while (stop == 0){
		gen();
		out();
		stop = islast();
	}
}

int main(){
	return 0;
}
