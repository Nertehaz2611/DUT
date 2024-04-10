#include<bits/stdc++.h>
using namespace std;

void init(int a[], int n);
void out(int a[], int n);
bool islast(int a[], int n);
void gen(int a[], int n);
void method(int a[], int n);
int d = 0;
int main(){
	int n; cin >> n;
	int a[n+1];
	method(a, n);
	return 0;
}
void init(int a[], int n){
	for (int i = 1; i <= n; i++){
		a[i] = i;
	}
}
void out(int a[], int n){
	cout << ++d << ": ";
	for (int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
bool islast(int a[], int n){
	int i = 1;
	for (int i = 1; i <= n; i++){
		if (a[i] != n-i+1) return 0;
	}
	return 1;
}
void gen(int a[], int n){
	int i = n-1;
	while (a[i] > a[i+1]){
		i--;
	}
	int k = n;
	while (a[k] < a[i]){
		k--;
	}
	swap(a[i], a[k]);
	int l = i+1, r = n;
	while (l < r){
		swap(a[l], a[r]);
		l++;
		r--;
	}
}
void method(int a[], int n){
	init(a, n);
	out(a, n);
	bool stop = islast(a, n);
	while (!stop){
		gen(a, n);
		out(a, n);
		stop = islast(a, n);
	}
}
