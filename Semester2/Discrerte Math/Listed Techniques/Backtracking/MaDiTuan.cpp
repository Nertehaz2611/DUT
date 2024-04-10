#include<bits/stdc++.h>
using namespace std;

int X[9] = {0, -2,-2,-1,-1, 1, 1, 2, 2};
int Y[9] = {0, -1, 1,-2, 2,-2, 2,-1, 1};
int dem = 0;

void init(int a[][9]);
void out(int a[][9]);
bool check(int a[][9], int x, int y);
void Try(int a[][9], int x, int y);

int main(){
	int a[9][9];
	init(a);
	int x, y;
	cout << "Nhap toa do ban dau: "; cin >> x >> y;
	Try(a, x, y);
	cout << "Khong the di chuyen het ban co";
	return 0;
}

void init(int a[][9]){
	for (int i = 1; i <= 8; i++){
		for (int j = 1; j <= 8; j++) a[i][j] = 0;
	}
}

void out(int a[][9]){
	for (int i = 1; i <= 8; i++){
		for (int j = 1; j <= 8; j++){
			printf("%2d ", a[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}

bool check(int a[][9], int x, int y){
	return (1 <= x && 8 >= x && 1 <= y && 8 >= y && a[x][y] == 0);
}

void Try(int a[][9], int x, int y){
	dem++;
	a[x][y] = dem;
	for (int i = 1; i <= 8; i++){
		if (dem == 64){
			cout << "Cac buoc di la: " << endl;
			out(a);
			exit(0);
		}
		int u = x+X[i];
		int v = y+Y[i];
		if (check(a, u, v)) Try(a, u, v);
	}
	dem--;
	a[x][y] = 0;
}


