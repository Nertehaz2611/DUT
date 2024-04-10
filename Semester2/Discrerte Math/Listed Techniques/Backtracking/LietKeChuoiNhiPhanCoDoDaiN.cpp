#include<bits/stdc++.h>
using namespace std;

void out(int b[], int n);
void Try(int i, int b[], int n);

int main(){
	int n; cin >> n;
	int b[n+1];
	Try(1, b, n);
	return 0;
}

void out(int b[], int n){
	for (int i = 1; i <= n; i++){
		cout << b[i];
	}
	cout << endl;
}

void Try(int i, int b[], int n){
	int j;
	for (j = 0; j <= 1; j++){
		b[i] = j;
		if (i == n) out(b, n);
		else Try(i+1, b, n);
	}
}
