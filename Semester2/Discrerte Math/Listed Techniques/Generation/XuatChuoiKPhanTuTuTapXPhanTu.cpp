#include<bits/stdc++.h>
using namespace std;
void init(int a[], int k);
void out(int a[], int k);
bool islast(int a[], int k, int n);
void gen(int a[], int k, int x);
void method(int a[], int k, int x);
int d = 1;
int main(){
	int x; cin >> x;
	int k; cin >> k;
	int a[k+1];
	method(a, k, x);
	return 0;
}
void init(int a[], int k){
	for (int i = 1; i <= k; i++) a[i] = i;
}
void out(int a[], int k){
	cout << d++ << ":  ";
	for (int i = 1; i <= k; i++) cout << a[i] << " ";
	cout << endl;
}
bool islast(int a[], int k, int x){
	for (int i = k; i >= 1; i--){
		if (a[i] != x-k+i) return 0;
	}
	return 1;
}
void gen(int a[], int k, int x){
	int i = k;
	while (a[i] == x-k+i) i--;
	a[i]++;
	for (int j = i+1; j <= k; j++) a[j] = a[i]+j-i;
}
void method(int a[], int k, int x){
	init(a, k);
	out(a, k);
	bool stop = islast(a, k, x);
	while (stop == 0){
		gen(a, k, x);
		out(a, k);
		stop = islast(a, k, x);
	}
}
