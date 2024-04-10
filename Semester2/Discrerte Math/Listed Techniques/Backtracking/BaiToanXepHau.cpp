#include<bits/stdc++.h>
using namespace std;

void out(int x[], int n);
void Try(int i, int x[], int a[], int b[], int c[], int n);

int main(){
	int n; cin >> n;
	int x[n+1], a[n+1], b[101], c[101];
	for (int i = 1; i <= n; i++){
		a[i] = 1;
	}
	for (int i = 2; i <= 16; i++){
		b[i] = 1;
	}
	for (int i = 1-n; i <= n-1; i++){
		c[i] = 1;
	}
	Try(1, x, a, b, c, n);
	return 0;
}

void out(int x[], int n){
	for (int i = 1; i <= n; i++){
		cout << x[i] << " ";
	}
	cout << endl;
}

void Try(int i, int x[], int a[], int b[], int c[], int n){
	for (int j = 1; j <= n; j++){
		if (a[j] == 1 && b[i+j] == 1 && c[i-j] == 1){
			x[i] = j;
			a[j] = 0;
			b[i+j] = 0;
			c[i-j] = 0;
			if (i == n) out(x, n);
			else Try(i+1, x, a, b, c, n);
			a[j] = 1;
			b[i+j] = 1;
			c[i-j] = 1;
		}
	}
}
