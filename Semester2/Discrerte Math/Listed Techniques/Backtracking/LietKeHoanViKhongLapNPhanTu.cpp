#include<bits/stdc++.h>
using namespace std;

void init(int s[], int n);
void out(int s[], int n);
void Try(int i, int b[], int s[], int n);

int main(){
	int n; cin >> n;
	int b[n+1], s[n+1];
	for (int i = 1; i <= n; i++){
		b[i] = 1;
	}
	init(s, n);
	Try(1, b, s, n);
	return 0;
}

void init(int s[], int n){
	for (int i = 1; i <= n; i++) s[i] = i;
}

void out(int s[], int n){
	for (int i = 1; i <= n; i++){
		cout << s[i] << " ";
	}
	cout << endl;
}

void Try(int i, int b[], int s[], int n){
	int j;
	for (j = 1; j <= n; j++){
		if (b[j] == 1){
			s[i] = j;
			b[j] = 0;
			if (i == n) out(s, n);
			else Try(i+1, b, s, n);
			b[j] = 1;
		}
	}
}
