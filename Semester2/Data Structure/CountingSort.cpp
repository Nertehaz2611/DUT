#include<stdio.h>
#include<stdlib.h>

int n = 6;
void countingSort(int a[], int b[], int k){
	int c[k+1] = {0};
	for (int i = 0; i < n; i++){
		c[a[i]]++;
	}
	for (int i = 1; i <= k; i++){
		c[i] += c[i-1];
	}
	for (int j = n-1; j >= 0; j--){
		b[c[a[j]]-1] = a[j];
		c[a[j]]--;
	}
}

int main(){
	int a[n] = {1, 1, 3, 3, 2, 5};
	int b[n];
	countingSort(a, b, 5);
	for (int i = 0; i < n; i++){
		printf("%d ", b[i]);
	}
	return 0;
}
