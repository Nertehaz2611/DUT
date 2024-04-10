#include<bits/stdc++.h>
using namespace std;
int d = 0;
void init(int b[], int n);
void out(int b[], int n);
bool islast(int b[], int n);
void gen(int b[], int n);
void method(int b[], int n);

int main(){
	int n; cin >> n;
	int b[n+1];
	method(b, n);
	return 0;
}

void init(int b[], int n){
	for (int i = 1; i <= n; i++) b[i] = 0;
}
void out(int b[], int n){
	cout << ++d << ":  ";
	for (int i = 1; i <= n; i++) cout << b[i];
	cout << endl;
}
bool islast(int b[], int n){
	for (int i = 1; i <= n; i++){
		if (b[i] == 0) return false;
	}
	return true;
}
void gen(int b[], int n){
	int i = n;
	while (b[i]) i--;
	b[i] = 1;
	for (int j = i+1; j <= n; j++){
		b[j] = 0;
	}
}
void method(int b[], int n){
	init(b, n);
	out(b, n);
	bool stop = islast(b, n);
	while (!stop){
		gen(b, n);
		out(b, n);
		stop = islast(b, n);
	}
}
